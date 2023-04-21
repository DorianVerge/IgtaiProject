#pragma once

#include <vector>
#include "vertex.h"
#include "bezierCurve.h"
#include "mesh.h"

class BezierSurface {
public:
    BezierSurface(const std::vector<std::vector<Vertex>>& controlPointsGrid);

    Vertex evaluate(float u, float v) const;
    std::vector<std::vector<Vertex>> discretizeUniformParametric(int numSegmentsU, int numSegmentsV) const;
    Mesh createNormalVisualizerMesh(const std::vector<std::vector<Vertex>>& surfaceVertices, float normalLength);

private:
    std::vector<std::vector<Vertex>> controlPointsGrid;
    Vertex evaluatePartialU(float u, float v) const;
    Vertex evaluatePartialV(float u, float v) const;
};
