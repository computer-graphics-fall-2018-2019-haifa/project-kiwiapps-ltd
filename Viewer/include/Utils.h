#pragma once
#include <glm/glm.hpp>
#include <string>
#include "MeshModel.h"

/*
 * Utils class.
 * This class is consisted of static helper methods that can have many clients across the code.
 */
class Utils
{
public:
	static glm::vec3 Vec3fFromStream(std::istream& issLine);
	static glm::vec2 Vec2fFromStream(std::istream& issLine);
    
    static std::vector<glm::vec3> CalculateNormals(std::vector<glm::vec3> vertices, std::vector<Face> faces);
    static std::shared_ptr<MeshModel> LoadMeshModelPointer(const std::string& filePath);

    static glm::mat4 CalculateScaleMatrix(const glm::vec3 scale);
    static glm::mat4 CalculateTranslateMatrix(const glm::vec3 translate);
    static glm::mat4 CalculateRotateMatrix(const glm::vec3 rotate);

private:
	static std::string GetFileName(const std::string& filePath);
};
