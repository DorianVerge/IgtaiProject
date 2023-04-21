#include "surfaceMesh.h"
#include "../include/defines.h"

SurfaceMesh::SurfaceMesh(const std::vector<std::vector<Vertex>>& verticesGrid, GLenum drawMode)
    : m_vertices(createVertices(verticesGrid)),
      m_indices(createIndices(verticesGrid)),
      drawMode(drawMode),
      numVertices(m_vertices.size()),
      numIndices(m_indices.size()) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), &m_indices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //updateNormals();
}

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

    for (int i = 0; i < (numRows - 1); ++i) {
        for (int j = 0; j < (numCols - 1); ++j) {
            indices.push_back(i * numCols + j);
            indices.push_back(i * numCols + j + 1);
            indices.push_back((i + 1) * numCols + j);

            indices.push_back((i + 1) * numCols + j);
            indices.push_back((i + 1) * numCols + j + 1);
            indices.push_back(i * numCols + j + 1);
        }
    }
    return indices;
}

/* void SurfaceMesh::updateNormals() {
    std ::cout << "updateNormals" << std::endl;
    std::vector<glm::vec3> normals = generateNormals();
    std ::cout << "updateNormals" << std::endl;
    int numRows = m_verticesGrid.size();
    int numCols = m_verticesGrid[0].size();
    std::cout << "numRows: " << numRows << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            m_verticesGrid[i][j].normal = normals[i * numCols + j];
        }
    }
}



glm::vec3 SurfaceMesh::calculateNormal(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3) {
    glm::vec3 vector1 = point2 - point1;
    glm::vec3 vector2 = point3 - point1;
    glm::vec3 normal = glm::cross(vector1, vector2);
    return glm::normalize(normal);
}

std::vector<glm::vec3> SurfaceMesh::generateNormals() {
    int numRows = m_verticesGrid.size();
    int numCols = m_verticesGrid[0].size();
    std::vector<glm::vec3> normals(numRows * numCols, glm::vec3(0.0f, 0.0f, 0.0f));
    std::vector<int> nbNormals(numRows * numCols, 0);

    for (int i = 0; i < numRows - 1; ++i) {
        for (int j = 0; j < numCols - 1; ++j) {
            glm::vec3 normal1 = calculateNormal(
                m_verticesGrid[i][j].position,
                m_verticesGrid[i][j + 1].position,
                m_verticesGrid[i + 1][j].position
            );
            glm::vec3 normal2 = calculateNormal(
                m_verticesGrid[i + 1][j].position,
                m_verticesGrid[i + 1][j + 1].position,
                m_verticesGrid[i][j + 1].position
            );

            normals[i * numCols + j] += normal1;
            normals[i * numCols + j + 1] += normal1 + normal2;
            normals[(i + 1) * numCols + j] += normal1 + normal2;
            normals[(i + 1) * numCols + j + 1] += normal2;

            nbNormals[i * numCols + j]++;
            nbNormals[i * numCols + j + 1] += 2;
            nbNormals[(i + 1) * numCols + j] += 2;
            nbNormals[(i + 1) * numCols + j + 1]++;
                std::vector<unsigned int> disconnectedVertices;

for (unsigned int i = 0; i < nbNormals.size(); i++) {
    if (nbNormals[i] == 0) {
        disconnectedVertices.push_back(i);
        std::cout << "Disconnected vertex found at index: " << i << std::endl;
    }
}
        }
    }


    for (int i = 0; i < numRows * numCols; ++i) {
        normals[i] /= nbNormals[i];
        normals[i] = glm::normalize(normals[i]);
    }

    return normals;
} 

std::vector<Vertex> SurfaceMesh::getVertices() const {
    return m_vertices;
}

std::vector<std::vector<Vertex>> SurfaceMesh::getVerticesGrid() const {
    return m_verticesGrid;
}*/

void SurfaceMesh::draw() const {
    glBindVertexArray(VAO);
    if (numIndices > 0) {
        glDrawElements(drawMode, numIndices, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(drawMode, 0, numVertices);
    }
    glBindVertexArray(0);
}
