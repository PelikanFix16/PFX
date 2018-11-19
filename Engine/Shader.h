#pragma once
#include <GL/glew.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>



class Shader {

    public:

        enum ShaderType {
                    vertexShader,
                    fragmentShader
        };

    private:

        unsigned int _ID;
        std::vector<std::pair<ShaderType,std::string> > _shaders;
        

    public:
        Shader();
        void loadShader(std::string src,ShaderType type);
        void use();
        void compileShader();
    private:
        void compileErrors(GLuint shader,std::string type);
        unsigned int compileShaderHelp(GLenum shaderType,std::string type,const char* source);


};
