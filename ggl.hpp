#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../stb/stb_image.h"
#include "../stb/stb_image_resize.h"
#include "../stb/stb_image_write.h"

#include "vector.cpp"
#include "math.cpp"

namespace ggl {

}//ggl