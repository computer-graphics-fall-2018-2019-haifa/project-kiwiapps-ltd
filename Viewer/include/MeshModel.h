#pragma once
#include <glm/glm.hpp>
#include <string>
#include <memory>
#include "Face.h"

/*
 * MeshModel class.
 * This class represents a mesh model (with faces and normals informations).
 * You can use Utils::LoadMeshModel to create instances of this class from .obj files.
 */
class MeshModel
{
private:
	std::vector<Face> faces;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
    std::vector<glm::vec2> textures;
    std::vector<glm::vec3> boundingBox;
	glm::mat4x4 worldTransform;
	glm::vec4 color;
	std::string modelName;
    //get minimum index value in all the verticses
    // 0 -> x, 1 -> y, 2 -> z
    const float GetMin(int index);
    //get maximum  value in all the vertices
    // 0 -> x, 1 -> y, 2 -> z
    const float GetMax(int index);

public:
	MeshModel(const std::vector<Face>& faces, const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& textures, const std::string& modelName = "");
	virtual ~MeshModel();

	void SetWorldTransformation(const glm::mat4x4& worldTransform);
	const glm::mat4x4& GetWorldTransformation() const;

	const glm::vec4& GetColor() const;
	void SetColor(const glm::vec4& color);

	const std::string& GetModelName();

    const glm::vec3 CalculateFaceNormal(Face face);
    const glm::vec3 GetVertexByIndex(int index);
    const std::vector<glm::vec3> CalculateBoundingBox();

	// Add more methods/functionality as needed...
};
