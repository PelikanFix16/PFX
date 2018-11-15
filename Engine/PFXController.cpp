#include "PFXController.h"


void PFXController::processInput() {

   if(glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(this->_window, true);
        std::cout << "window was closed" << std::endl;
   }

}

void PFXController::poolEvents() {
    glfwPollEvents();
}

PFXController::PFXController(GLFWwindow* window) {

    this->_window = window;
}
