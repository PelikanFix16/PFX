#include "PFXInit.h"


PFXInit::PFXInit(std::string title,int width,int height) {

    this->_width = width;
    this->_height = height;
    this->_title = title;


}

PFXInit::~PFXInit() {

    glfwTerminate();
 
}

int PFXInit::Set() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->_window = glfwCreateWindow(this->_width,this->_height,this->_title.c_str(),NULL,NULL);

    if(this->_window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->_window);
    glfwSetFramebufferSizeCallback(this->_window,framebuffer_size_callback);

    GLenum err = glewInit();
    
    if(GLEW_OK != err){
        std::cout << "Failed to load glew" << std::endl;

    }




}

void PFXInit::framebuffer_size_callback(GLFWwindow* window,int width,int height) {

    glViewport(0,0,width,height);


}

bool PFXInit::isClosedWindow() {

    return glfwWindowShouldClose(this->_window);

}

void PFXInit::clearBuffer(float r,float g,float b,float a) {

    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);


}

void PFXInit::swapBuffer() {

    glfwSwapBuffers(this->_window);

}

void PFXInit::closeWindow() {

    glfwSetWindowShouldClose(this->_window,true);

}
