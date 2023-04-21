#pragma once

#include "defines.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    void use();
    void setMat4(const std::string& name, const glm::mat4& matrix) const;
    unsigned int getProgram() const;
    void setVec3(const std::string& name, const glm::vec3& vec) const;
private:
    unsigned int shaderProgram;
};
