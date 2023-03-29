#pragma once

#include <vector>
#include <glad/glad.h>
#include <vertex.h>

class Mesh
{
public:
    Mesh( std::vector<Vertex> vertices);
    ~Mesh();
    void draw() const;

private:
    unsigned int VAO, VBO,numVertices;
};