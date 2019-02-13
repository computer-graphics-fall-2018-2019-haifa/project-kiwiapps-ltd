#include "AmbientLight.h"

AmbientLight::AmbientLight() : Light()
{
    SetColor(glm::vec3(0.2, 0.2, 0.2));
}


AmbientLight::~AmbientLight()
{
}
