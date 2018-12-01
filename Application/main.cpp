#include <iostream>
#include "../Engine/PFXInit.h"
#include "../Engine/PFXController.h"
#include "../Engine/Shader.h"
#include "../Engine/Buffer.h"
#include "../Engine/Texture.h"

int main(int argc,char* argv[]) {   



    
    PFXInit* pfx = new PFXInit("PFX ENGINE",800,600);
    pfx->Set();

    PFXController* controller = new PFXController(pfx->getWindow());
    
    Shader* shader = new Shader();
    shader->loadShader("./Engine/ShadersSrc/shader.vs",Shader::ShaderType::vertexShader);
    shader->loadShader("./Engine/ShadersSrc/shader.fs",Shader::ShaderType::fragmentShader);
    shader->compileShader();

    Buffer* buf = new Buffer();
    Texture* tex = new Texture("/Users/hubertosypowicz/Dev/OpenGL/PFX/Textures/pepe.png",0);

   float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
   unsigned int indices[] = { 
        0, 1, 3,  
        1, 2, 3   
    };  
  
   buf->LoadVert(vertices,sizeof(vertices));
   buf->AddAttrib(0,3,8,0);
   buf->AddAttrib(1,3,8,3);
   buf->AddAttrib(2,3,8,6);
   buf->LoadIndices(indices,sizeof(indices));

   

  

    shader->use();
    shader->setUniform1i("texture1",0);


   while(!pfx->isClosedWindow()) {

        if(controller->processInput(256))
        
        pfx->closeWindow();
        pfx->clearBuffer(0.4f,0.2f,0.1f,1.0f);
        tex->activeTexture();
        shader->use();

        buf->drawIndices();

        pfx->swapBuffer();
        controller->poolEvents();


   }

    delete buf;
    delete pfx;

    return 0;
}
