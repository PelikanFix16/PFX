#include "Buffer.h"

Buffer::Buffer() {

    glGenVertexArrays(1,&(this->_VAO));
    glGenBuffers(1,&(this->_VBO));
    glGenBuffers(1,&(this->_EBO));



}
Buffer::~Buffer() {

    glDeleteBuffers(1,&(this->_VBO));
    glDeleteBuffers(1,&(this->_EBO));
    glDeleteVertexArrays(1,&(this->_VAO));

}

void Buffer::bind() {
    
    glBindVertexArray(this->_VAO);

}


void Buffer::LoadVert(float* vert,size_t size) {

    this->bind();
    this->bindVBO();
    glBufferData(GL_ARRAY_BUFFER,size,vert,GL_STATIC_DRAW);
    this->unbindVBO();
    this->unbind();
    this->_vertSize = size;
}

void Buffer::drawVert() {
    this->bind();
    glDrawArrays(GL_TRIANGLES,0,this->_vertSize);
    this->unbind();
}
void Buffer::drawIndices() {
    this->bind();

    glDrawElements(GL_TRIANGLES,this->_indicesSize,GL_UNSIGNED_INT,0);

    this->unbind();
}

void Buffer::AddAttrib(unsigned int attrib,unsigned int sizeAttrib,unsigned int jumpAttrib,unsigned int start) {

    this->bind();
    this->bindVBO();
    glVertexAttribPointer(attrib,sizeAttrib,GL_FLOAT,GL_FALSE,jumpAttrib*sizeof(float),(void*)start);
    glEnableVertexAttribArray(attrib);
    this->unbindVBO();
    this->unbind();


}

void Buffer::unbind() {

    glBindVertexArray(0);
}

void Buffer::LoadIndices(unsigned int* indices,size_t size) {

    this->bind();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,indices,GL_STATIC_DRAW);
    this->unbind();    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    this->_indicesSize = size;
}

void Buffer::bindVBO() {
    
    glBindBuffer(GL_ARRAY_BUFFER,this->_VBO);
    

}

void Buffer::unbindVBO() {

    glBindBuffer(GL_ARRAY_BUFFER,0);

}





