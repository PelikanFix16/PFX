#include <iostream>
#include "../Engine/PFXInit.h"
#include "../Engine/PFXController.h"

int main(int argc,char* argv[]) {


    PFXInit* pfx = new PFXInit("PFX ENGINE",800,600);
    pfx->Set();

    PFXController* controller = new PFXController(pfx->getWindow());

   while(!pfx->isClosedWindow()) {

       controller->processInput();

       pfx->clearBuffer(0.4f,0.2f,0.1f,1.0f);

       pfx->swapBuffer();

       controller->poolEvents();


   }

    delete pfx;

    return 0;
}
