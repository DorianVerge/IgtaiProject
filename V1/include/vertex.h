#pragma once
#include <glm/glm.hpp>
struct Vertex {
    glm::vec3 position;
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 normal;
    glm::vec2 texCoords;
};