#include "bezierSurface.h"
#include "defines.h"

BezierSurface::BezierSurface(const std::vector<std::vector<Vertex>>& controlPointsGrid)
    : controlPointsGrid(controlPointsGrid) {}

Vertex BezierSurface::evaluate(float u, float v) const {
    std::vector<Vertex> curvePoints;
    for (const auto& controlPoints : controlPointsGrid) {
        BezierCurve curve(controlPoints);
        curvePoints.push_back(curve.evaluate(u));
    }

    BezierCurve finalCurve(curvePoints);
    return finalCurve.evaluate(v);
}

std::vector<std::vector<Vertex>> BezierSurface::discretizeUniformParametric(int numSegmentsU, int numSegmentsV) const {
    std::vector<std::vector<Vertex>> pointsGrid;
    for (int i = 0; i <= numSegmentsU; ++i) {
        float u = static_cast<float>(i) / numSegmentsU;
        std::vector<Vertex> row;
        for (int j = 0; j <= numSegmentsV; ++j) {
            float v = static_cast<float>(j) / numSegmentsV;
            row.push_back(evaluate(u, v));
        }
        pointsGrid.push_back(row);
    }
    return pointsGrid;
}