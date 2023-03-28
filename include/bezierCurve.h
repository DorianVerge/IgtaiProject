#pragma once

#include <glm/glm.hpp>
#include <vector>
class BezierCurve {
public:
    BezierCurve(const std::vector<glm::vec3>& controlPoints);

    glm::vec3 evaluate(float t) const;

    std::vector<glm::vec3> discretizeUniformParametric(int numSegments) const;

private:
    std::vector<glm::vec3> controlPoints;

    glm::vec3 deCasteljau(const std::vector<glm::vec3>& points, float t) const;
};