#pragma once

#include <glad/glad.h>

class Mesh
{
public:
    Mesh(float* vertices, unsigned int numVertices);
    ~Mesh();
    void draw() const;

private:
    unsigned int VAO, VBO;
};