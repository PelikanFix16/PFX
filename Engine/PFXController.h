#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
class PFXController {



    private:
        GLFWwindow* _window;

    public:
        PFXController(GLFWwindow* window);
        void processInput();
        void poolEvents();





};
