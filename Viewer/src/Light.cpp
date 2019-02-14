#include "Light.h"
#include "ImguiMenus.h"
#include "Utils.h"
#include <vector>
#include <iostream>

Light::Light():
color(glm::vec3(1.0, 1.0, 1.0))
{
    this->model = std::make_shared<MeshModel>(MeshModel(Utils::LoadMeshModel(GetLightPath())));
}

Light::~Light()
{
}

const glm::vec3& Light::GetColor() const
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
