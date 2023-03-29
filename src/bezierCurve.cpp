#include "bezierCurve.h"
#include "defines.h"

BezierCurve::BezierCurve(const std::vector<Vertex>& controlPoints)
    : controlPoints(controlPoints) {}

Vertex BezierCurve::evaluate(float t) const {
    return deCasteljau(controlPoints, t);
}

std::vector<Vertex> BezierCurve::discretizeUniformParametric(int numSegments) const {
    std::vector<Vertex> points;
    for (int i = 0; i <= numSegments; ++i) { 
        float t = static_cast<float>(i) / numSegments;
        points.push_back(evaluate(t));
    }
    return points;
}

Vertex BezierCurve::deCasteljau(const std::vector<Vertex>& points, float t) const {
    if (points.size() == 1) {
        return points[0];
    }

    std::vector<Vertex> newPoints;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        ///std::cout << "points"  <<points[i+1].x << points[i+1].y << std::endl;
        newPoints.push_back(glm::mix(points[i].position, points[i + 1].position, t));
    }

    return deCasteljau(newPoints, t);
}