#include "ggl.hpp"

//TODO: Currently dependent on stbi 

GLuint load_cube_tex(const char* dir, int channels) {
	int width;
	int height;
	int comp;
	char* img;
	unsigned char* tex_data;
	GLuint texture;
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	img = (char*)"right.jpg"; 
	char* right = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(right, dir);
	strcat(right, img);
	tex_data = stbi_load(right, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load right texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(right);
	
	img = (char*)"left.jpg"; 
	char* left = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(left, dir);
	strcat(left, img);
	tex_data = stbi_load(left, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load left texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(left);

	img = (char*)"top.jpg"; 
	char* top = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(top, dir);
	strcat(top, img);
	tex_data = stbi_load(top, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load top texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(top);
	
	img = (char*)"bottom.jpg"; 
	char* bottom = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(bottom, dir);
	strcat(bottom, img);
	tex_data = stbi_load(bottom, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load bottom texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(bottom);
	
	img = (char*)"front.jpg"; 
	char* front = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(front, dir);
	strcat(front, img);
	tex_data = stbi_load(front, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load front texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(front);
	
	img = (char*)"back.jpg"; 
	char* back = (char*)malloc((strlen(dir) + strlen(img) + 1) *  sizeof(char));
	strcpy(back, dir);
	strcat(back, img);
	tex_data = stbi_load(back, &width, &height, &comp, channels);
	if(!tex_data) {
		std::cerr << "Failed to load back texture.\n";
		stbi_image_free(tex_data);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_data);
	stbi_image_free(tex_data);
	free(back);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	return texture;
}