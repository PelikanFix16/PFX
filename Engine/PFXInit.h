#pragma once 
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class PFXInit {


    private:
        int _width;
        int _height;
        std::string _title;
        GLFWwindow* _window;

    
    public:
        PFXInit(std::string title,int width,int height);
        ~PFXInit();
        int Set();
        bool isClosedWindow();
        void clearBuffer(float r,float g,float b,float a);
        void swapBuffer();
        inline GLFWwindow* getWindow() {return this->_window;};
        void closeWindow();

    private:
        static void framebuffer_size_callback(GLFWwindow* window,int width,int height);





    


};
