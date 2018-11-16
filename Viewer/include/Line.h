#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

class Line
{
private:
    
    
public:
    Line(const glm::vec3 point1, const glm::vec3 point2);
    virtual ~Line();
    
    glm::vec3 point1;
    glm::vec3 point2;
    
    std::vector<glm::vec3> getPoints();
};
