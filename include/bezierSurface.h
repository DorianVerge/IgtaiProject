class BezierSurface {
public:
    BezierSurface(unsigned int uDegree, unsigned int vDegree, const std::vector<glm::vec3>& controlPoints);
    void discretize(unsigned int uResolution, unsigned int vResolution);
    void createBuffers();
    void draw() const;

private:
    unsigned int uDegree;
    unsigned int vDegree;
    std::vector<glm::vec3> controlPoints;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvCoordinates;
    unsigned int VAO, VBO, EBO;
};
