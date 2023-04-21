#include "defines.h"
#include "mesh.h"
#include "shader.h"
#include "camera.h"
#include <iostream>
#include <glm/glm.hpp>

Mesh::Mesh(std::vector<Vertex> vertices,Camera* camera,GLenum drawMode) : drawMode(drawMode)
{
    this->camera=camera;
    numVertices=vertices.size();
    //std::cout << "numVertices" << numVertices << std::endl;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);
    

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, GLenum drawMode) : drawMode(drawMode) {
    numVertices = vertices.size();
    numIndices = indices.size();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::draw(Shader* shader, float ratio) const
{
    glm::mat4 projection = glm::perspective(glm::radians(camera->getFOV()),ratio, 0.1f, 100.0f);
    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setMat4("model", model);
    shader->use();
    glBindVertexArray(VAO);
    if (numIndices > 0) {
        glDrawElements(drawMode, numIndices, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(drawMode, 0, numVertices);
    }
    glBindVertexArray(0);
}

