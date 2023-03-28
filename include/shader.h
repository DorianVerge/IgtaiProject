#pragma once

#include "defines.h"

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    void use();
    unsigned int getProgram() const;
private:
    unsigned int shaderProgram;
};
