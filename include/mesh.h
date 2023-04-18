#pragma once

#include <vector>
#include <glad/glad.h>
#include <vertex.h>

class Mesh
{
public:
    Mesh() = default;
    Mesh( std::vector<Vertex> vertices,GLenum drawMode = GL_LINE_STRIP);
    ~Mesh();
    void draw() const;
    unsigned int numVertices;

private:
    GLenum drawMode;
    unsigned int VAO, VBO;
};