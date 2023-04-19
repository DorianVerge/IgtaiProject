#include "surfaceMesh.h"
#include "defines.h"

#include "surfaceMesh.h"


SurfaceMesh::SurfaceMesh(const std::vector<std::vector<Vertex>>& verticesGrid, GLenum drawMode)
    : Mesh(createVertices(verticesGrid), createIndices(verticesGrid), drawMode) {}

std::vector<Vertex> SurfaceMesh::createVertices(const std::vector<std::vector<Vertex>>& verticesGrid) {
    std::vector<Vertex> vertices;
    int numRows = verticesGrid.size();
    int numCols = verticesGrid[0].size();

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            vertices.push_back(verticesGrid[i][j]);
        }
    }
    return vertices;
}

std::vector<GLuint> SurfaceMesh::createIndices(const std::vector<std::vector<Vertex>>& verticesGrid) {
    std::vector<GLuint> indices;
    int numRows = verticesGrid.size();
    int numCols = verticesGrid[0].size();

    for (int i = 0; i < numRows - 1; ++i) {
        for (int j = 0; j < numCols - 1; ++j) {
            indices.push_back(i * numCols + j);
            indices.push_back(i * numCols + j + 1);
            indices.push_back((i + 1) * numCols + j);

            indices.push_back((i + 1) * numCols + j);
            indices.push_back(i * numCols + j + 1);
            indices.push_back((i + 1) * numCols + j + 1);
        }
    }
    return indices;
}