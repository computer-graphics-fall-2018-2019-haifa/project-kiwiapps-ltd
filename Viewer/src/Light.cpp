#include "Light.h"
#include "ImguiMenus.h"
#include "Utils.h"
#include <vector>
#include <iostream>

Light::Light():
color(glm::vec3(1.0, 1.0, 1.0)),
model(Utils::LoadMeshModelPointer(GetLightPath()))
{
    model->translate = glm::vec3(10, 10, 0);
}

Light::~Light()
{
}

glm::vec3& Light::GetColor()
{
	return color;
}

void Light::SetColor(const glm::vec3& color)
{
	this->color = color;
}

const glm::vec3& Light::GetTranslation() const
{
    return model->GetTranslate();
}
void Light::SetTranslation(const glm::vec3& translation)
{
    return model->SetTranslate(translation);
}


void Light::SetModelName(std::string name)
{
    this->model->modelName = name;
}
