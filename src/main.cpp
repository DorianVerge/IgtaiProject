#include "defines.h"


void processInput(GLFWwindow *window);
void parseCommandLineArguments(int argc, char *argv[]);
std::vector<Vertex> createControlPoints();
std::vector<std::vector<Vertex>> createControlGrid();
std::vector<Vertex> createVertices(std::vector<std::vector<Vertex>> controlPointsGrid);
//Mesh createBezierCurveMesh(std::vector<Vertex> controlPoints);
//Mesh createControlePolygoneMesh(std::vector<Vertex> controlPoints);
//Mesh createBezierSurfaceMesh(std::vector<Vertex> controlPoints);

bool drawControlPolygon = false;
bool drawBezierCurve = false;
bool STOP = false;
float zoomLevel = 45.0f;
float zRotationAngle = 0.0f;

int main(int argc, char *argv[]) {
    parseCommandLineArguments(argc, argv);

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
    std::vector<Vertex> controlPoints= createControlPoints();
    std::vector<std::vector<Vertex>> controlPointsGrid = createControlGrid();

    BezierCurve bezierCurve(controlPoints);
    std::vector<Vertex> curvePoints = bezierCurve.discretizeUniformParametric(20);
    Mesh curveMesh(curvePoints);
    Mesh controlPolygonMesh(controlPoints);

    BezierSurface bezierSurface(controlPointsGrid);
    std::vector<std::vector<Vertex>> surfacePoints = bezierSurface.discretizeUniformParametric(20,20);

    std::vector<Vertex> surfaceVertices= createVertices(surfacePoints);

    Mesh surfaceMesh(surfaceVertices, GL_TRIANGLE_STRIP);
 
    static float angle = 0.0f;
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        if (!STOP){
            angle+=0.1f;
            rotationMatrix=glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        }
        glm::mat4 zRotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(zRotationAngle), glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 projection = glm::perspective(glm::radians(zoomLevel), 800.0f / 600.0f, 0.1f, 100.0f);
        glm::mat4 view = zRotationMatrix * glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))*rotationMatrix;;
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
        if (1)
            surfaceMesh.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    std::cout << "curve points"  << std::endl;

    return 0;
}

std::vector<Vertex> createControlPoints() {
    std::vector<Vertex> controlPoints = {
        {glm::vec3(-0.5f, -0.5f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.5f, -0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(0.0f, 0.5f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(-0.5f, -0.5f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)}
        };

    return controlPoints;
}

std::vector<std::vector<Vertex>> createControlGrid(){
    std::vector<std::vector<Vertex>> controlPointsGrid = {
    {
        {glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, -1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f)}
    },
    {
        {glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f)},
        {glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 1.0f)},
        {glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f)}
    },
    {
        {glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 0.5f, 0.0f)},
        {glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.5f, 1.0f)},
        {glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(0.5f, 0.0f, 1.0f)}
    }
    };
    return controlPointsGrid;
}

std::vector<Vertex> createVertices(std::vector<std::vector<Vertex>> surfacePoints){
    std::vector<Vertex> vertices;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            vertices.push_back(surfacePoints[i][j]);
            vertices.push_back(surfacePoints[i + 1][j]);
        }
        if (i < 20 - 1) {
            // Add degenerate vertices to connect strips
            vertices.push_back(surfacePoints[i + 1][20]);
            vertices.push_back(surfacePoints[i + 1][0]);
        }
    }
    
    return vertices;
}

void parseCommandLineArguments(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++)
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
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        STOP=!STOP;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        zoomLevel -= 0.3f;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        zoomLevel += 0.3f;  
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        zRotationAngle -= 0.3f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        zRotationAngle += 0.3f;       
}
