#pragma once

#include "MeshModel.h"
#include <glm/glm.hpp>

class Light
{
private:
    glm::vec3 color;
    std::shared_ptr<MeshModel> model;
public:
	Light();
	virtual ~Light();

	const glm::vec3& GetColor()  const;
	void SetColor(const glm::vec3& color);
    const glm::vec3& GetTranslation() const;
    void SetTranslation(const glm::vec3& translation);
    
    void SetModelName(std::string name);
};
