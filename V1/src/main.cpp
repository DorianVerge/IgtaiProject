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
bool drawNormalSurface = false;
bool drawColoredNormal = false;
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

    Light light0 = Light(0, glm::vec3(5.0f, 0.0f, 10.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f);
    Light light1 = Light(1, glm::vec3(-4.0f, 0.0f, 9.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f);
    Light light2 = Light(2, glm::vec3(-4.0f, 0.0f, -9.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f);
    std::vector<Light*> lights = {&light0,&light1,&light2};

    Shader shader("shaders/basicShaders/vertexShader.glsl", "shaders/basicShaders/fragmentShader.glsl");
    Shader SurfaceShader("shaders/surfaceshader/vertexShader.glsl", "shaders/surfaceshader/fragmentShader.glsl");
    std::vector<Vertex> controlPoints= createControlPoints();
    std::vector<std::vector<Vertex>> controlPointsGrid = createControlGrid();

    BezierCurve bezierCurve(controlPoints);
    std::vector<Vertex> curvePoints = bezierCurve.discretizeUniformParametric(u);
    Mesh curveMesh(curvePoints, &camera);
    Mesh controlPolygonMesh(controlPoints, &camera);

    BezierSurface bezierSurface(controlPointsGrid);

    std::vector<std::vector<Vertex>> surfacePoints = bezierSurface.discretizeUniformParametric(u,v);

    SurfaceMesh surfaceMesh(surfacePoints,lights, &camera,GL_TRIANGLES);
    NormalMesh coloredNormalMesh(surfacePoints,lights, &camera,GL_TRIANGLES);


    if (drawParametric)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Mesh NormalMesh= surfaceMesh.createNormalVisualizerMesh(surfacePoints, 0.1f);
     

    

    glfwSetScrollCallback(window, scroll_callback);
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    float ratio;

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        camera.processKeyboardInput(window, deltaTime);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(3.0f);
        ratio=  myWindow.getAspectRatio();
        if (drawBezierCurve)
            curveMesh.draw(&shader,ratio);
        if (drawControlPolygon)
            controlPolygonMesh.draw(&shader,ratio);
        if (drawBezierSurface || drawParametric)
            surfaceMesh.draw(&SurfaceShader,ratio);
        if (drawNormal)
            NormalMesh.draw(&shader, ratio);
        if (drawNormalSurface){
            NormalMesh.draw(&shader, ratio);
            surfaceMesh.draw(&shader, ratio);
        }
        if (drawColoredNormal)
            coloredNormalMesh.draw(&shader, ratio);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
        

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
        {glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.9f)},
        {glm::vec3(3.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.0f, 0.0f)}
    },
    {
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        {glm::vec3(0.0f, 2.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.9f)},
        {glm::vec3(0.0f, 3.0f, 0.0f), glm::vec3(0.5f, 0.0f, 0.0f)}
    },
    {
        {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        {glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.5f)},
        {glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.9f)},
        {glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.5f, 0.0f, 0.0f)}
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
        if (strcmp(argv[i], "-ns") == 0) {
            drawNormalSurface = true;
        }
        if (strcmp(argv[i], "-t") == 0) {
            drawParametric = true;
        }
        if (strcmp(argv[i], "-nc") == 0) {
            drawColoredNormal = true;
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