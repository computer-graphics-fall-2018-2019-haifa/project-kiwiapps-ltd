#include "PointLight.h"
#include <algorithm>

PointLight::PointLight(const glm::vec3& position) :
	Light(),
	position(position)
{
}

PointLight::PointLight(const glm::vec3& position, const glm::vec3& color) :
	Light(),
	position(position)
{
    SetColor(glm::vec3(0.2, 0.2, 0.2));
}

PointLight::~PointLight()
{
}

glm::vec3& PointLight::GetPosition()
{
	return position;
}
