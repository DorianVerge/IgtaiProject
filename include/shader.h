#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{
public:
    Shader(const char* vertexSource, const char* fragmentSource);
    ~Shader();
    void use();
    unsigned int getProgram() const;
private:
    unsigned int shaderProgram;
};
