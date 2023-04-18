#include "defines.h"

Mesh::Mesh(std::vector<Vertex> vertices,GLenum drawMode) : drawMode(drawMode)
{
    this->numVertices=vertices.size();
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

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Mesh::draw() const
{
    glBindVertexArray(VAO);
    glDrawArrays(drawMode, 0, numVertices);
    glBindVertexArray(0);
}