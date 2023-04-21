#include "normalMesh.h"
#include "../include/defines.h"

NormalMesh::NormalMesh(const std::vector<std::vector<Vertex>>& verticesGrid, std::vector<Light*> lights,Camera* camera, GLenum drawMode)
    : m_vertices(createVertices(verticesGrid)),
      m_indices(createIndices(verticesGrid)),
      drawMode(drawMode),
      numVertices(m_vertices.size()),
      numIndices(m_indices.size()),
      m_lights(lights) {
    this->camera = camera;
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

std::vector<Vertex> NormalMesh::createVertices(const std::vector<std::vector<Vertex>>& verticesGrid) {
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

std::vector<GLuint> NormalMesh::createIndices(const std::vector<std::vector<Vertex>>& verticesGrid) {
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

Mesh NormalMesh::createNormalVisualizerMesh(const std::vector<std::vector<Vertex>>& surfaceVertices, float normalLength) {
    std::vector<Vertex> normalVertices;

    for (const auto& row : surfaceVertices) {
        for (const auto& vertex : row) {
            // Add the original vertex position
            normalVertices.push_back({
                vertex.position,
                glm::vec3(1.0f, 0.5f, 0.31f),
                glm::vec3(0.0f)
            });

            // Add the offset vertex position
            normalVertices.push_back({
                vertex.position + vertex.normal * normalLength,
                glm::vec3(1.0f, 0.4f, 0.4f),
                glm::vec3(0.0f)
            });
        }
    }

    return Mesh(normalVertices,camera, GL_LINES);
}


void NormalMesh::draw(Shader* shader,float ratio) const {
    shader->use();
    glm::mat4 projection = glm::perspective(glm::radians(camera->getFOV()),ratio, 0.1f, 100.0f);
    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);
    for (unsigned int i = 0; i < m_lights.size(); i++) {
        shader->setVec3("lightPositions[" + std::to_string(i) + "]", m_lights[i]->getPosition());
        shader->setVec3("lightColors[" + std::to_string(i) + "]", m_lights[i]->getColor());
    }
    shader->setVec3("cameraPosition", camera->getPosition());

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setMat4("model", model);
    
    
    glBindVertexArray(VAO);
    if (numIndices > 0) {
        glDrawElements(drawMode, numIndices, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(drawMode, 0, numVertices);
    }
    glBindVertexArray(0);
}
