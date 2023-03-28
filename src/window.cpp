#include "../include/defines.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


// settings
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void window_size_callback(GLFWwindow* window, int width, int height);

Window::Window()  {

    // Get the primary monitor
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();

    // Get the video mode of the primary monitor
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    m_width = (mode->width * 4 / 10);
    m_height = (mode->height * 5 / 10);
    
    // glfw: initialize and configure
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    window = glfwCreateWindow(m_width, m_height, "ProjectScene", NULL ,NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
    // Charger l'image
    int icon_width, icon_height, icon_channels;
    unsigned char* icon_data = stbi_load("objects/SaleGeuleD'Andrew.png", &icon_width, &icon_height, &icon_channels, 0);
    // Définir l'icône de la fenêtre
    if (icon_data)
    {
        GLFWimage icon;
        icon.width = icon_width;
        icon.height = icon_height;
        icon.pixels = icon_data;
        glfwSetWindowIcon(window, 1, &icon);
        stbi_image_free(icon_data);
    }
    else
    {
        std::cout << "Failed to load icon image" << std::endl;
    }
    // Wait for the window to be displayed by the window manager
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Get the position of the primary monitor
    int monitorX, monitorY;
    glfwGetMonitorPos(primaryMonitor, &monitorX, &monitorY);

    // Calculate the window position to center it on the primary monitor
    int xPos = monitorX + (mode->width - m_width) / 2;
    int yPos = monitorY + (mode->height - m_height) / 2;

    // Set the window position on the primary monitor
    glfwSetWindowPos(window, xPos, yPos);

}

Window::~Window(){
    glfwTerminate();
}

GLFWwindow* Window::getWindow(){
    return window;
}
unsigned int Window::getHeight(){
    return m_height;
}

unsigned int Window::getWidth(){
    return m_width;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    float aspectRatio = 800.0f / 600.0f; // 4:3 aspect ratio
    int newWidth = width;
    int newHeight = static_cast<int>(width / aspectRatio);

    if (newHeight > height)
    {
        newHeight = height;
        newWidth = static_cast<int>(height * aspectRatio);
    }

    int xOffset = (width - newWidth) / 2;
    int yOffset = (height - newHeight) / 2;

    glViewport(xOffset, yOffset, newWidth, newHeight);
}

    

