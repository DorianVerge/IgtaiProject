#include "defines.h"

void processInput(GLFWwindow *window);
bool drawControlPolygon = false;
bool drawBezierCurve = false;

int main(int argc, char *argv[]) {
    std::cout << argc << argv[0]<< argv[1] << std::endl;
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-p") == 0)
        {
            drawControlPolygon = true;
        }
        if (strcmp(argv[i], "-b") == 0)
        {
            drawBezierCurve = true;
        }
    }
    Window myWindow;
    GLFWwindow *window = myWindow.getWindow();

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");

    std::vector<Vertex> controlPoints = {
    {glm::vec3(-0.5f, -0.5f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
    {glm::vec3(0.5f, -0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
    {glm::vec3(0.0f, 0.5f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
    {glm::vec3(-0.5f, -0.5f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)}
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
    for (const auto &vertex : vertices) {
        std::cout << vertex.color.x << " " << vertex.color.y << " " << vertex.color.z << std::endl;
    }
    static float angle = 0.0f;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
    Mesh curveMesh=Mesh(vertices);
    Mesh controlPolygonMesh = Mesh(controlPoints);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        angle+=0.1f;
        rotationMatrix=glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))*rotationMatrix;;
        glm::mat4 model = glm::mat4(1.0f);

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", model);
        shader.use();
        glLineWidth(3.0f);
        if (drawBezierCurve)
            curveMesh.draw();
        if (drawControlPolygon)
            controlPolygonMesh.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
