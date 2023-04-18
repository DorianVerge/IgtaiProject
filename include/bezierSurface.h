#pragma once

#include <vector>
#include "vertex.h"
#include "bezierCurve.h"

class BezierSurface {
public:
    BezierSurface(const std::vector<std::vector<Vertex>>& controlPointsGrid);

    Vertex evaluate(float u, float v) const;
    std::vector<std::vector<Vertex>> discretizeUniformParametric(int numSegmentsU, int numSegmentsV) const;

private:
    std::vector<std::vector<Vertex>> controlPointsGrid;
};
