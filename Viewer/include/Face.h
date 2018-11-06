#pragma once
#include <memory>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <iostream>

class Face
{
private:
	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;
	std::vector<int> textureIndices;

public:
	Face(std::istream& issLine);
	virtual ~Face();
	const int GetVertexIndex(int index);
	const int GetNormalIndex(int index);
	const int GetTextureIndex(int index);
};
