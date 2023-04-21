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
        newPoints.push_back({glm::mix(points[i].position, points[i + 1].position, t),glm::mix(points[i].color, points[i + 1].color, t)});
    }

    return deCasteljau(newPoints, t);
}

Vertex BezierCurve::evaluateDerivative(float t) const {
    if (controlPoints.size() <= 1) {
        return Vertex{glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f)};
    }

    std::vector<Vertex> reducedControlPoints;
    for (size_t i = 0; i < controlPoints.size() - 1; ++i) {
        reducedControlPoints.push_back({
            controlPoints[i + 1].position - controlPoints[i].position,
            controlPoints[i + 1].color - controlPoints[i].color,
            glm::vec3(0.0f)
        });
    }

    BezierCurve derivativeCurve(reducedControlPoints);
    return derivativeCurve.evaluate(t);
}
