#pragma once

#include <glm/glm.hpp>
#include <vertex.h>
#include <vector>
class BezierCurve {
public:
    BezierCurve(const std::vector<Vertex>& controlPoints);

    Vertex evaluate(float t) const;

    std::vector<Vertex> discretizeUniformParametric(int numSegments) const;
    Vertex evaluateDerivative(float t) const;

private:
    std::vector<Vertex> controlPoints;

    Vertex deCasteljau(const std::vector<Vertex>& points, float t) const;
};