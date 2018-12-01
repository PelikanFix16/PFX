#include "Shader.h"

void Shader::loadShader(std::string src,ShaderType type) {

    std::string content;
    std::ifstream fileStream(src,std::ios::in);
    if(!fileStream.is_open()){
        std::cerr << "Could not read file" << src << std::endl;
    }
    std::string line = "";
    while(!fileStream.eof()){
        std::getline(fileStream,line);
        content.append(line+"\n");

    }
    fileStream.close();
   
    std::pair<Shader::ShaderType,std::string> tempPair;
    tempPair.first = type;
    tempPair.second = content;
    
    _shaders.push_back(tempPair);


}




Shader::Shader() {

    this->_ID = glCreateProgram(); 

}

void Shader::compileShader() {

    std::vector<unsigned int> tempShader;

    for(std::vector<std::pair<ShaderType,std::string> >::iterator it = this->_shaders.begin();it != this->_shaders.end();it++){

        const char* shaderCode = it->second.c_str();
        unsigned int shader;
        switch(it->first) {
            case vertexShader:
                shader = this->compileShaderHelp(GL_VERTEX_SHADER,"VERTEX",shaderCode);
                break;
            case fragmentShader:
                shader = this->compileShaderHelp(GL_FRAGMENT_SHADER,"FRAGMENT",shaderCode);
                break;
        }

        glAttachShader(this->_ID,shader);
        tempShader.push_back(shader);

    }
    glLinkProgram(this->_ID);
    this->compileErrors(this->_ID,"PROGRAM");
    for(std::vector<unsigned int>::iterator it = tempShader.begin();it != tempShader.end();it++){

        glDeleteShader(*it);
    }


}

unsigned int Shader::compileShaderHelp(GLenum shaderType,std::string type,const char* source) {

    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader,1,&source,NULL);
    glCompileShader(shader);
    this->compileErrors(shader,type);
    return shader;


}

void Shader::compileErrors(GLuint shader,std::string type) {
    

 GLint success;
        GLchar infoLog[1024];
        if(type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }

}

void Shader::use() {

    glUseProgram(this->_ID);

}

void Shader::setUniform4F(std::string name,float r,float g,float b,float a) {

    glUniform4f(glGetUniformLocation(this->_ID,name.c_str()),r,g,b,a);

}

void Shader::setUniform1i(std::string name,int value) {

    glUniform1i(glGetUniformLocation(this->_ID,name.c_str()),value);

}
