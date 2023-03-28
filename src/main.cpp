#include "defines.h"

void processInput(GLFWwindow *window);
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

int main()
{
    // glfw: initialize
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }  
    Window myWindow;
    GLFWwindow* window = myWindow.getWindow();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    // ... (set up vertex data and VAO)
        float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };

    Mesh triangle(vertices, sizeof(vertices) / sizeof(float));
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        shader.use();
        triangle.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
