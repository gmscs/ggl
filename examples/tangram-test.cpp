#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../ggl.hpp"

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
"uniform mat4 matrix;"
"out vec3 color;"
"void main() {"
"  gl_Position = matrix * vec4(pointVec, 1.0);"
"  color = colorVec;"
"}";
//Using layout(location...) is not strictly necessary for this but
//I used it for learning purposes and it is generally 
//considered good pratice to specify the location even if obvious.

const float triangle_points[] = {
    0.0f, 0.0f, 0.0f,
    0.1f, -0.1f, 0.0f,
    -0.1f, -0.1f, 0.0f
};

const float square_points[] = {
    -0.1f, 0.1f, 0.0f,  //triangle 1
    0.1f, -0.1f, 0.0f,
    -0.1f, -0.1f, 0.0f,
    0.1f, -0.1f, 0.0f,  //triangle 2
    -0.1f, 0.1f, 0.0f,
    0.1f, 0.1f, 0.0f
};

const float parallelogram_points[] = {
    0.0f, 0.0f, 0.0f,   //triangle 1
    0.1f, -0.1f, 0.0f,
    -0.1f, -0.1f, 0.0f,
    0.1f, -0.1f, 0.0f,  //triangle 2
    0.0f, 0.0f, 0.0f,
    0.2f, 0.0f, 0.0f
};

const float white_color[] = {
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f
};

const float light_grey_color[] = {
    0.9294f, 0.9294f, 0.9294f,
    0.9294f, 0.9294f, 0.9294f,
    0.9294f, 0.9294f, 0.9294f
};

const float grey_color[] = {
    0.659f, 0.659f, 0.659f,
    0.659f, 0.659f, 0.659f,
    0.659f, 0.659f, 0.659f
};

const float black_color[] = {
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f
};

const float pink_color[] = {
    1.0f, 0.824f, 0.866f,
    1.0f, 0.824f, 0.866f,
    1.0f, 0.824f, 0.866f,
    1.0f, 0.824f, 0.866f,
    1.0f, 0.824f, 0.866f,
    1.0f, 0.824f, 0.866f
};

const float brown_color[] = {
    0.686f, 0.439f, 0.0f,
    0.686f, 0.439f, 0.0f,
    0.686f, 0.439f, 0.0f
};

const float dark_brown_color[] = {
    0.373f, 0.184f, 0.0f,
    0.373f, 0.184f, 0.0f,
    0.373f, 0.184f, 0.0f
};

int main()
{
    ggl::matrix4<float> matrix(0.0);

    if(!glfwInit()) {
        std::cerr << "GLFW failed to initialize." << std::endl; 
        return 1;
    }
    GLFWwindow* window = glfwCreateWindow(600, 600, "Leia Tangram", NULL, NULL);
    if(!window) {
        std::cerr << "Window failed to initialize." << std::endl; 
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum glew_result = glewInit();
    if(glew_result != GLEW_OK){
        std::cerr << "GLEW failed to initialize." << std::endl;
        return 1;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);     //My points are given clockwise

    //VBOs
    GLuint triangle_vbo = 0;
    glGenBuffers(1, &triangle_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), triangle_points, GL_STATIC_DRAW);

    GLuint white_color_vbo = 0;
    glGenBuffers(1, &white_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, white_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), white_color, GL_STATIC_DRAW);
    
    GLuint light_grey_color_vbo = 0;
    glGenBuffers(1, &light_grey_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, light_grey_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), light_grey_color, GL_STATIC_DRAW);
    
    GLuint grey_color_vbo = 0;
    glGenBuffers(1, &grey_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, grey_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), grey_color, GL_STATIC_DRAW);
    
    GLuint black_color_vbo = 0;
    glGenBuffers(1, &black_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, black_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), black_color, GL_STATIC_DRAW);

    GLuint pink_color_vbo = 0;
    glGenBuffers(1, &pink_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, pink_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), pink_color, GL_STATIC_DRAW);
    
    GLuint brown_color_vbo = 0;
    glGenBuffers(1, &brown_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, brown_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), brown_color, GL_STATIC_DRAW);
    
    GLuint dark_brown_color_vbo = 0;
    glGenBuffers(1, &dark_brown_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, dark_brown_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), dark_brown_color, GL_STATIC_DRAW);

    GLuint square_vbo = 0;
    glGenBuffers(1, &square_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, square_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), square_points, GL_STATIC_DRAW);
    
    GLuint parallelogram_vbo = 0;
    glGenBuffers(1, &parallelogram_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, parallelogram_vbo);
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), parallelogram_points, GL_STATIC_DRAW);

    //VAOs
    GLuint chest_vao = 0;
    glGenVertexArrays(1, &chest_vao);
    glBindVertexArray(chest_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, white_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint hair_left_vao = 0;
    glGenVertexArrays(1, &hair_left_vao);
    glBindVertexArray(hair_left_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, dark_brown_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    GLuint hair_right_vao = 0;
    glGenVertexArrays(1, &hair_right_vao);
    glBindVertexArray(hair_right_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, brown_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    GLuint legs_vao = 0;
    glGenVertexArrays(1, &legs_vao);
    glBindVertexArray(legs_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, light_grey_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint dress_vao = 0;
    glGenVertexArrays(1, &dress_vao);
    glBindVertexArray(dress_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, grey_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint square_vao = 0;
    glGenVertexArrays(1, &square_vao);
    glBindVertexArray(square_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, square_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, pink_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    GLuint parallelogram_vao = 0;
    glGenVertexArrays(1, &parallelogram_vao);
    glBindVertexArray(parallelogram_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, parallelogram_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, black_color_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // SHADERS
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

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.65882f, 0.68627f, 1.0f, 1.0f);
        glUseProgram(shader);

        //// CHEST
        matrix = ggl::scale(ggl::matrix4<float>(1.0), ggl::vector3<float>(2.0, 2.0, 0.0));
        matrix = ggl::rotate_z(matrix, ggl::degrees_to_radians(-90));
        matrix = ggl::translate(matrix, ggl::vector3<float>(-0.18, 0.1, 1.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(chest_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        //// HAIR LEFT
        matrix = ggl::rotate_z(ggl::matrix4<float>(1.0), ggl::degrees_to_radians(-90));
        matrix = ggl::translate(matrix, ggl::vector3<float>(-0.695, -0.142, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(hair_left_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //// HAIR RIGHT
        matrix = ggl::rotate_z(ggl::matrix4<float>(1.0), ggl::degrees_to_radians(90.0f));
        matrix = ggl::translate(matrix, ggl::vector3<float>(0.695, -0.142, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(hair_right_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /// LEGS
        matrix = ggl::scale(ggl::matrix4<float>(1.0), ggl::vector3<float>(2.0, 2.0, 0.0));
        matrix = ggl::rotate_z(matrix, ggl::degrees_to_radians(90));
        matrix = ggl::translate(matrix, ggl::vector3<float>(0.041, 0.04, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(legs_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        /// DRESS
        matrix = ggl::scale(ggl::matrix4<float>(1.0), ggl::vector3<float>(1.5, 1.5, 0.0));
        matrix = ggl::translate(matrix, ggl::vector3<float>(-0.02, 0.022, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(dress_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //// FACE
        matrix = ggl::rotate_z(ggl::matrix4<float>(1.0), ggl::degrees_to_radians(45));
        matrix = ggl::translate(matrix, ggl::vector3<float>(0.492, 0.492, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(square_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        //// GUN
        matrix = ggl::translate(ggl::matrix4<float>(1.0), ggl::vector3<float>(0.263, 0.5, 0.0));
        glUniformMatrix4fv(glGetUniformLocation(shader, "matrix"), 1, GL_TRUE, ggl::pointer(matrix));
        glBindVertexArray(parallelogram_vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    //Delete references to objects
    glBindVertexArray(chest_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &chest_vao);

    glBindVertexArray(hair_left_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &hair_left_vao);

    glBindVertexArray(hair_right_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &hair_right_vao);

    glBindVertexArray(legs_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &legs_vao);

    glBindVertexArray(dress_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &dress_vao);

    glBindVertexArray(square_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &square_vao);

    glBindVertexArray(parallelogram_vao);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDeleteVertexArrays(1, &parallelogram_vao);

    /*
     * Delete objects after deleting references to avoid segfaults or out-of-memory problems
     * Should be deleted when no longer in use at all.
     * In our case - on program termination.
    */
    glDeleteBuffers(1, &triangle_vbo);
    glDeleteBuffers(1, &white_color_vbo);
    glDeleteBuffers(1, &light_grey_color_vbo);
    glDeleteBuffers(1, &grey_color_vbo);
    glDeleteBuffers(1, &black_color_vbo);
    glDeleteBuffers(1, &pink_color_vbo);
    glDeleteBuffers(1, &brown_color_vbo);
    glDeleteBuffers(1, &dark_brown_color_vbo);
    glDeleteBuffers(1, &square_vbo);
    glDeleteBuffers(1, &parallelogram_vbo);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
