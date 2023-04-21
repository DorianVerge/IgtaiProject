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

/* std::vector<std::vector<Vertex>> BezierSurface::discretizeUniformParametric(int numSegmentsU, int numSegmentsV) const
{
    std::vector<std::vector<Vertex>> pointsGrid;
    for (int i = 0; i <= numSegmentsU; ++i)
    {
        float u = static_cast<float>(i) / numSegmentsU;
        std::vector<Vertex> row;
        for (int j = 0; j <= numSegmentsV; ++j)
        {
            float v = static_cast<float>(j) / numSegmentsV;
            Vertex point = evaluate(u, v);
            // Vertex partialU = evaluatePartialU(u, v);
            // Vertex partialV = evaluatePartialV(u, v);

            // point.normal = glm::cross(partialU.position, partialV.position);
            // if (glm::length(point.normal) > 0.0f) {
            //   point.normal = glm::normalize(point.normal);
            //} else {
            //  point.normal = glm::vec3(0.0f);
            //}
            point.texCoords = glm::vec2(u, v);
            row.push_back(point);
        }
        pointsGrid.push_back(row);
    }
    return pointsGrid;
} */

std::vector<std::vector<Vertex>> BezierSurface::discretizeUniformParametric(int numSegmentsU, int numSegmentsV) const {
    std::vector<std::vector<Vertex>> pointsGrid;
    for (int i = 0; i <= numSegmentsU; ++i) {
        float u = static_cast<float>(i) / numSegmentsU;
        std::vector<Vertex> row;
        for (int j = 0; j <= numSegmentsV; ++j) {
            float v = static_cast<float>(j) / numSegmentsV;
            Vertex point = evaluate(u, v);

            Vertex partialU = evaluatePartialU(u, v);
            Vertex partialV = evaluatePartialV(u, v);

            point.normal = glm::cross(partialU.position, partialV.position);
            if (glm::length(point.normal) > 0.0f) {
                point.normal = glm::normalize(point.normal);
            } else {
                point.normal = glm::vec3(0.0f);
            }

            point.texCoords = glm::vec2(u, v);
            row.push_back(point);
        }
        pointsGrid.push_back(row);
    }
    return pointsGrid;
}


Vertex BezierSurface::evaluatePartialU(float u, float v) const {
    std::vector<Vertex> curvePoints;
    for (const auto& controlPoints : controlPointsGrid) {
        BezierCurve curve(controlPoints);
        curvePoints.push_back(curve.evaluateDerivative(u));
    }

    BezierCurve finalCurve(curvePoints);
    return finalCurve.evaluate(v);
}

Vertex BezierSurface::evaluatePartialV(float u, float v) const {
    std::vector<Vertex> curvePoints;
    for (int i = 0; i < controlPointsGrid.size(); ++i) {
        BezierCurve curve(controlPointsGrid[i]);
        curvePoints.push_back(curve.evaluateDerivative(v));
    }

    BezierCurve finalCurve(curvePoints);
    return finalCurve.evaluate(u);
}

Mesh BezierSurface::createNormalVisualizerMesh(const std::vector<std::vector<Vertex>>& surfaceVertices, float normalLength) {
    std::vector<Vertex> normalVertices;

    for (const auto& row : surfaceVertices) {
        for (const auto& vertex : row) {
            // Add the original vertex position
            normalVertices.push_back({
                vertex.position,
                glm::vec3(1.0f, 1.0f, 1.0f),
                glm::vec3(0.0f)
            });

            // Add the offset vertex position
            normalVertices.push_back({
                vertex.position + vertex.normal * normalLength,
                glm::vec3(1.0f, 1.0f, 1.0f),
                glm::vec3(0.0f)
            });
        }
    }

    return Mesh(normalVertices, GL_LINES);
}