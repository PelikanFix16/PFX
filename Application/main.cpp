#include <iostream>
#include "../Engine/PFXInit.h"
#include "../Engine/PFXController.h"
#include "../Engine/Shader.h"
#include "../Engine/Buffer.h"
int main(int argc,char* argv[]) {


    PFXInit* pfx = new PFXInit("PFX ENGINE",800,600);
    pfx->Set();

    PFXController* controller = new PFXController(pfx->getWindow());
    
    Shader* shader = new Shader();
    shader->loadShader("./Engine/ShadersSrc/shader.vs",Shader::ShaderType::vertexShader);
    shader->loadShader("./Engine/ShadersSrc/shader.fs",Shader::ShaderType::fragmentShader);
    shader->compileShader();

    float vertices[5] = {0.5f,0.1f,-0.4f,0.23f,0.32f};
    Buffer* buf = new Buffer();




    while(!pfx->isClosedWindow()) {

        if(controller->processInput(256))
           pfx->closeWindow();
       
    
        pfx->clearBuffer(0.4f,0.2f,0.1f,1.0f);

        shader->use();


        pfx->swapBuffer();
        controller->poolEvents();


   }

    delete pfx;
    delete buf;

    return 0;
}
