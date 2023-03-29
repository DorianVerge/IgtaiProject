#include "defines.h"

void processInput(GLFWwindow *window);

int main() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    Window myWindow;
    GLFWwindow *window = myWindow.getWindow();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    std::vector<Vertex> controlPoints = {
        {glm::vec3(-0.5f, 0.0f, 1.0f),glm::vec3(0.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, 0.5f, 0.5f),glm::vec3(0.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.5f, 0.5f),glm::vec3(0.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, 0.0f, 0.5f),glm::vec3(0.0f, 0.0f, 0.0f)}
    };
    BezierCurve bezierCurve(controlPoints);

    std::vector<Vertex> curvePoints = bezierCurve.discretizeUniformParametric(20);
    std::cout << "curve points" << curvePoints.size() << std::endl;
    std::vector<Vertex> vertices;
    for (const auto &point : curvePoints) {
        vertices.push_back({point});
    }
    std::cout << "curve points" << curvePoints.size() << std::endl;
    std::cout << "Vertices:" << std::endl;

    Mesh curveMesh=Mesh(vertices);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        shader.use();
        glLineWidth(3.0f);
        curveMesh.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
