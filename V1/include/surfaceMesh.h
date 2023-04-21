#pragma once
#include <vector>

#include "defines.h"

class SurfaceMesh {
public:
    SurfaceMesh(const std::vector<std::vector<Vertex>>& verticesGrid, GLenum drawMode);
    void draw() const;

private:
    std::vector<Vertex> createVertices(const std::vector<std::vector<Vertex>>& verticesGrid);
    std::vector<GLuint> createIndices(const std::vector<std::vector<Vertex>>& verticesGrid);
    void updateNormals();
    void updateVBO(const std::vector<Vertex>& vertices);

    std::vector<Vertex> m_vertices;
    std::vector<std::vector<Vertex>> m_verticesGrid;
    std::vector<GLuint> m_indices;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    GLenum drawMode;
    size_t numVertices;
    size_t numIndices;
};