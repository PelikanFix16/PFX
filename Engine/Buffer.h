#pragma once
#include <GL/glew.h>
#include <iostream>
#include <iterator>
#include <vector>
class Buffer {

    public:
        Buffer();
        ~Buffer();
        void bind();
        void unbind();
        void LoadVert(float* vert,size_t size);
        void LoadIndices(unsigned int* indices,size_t size);
        void AddAttrib(unsigned int attrib,unsigned int sizeAttrib,unsigned int jumpAttrib,unsigned int start);
        void drawIndices();
        void drawVert();


    private:
        unsigned int _VBO;
        unsigned int _EBO;
        unsigned int _VAO;
        unsigned int _vertSize;
        unsigned int _indicesSize;
    private:
        void bindVBO();
        void unbindVBO();




};
