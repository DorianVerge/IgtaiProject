#pragma once 
#include "defines.h"

class Window {
    private:
        GLFWwindow* window;
        unsigned int m_width;
        unsigned int m_height; 
        GLFWvidmode* mode;   
    public:
        Window();
        ~Window();
        unsigned int getWidth();
        unsigned int getHeight();
        GLFWwindow* getWindow();

};
