#include "bezierCurve.h"
#include "defines.h"

BezierCurve::BezierCurve(const std::vector<glm::vec3>& controlPoints)
    : controlPoints(controlPoints) {}

glm::vec3 BezierCurve::evaluate(float t) const {
    return deCasteljau(controlPoints, t);
}

std::vector<glm::vec3> BezierCurve::discretizeUniformParametric(int numSegments) const {
    std::cout << "numSegments: " << numSegments << std::endl; // Add this line for debugging
    std::vector<glm::vec3> points;
    for (int i = 0; i <= numSegments; ++i) {
        float t = static_cast<float>(i) / numSegments;
        points.push_back(evaluate(t));
    }
    return points;
}

glm::vec3 BezierCurve::deCasteljau(const std::vector<glm::vec3>& points, float t) const {
    if (points.size() == 1) {
        return points[0];
    }

    std::vector<glm::vec3> newPoints;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        newPoints.push_back(glm::mix(points[i], points[i + 1], t));
    }

    return deCasteljau(newPoints, t);
}