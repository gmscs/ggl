#include "../ggl/ggl.hpp"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const char* fragment_shader =
"#version 330 core\n"
"in vec3 color;"
"out vec4 fcolor;"
"void main() {"
"  fcolor = vec4(color, 1.0);"
"}";

const char* vertex_shader = 
"#version 330 core\n"
"layout(location = 0) in vec3 pointVec;"
"layout(location = 1) in vec3 colorVec;"
""
"uniform mat4 view;"
"uniform mat4 projection;"
"out vec3 color"
""
"void main() {"
"   gl_Position = projection * view * vec4(pointVec, 1.0);"
"   color = colorVec;"
"}";

int main() {
    if(!glfwInit()) {
		std::cerr << "glfwInit failed." << std::endl;
		return 1;
	}

	int win_width = 800;
	int win_height = 600;
	
	GLFWwindow* window = glfwCreateWindow(win_width, win_height, "Cloth", NULL, NULL);
	if(window == NULL) {
		std::cerr << "Window creation failed." << std::endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if(glewInit() != GLEW_OK) {
		std::cerr << "glewInit failed." << std::endl;
		return 1;
	}

    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    std::vector<ggl::particle<float>> particles;
    std::vector<ggl::spring<float>> springs;
    ggl::vector3<float> gravity(0.0f, -9.81f, 0.0f);
    ggl::vector3<float> wind(9.0f, 0.0f, 0.0f);
    int grid_width = 8;
    int grid_height = 8;
    float spacing = 0.05f;
    float stiffness = 1500.0f;
    float mass = 0.2f;
    float delta_time = 0.01f;
    float energy_loss = 0.98f;
    
    float potentialEnergy = 0.0f;
    float kineticEnergy = 0.0f;
    float total_energy = 0.0f;

    for(int i = 0; i < grid_height; ++i) {
        for(int j = 0; j < grid_width; ++j) {
            ggl::particle<float> p(ggl::vector3<float>(j * spacing, i * spacing, 0.0f), 
                                    ggl::vector3<float>(0.0f, 0.0f, 0.0f), 
                                    ggl::vector3<float>(0.0f, 0.0f, 0.0f), 
                                    mass, (j == 0));
            particles.push_back(p);
        }
    }

    for(int i = 0; i < grid_height; ++i) {
        for(int j = 0; j < grid_width; ++j) {
            int index = i * grid_width + j;
            if(j < grid_width - 1) {
                ggl::spring<float> s(index, index + 1, spacing, stiffness);
                springs.push_back(s);
            }
            if(i < grid_height - 1) {
                ggl::spring<float> s(index, index + grid_width, spacing, stiffness);
                springs.push_back(s);
            }
        }
    }

    ggl::matrix4 view = ggl::get_view_matrix(ggl::vector3<float>(0.0f, 0.0f, 5.0f),
                                                    ggl::vector3<float>(0.0f, 0.0f, 0.0f),
                                                    ggl::vector3<float>(0.0f, 1.0f, 0.0f));
    ggl::matrix4 projection = ggl::get_projection_matrix(ggl::degrees_to_radians(45.0f),
                                                        800.0f / 600.0f, 0.1f, 100.0f);

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    GLuint shader = glCreateProgram();
    glAttachShader(shader, vs);
    glAttachShader(shader, fs);
    glLinkProgram(shader);

    int wind_str = 0;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.65882f, 0.68627f, 1.0f, 1.0f);
        glUseProgram(shader);

        for(auto& particle : particles) {
            if(!particle.is_fixed) {
                if(wind[0] >= 9) wind_str = -1;
                if(wind[0] <= 1) wind_str = 1;
                wind[0] += delta_time * wind_str;
                particle.force = gravity * particle.mass + wind;
            }
        }

        for(const auto& spring : springs) {
            ggl::vector3 force = spring_force(spring, particles[spring.id], particles[spring.id_next]);
            if(!particles[spring.id].is_fixed) {
                particles[spring.id].force += force;
            }
            if(!particles[spring.id_next].is_fixed) {
                particles[spring.id_next].force -= force;
            }
        }

        for(auto& particle : particles) {
            particle = ggl::verlet_int(particle, delta_time, energy_loss);
        }

        glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, ggl::pointer(view));
        glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, ggl::pointer(projection));

        glBegin(GL_LINES);
        for(const auto& spring : springs) {
            const ggl::particle<float>& particle1 = particles[spring.id];
            const ggl::particle<float>& particle2 = particles[spring.id_next];
            glVertex3fv(ggl::pointer(particle1.position));
            glVertex3fv(ggl::pointer(particle2.position));
        }
        glEnd();

        glPointSize(5.0f);
        glBegin(GL_POINTS);
        for (const auto& particle : particles) {
            glVertex3fv(ggl::pointer(particle.position));
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
