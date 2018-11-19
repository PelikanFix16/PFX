#include "Buffer.h"

Buffer::Buffer() {

    glGenVertexArrays(1,&(this->_VAO));
    glGenBuffers(1,&(this->_VBO));
    glGenBuffers(1,&(this->_EBO));



}
Buffer::~Buffer() {

    glDeleteBuffers(1,&(this->_VAO));

}

void Buffer::bind() {

    glBindVertexArray(this->_VAO);
}

