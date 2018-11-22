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

    Buffer* buf = new Buffer();
    
      float vertices[] = {
         0.5f,  0.5f, 0.0f,  
         0.5f, -0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,  
        -0.5f,  0.5f, 0.0f  
    };

   unsigned int indices[] = { 
        0, 1, 3,  
        1, 2, 3   
    };  
  
   buf->LoadVert(vertices,sizeof(vertices));
   buf->AddAttrib(0,3,3,0);
   buf->LoadIndices(indices,sizeof(indices));
    
    while(!pfx->isClosedWindow()) {

        if(controller->processInput(256))
           pfx->closeWindow();
       
    
        pfx->clearBuffer(0.4f,0.2f,0.1f,1.0f);

        shader->use();

        buf->drawIndices();

        pfx->swapBuffer();
        controller->poolEvents();


   }

    delete buf;
    delete pfx;

    return 0;
}
