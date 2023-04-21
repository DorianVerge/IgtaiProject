#pragma once

#include <vector>
#include <glad/glad.h>
#include <vertex.h>

class Mesh
{
public:
    Mesh() = default;
    Mesh( std::vector<Vertex> vertices,GLenum drawMode = GL_LINE_STRIP);
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, GLenum drawMode = GL_LINE_STRIP);
    ~Mesh();
    void draw() const;
    unsigned int getNumVertices() const;
    
private:
    unsigned int numVertices;
    unsigned int numIndices = 0;
    GLenum drawMode;
    unsigned int VAO, VBO , EBO;
};