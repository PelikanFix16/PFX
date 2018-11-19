#pragma once
#include <GL/glew.h>
#include <iostream>
#include <iterator>
class Buffer {

    public:
        Buffer();
        ~Buffer();
        void bind();
        void LoadVert(float* vert,size_t size,int jump,);

    private:
        unsigned int _VBO;
        unsigned int _EBO;
        unsigned int _VAO;
        unsigned int _sizeVerticies;
        unsigned int _sizeAttrib;
        unsigned int _jumpAttrib;
        unsigned int _startAttrib;



};
