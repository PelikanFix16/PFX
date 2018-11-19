#include "PFXController.h"


bool PFXController::processInput(int keycode) {

    if(glfwGetKey(this->_window,keycode) == GLFW_PRESS)
        return true;
    else 
        return false;
}

void PFXController::poolEvents() {
    glfwPollEvents();
}

PFXController::PFXController(GLFWwindow* window) {

    this->_window = window;
}
