#pragma once
#include "mesh.h"
#include <vector>

class SurfaceMesh : public Mesh {
public:
    SurfaceMesh(const std::vector<std::vector<Vertex>>& verticesGrid, GLenum drawMode = GL_LINE_STRIP);
private:
    std::vector<GLuint> createIndices(const std::vector<std::vector<Vertex>>& verticesGrid);
    std::vector<Vertex> createVertices(const std::vector<std::vector<Vertex>>& verticesGrid);
};