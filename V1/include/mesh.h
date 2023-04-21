#pragma once

#include <vector>
#include <glad/glad.h>
#include <vertex.h>
#include <shader.h>
#include <camera.h>
class Mesh
{
public:
    Mesh() = default;
    Mesh( std::vector<Vertex> vertices, Camera* camera,GLenum drawMode = GL_LINE_STRIP);
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, GLenum drawMode = GL_LINE_STRIP);
    ~Mesh();
    void draw(Shader* shader, float ratio) const;
    unsigned int getNumVertices() const;
    Camera *camera;
    
private:
    unsigned int numVertices;
    unsigned int numIndices = 0;
    GLenum drawMode;
    unsigned int VAO, VBO , EBO;
};