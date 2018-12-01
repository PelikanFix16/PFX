#include "Texture.h"

Texture::Texture(std::string texturePath,unsigned int texNum) {

    this->_textureActive = GL_TEXTURE0+texNum;

    if(GL_MAX_TEXTURE_UNITS < this->_textureActive) {
        throw "To many textures";
    }

    glGenTextures(1,&(this->_texture));
    glBindTexture(GL_TEXTURE_2D,this->_texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    int width,height,nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texturePath.c_str(),&width,&height,&nrChannels,0);
    if(data) {
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        throw "Can't load texture from selected file path";
    }
    stbi_image_free(data);

}

void Texture::activeTexture() {

    glActiveTexture(this->_textureActive);
    glBindTexture(GL_TEXTURE_2D,this->_texture);
}
