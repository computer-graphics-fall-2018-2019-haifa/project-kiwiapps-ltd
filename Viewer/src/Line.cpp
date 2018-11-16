
#include "Line.h"

Line::Line(glm::vec3 point1, glm::vec3 point2) :
point1(point1),
point2(point2)
{
    
}

Line::~Line()
{
    
}

std::vector<glm::vec3> Line::getPoints() {
    
    std::vector<glm::vec3> points;
    points.push_back(point1);
    points.push_back(point2);
    return points;
}
