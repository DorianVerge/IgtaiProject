#include "defines.h"


void processInput(GLFWwindow *window);
void parseCommandLineArguments(int argc, char *argv[]);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
std::vector<Vertex> createControlPoints();
std::vector<std::vector<Vertex>> createControlGrid();
std::vector<Vertex> createVertices(std::vector<std::vector<Vertex>> controlPointsGrid);
//Mesh createBezierCurveMesh(std::vector<Vertex> controlPoints);
//Mesh createControlePolygoneMesh(std::vector<Vertex> controlPoints);
//Mesh createBezierSurfaceMesh(std::vector<Vertex> controlPoints);

bool drawControlPolygon = false;
bool drawBezierCurve = false;
bool drawBezierSurface = false;
bool drawNormal = false;
bool drawParametric = false;
bool STOP = true;
float zoomLevel = 45.0f;
float zRotationAngle = 0.0f;
static float angle = 0.0f;
int u=20;
int v=20;
Camera camera(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, glm::vec3(0.0f));

int main(int argc, char *argv[]) {
    parseCommandLineArguments(argc, argv);

    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    Window myWindow;
    GLFWwindow *window = myWindow.getWindow();

    glfwSetWindowUserPointer(window, &myWindow);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);

    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl");
    std::vector<Vertex> controlPoints= createControlPoints();
    std::vector<std::vector<Vertex>> controlPointsGrid = createControlGrid();

    BezierCurve bezierCurve(controlPoints);
    std::vector<Vertex> curvePoints = bezierCurve.discretizeUniformParametric(u);
    Mesh curveMesh(curvePoints);
    Mesh controlPolygonMesh(controlPoints);
    std::cout << "Updated vertices:" << std::endl;
        BezierSurface bezierSurface(controlPointsGrid);
        std::cout << "Updated vertices:" << std::endl;
        std::vector<std::vector<Vertex>> surfacePoints = bezierSurface.discretizeUniformParametric(u,v);
    std::cout << "Updated vertices:" << std::endl;
        SurfaceMesh surfaceMesh(surfacePoints,GL_TRIANGLES);
    std::cout << "Updated vertices:" << std::endl;
    // Access the vertices with updated normals from the surfaceMesh object
    std::cout << "Updated vertices:" << std::endl;
    //const std::vector<std::vector<Vertex>>& updatedVerticesGrid = surfaceMesh.getVerticesGrid();

    std::cout << "Updated vertices:" << std::endl;
    // Print the updated normals
    //for (const auto &row : updatedVerticesGrid) {
        //for (const auto &vertex : row) {
        // std::cout << vertex.position.x << " " << vertex.position.y << " " << vertex.position.z << " "
        //             << vertex.normal.x << " " << vertex.normal.y << " " << vertex.normal.z << std::endl;
    // }
    //}
    if (drawParametric)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Mesh NormalMesh= bezierSurface.createNormalVisualizerMesh(surfacePoints, 0.1f);
     
    //Mesh NormalMesh= bezierSurface.createNormalVisualizerMesh(updatedVerticesGrid, 0.1f); 

  //          for (const auto &vertex : surfacePoints) {
    //            std::cout << vertex[0].position.x << " " << vertex[0].position.y << " " << vertex[0].position.z<< " " << vertex[0].normal.x << " " << vertex[0].normal.y << " " << vertex[0].normal.z << std::endl;
            
    //}
 

    glfwSetScrollCallback(window, scroll_callback);
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        camera.processKeyboardInput(window, deltaTime);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 projection = glm::perspective(glm::radians(camera.getFOV()), myWindow.getAspectRatio(), 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 model = glm::mat4(1.0f);

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", model);
        shader.use();

        glm::vec3 lightDirection(0.5f, -1.0f, 0.5f);
        glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
        shader.setVec3("lightDirection", lightDirection);
        shader.setVec3("lightColor", lightColor);
        glLineWidth(3.0f);
        if (drawBezierCurve)
            curveMesh.draw();
        if (drawControlPolygon)
            controlPolygonMesh.draw();
        if (drawBezierSurface || drawParametric)
            surfaceMesh.draw();
        if (drawNormal)
            NormalMesh.draw();

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
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(3.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)}
    },
    {
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(0.0f, 2.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.0f, 3.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)}
    },
    {
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.5f)},
        {glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        {glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f)}
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
        if (strcmp(argv[i], "-u") == 0 && i + 1 < argc) {
            u = std::stoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-v") == 0 && i + 1 < argc) {
            v = std::stoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-s") == 0) {
            drawBezierSurface = true;
        }
        if (strcmp(argv[i], "-n") == 0) {
            drawNormal = true;
        }
        if (strcmp(argv[i], "-t") == 0) {
            drawParametric = true;
        }
    }
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);    
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.processMouseScroll(yoffset);
}