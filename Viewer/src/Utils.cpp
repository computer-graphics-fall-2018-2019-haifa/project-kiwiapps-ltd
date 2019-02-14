#include "Utils.h"
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

glm::vec3 Utils::Vec3fFromStream(std::istream& issLine)
{
	float x, y, z;
	issLine >> x >> std::ws >> y >> std::ws >> z;
	return glm::vec3(x, y, z);
}

glm::vec2 Utils::Vec2fFromStream(std::istream& issLine)
{
	float x, y;
	issLine >> x >> std::ws >> y;
	return glm::vec2(x, y);
}

MeshModel Utils::LoadMeshModel(const std::string& filePath)
{
	std::vector<Face> faces;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
    std::vector<glm::vec2> textures;
	std::ifstream ifile(filePath.c_str());

	// while not end of file
	while (!ifile.eof())
	{
		// get line
		std::string curLine;
		std::getline(ifile, curLine);

		// read the type of the line
		std::istringstream issLine(curLine);
		std::string lineType;

		issLine >> std::ws >> lineType;

		// based on the type parse data
		if (lineType == "v")
		{
			vertices.push_back(Utils::Vec3fFromStream(issLine));
		}
		else if (lineType == "vn")
		{
			normals.push_back(Utils::Vec3fFromStream(issLine));
		}
		else if (lineType == "vt")
		{
            textures.push_back(Utils::Vec2fFromStream(issLine));
		}
		else if (lineType == "f")
		{
			faces.push_back(Face(issLine));
		}
		else if (lineType == "#" || lineType == "")
		{
			// comment / empty line
		}
		else
		{
			//std::cout << "Found unknown line Type \"" << lineType << "\"";
		}
	}

	return MeshModel(faces, vertices, normals, textures, Utils::GetFileName(filePath));
}



glm::mat4 Utils::CalculateScaleMatrix(const glm::vec3 scale)
{
    return glm::mat4(scale.x, 0, 0, 0,
                     0, scale.y, 0, 0,
                     0, 0, scale.z, 0,
                     0, 0, 0, 1);
}

glm::mat4 Utils::CalculateTranslateMatrix(const glm::vec3 translate)
{
    return glm::mat4(1, 0, 0, translate.x,
                     0, 1, 0, translate.y,
                     0, 0, 1, translate.z,
                     0, 0, 0, 1);
}

glm::mat4 Utils::CalculateRotateMatrix(const glm::vec3 rotate)
{
    glm::mat3 x, y, z;
    glm::vec3 rotatePI = rotate * glm::vec3(M_PI);
    
    x = glm::mat4(1, 0, 0, 0,
                      0, cos(rotatePI.x), -sin(rotatePI.x), 0,
                      0, sin(rotatePI.x),  cos(rotatePI.x), 0,
                      0, 0, 0, 1);
    y = glm::mat4(cos(rotatePI.y), 0,  sin(rotatePI.y), 0,
                      0, 1, 0, 0,
                      -sin(rotatePI.y), 0, cos(rotatePI.y), 0,
                      0, 0, 0, 1);
    z = glm::mat4(cos(rotatePI.z), -sin(rotatePI.z), 0, 0,
                      sin(rotatePI.z), cos(rotatePI.z),  0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 1);
    return x * y * z;
}

std::string Utils::GetFileName(const std::string& filePath)
{
	if (filePath.empty()) {
		return {};
	}

	auto len = filePath.length();
	auto index = filePath.find_last_of("/\\");

	if (index == std::string::npos) {
		return filePath;
	}

	if (index + 1 >= len) {

		len--;
		index = filePath.substr(0, len).find_last_of("/\\");

		if (len == 0) {
			return filePath;
		}

		if (index == 0) {
			return filePath.substr(1, len - 1);
		}

		if (index == std::string::npos) {
			return filePath.substr(0, len);
		}

		return filePath.substr(index + 1, len - index - 1);
	}

	return filePath.substr(index + 1, len - index);
}
