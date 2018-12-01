#pragma once
#include <iostream>
#include "stb_image.h"
#include <GL/glew.h>
class Texture {

    private:

        GLenum _textureActive;
        unsigned int _texture;


    public:
        
        Texture(std::string texturePath,unsigned int texNum);
        void activeTexture();



};
