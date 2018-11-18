#define GLM_ENABLE_EXPERIMENTAL
#define _USE_MATH_DEFINES
#include <math.h>
#include "MeshModel.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

MeshModel::MeshModel(const std::vector<Face>& faces, const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& textures, const std::string& modelName) :
faces(faces),
vertices(vertices),
normals(normals),
textures(textures),
scale({ 1,1,1}),
rotate({ 0,0,0 }),
translate({ 0,0,0 }),
visibilityOptions({ 0,0,0 }),
worldTransform(glm::mat4x4(1)),
modelName(modelName)
{
    CalculateBoundingBox();
    color = glm::vec4(0);
    color.x = static_cast<float>(rand()) / RAND_MAX / 1.2; // dark colors
    color.y = static_cast<float>(rand()) / RAND_MAX / 1.2;
    color.z = static_cast<float>(rand()) / RAND_MAX / 1.2;
    color.w = 1.0f;
}

MeshModel::~MeshModel()
{
}

void MeshModel::CalculateBoundingBox()
{
    float minX = GetMin(0);
    float minY = GetMin(1);
    float minZ = GetMin(2);
    
    float maxX = GetMax(0);
    float maxY = GetMax(1);
    float maxZ = GetMax(2);
    
    this->boundingBox.clear();
    
    //  square 1
    //      maxX, maxY, minZ -> maxX, minY, minZ
    //      maxX, maxY, minZ -> minX, maxY, minZ
    //      maxX, maxY, minZ -> maxX, minY, minZ
    //      maxX, maxY, minZ -> minX, maxY, minZ
    
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(maxX, minY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(minX, maxY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(maxX, minY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(minX, maxY, minZ)));
    
    //  square 2
    //      maxX, maxY, maxZ -> maxX, minY, maxZ
    //      maxX, maxY, maxZ -> minX, maxY, maxZ
    //      maxX, maxY, maxZ -> maxX, minY, maxZ
    //      maxX, maxY, maxZ -> minX, maxY, maxZ
    
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, maxZ), glm::vec3(maxX, minY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, maxZ), glm::vec3(minX, maxY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, maxZ), glm::vec3(maxX, minY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, maxZ), glm::vec3(minX, maxY, maxZ)));
    
    // connect square 1 and 2
    //      minX, minY, minZ -> minX, minY, maxZ
    //      maxX, minY, minZ -> maxX, minY, maxZ
    //      minX, maxY, minZ -> minX, maxY, maxZ
    //      maxX, maxY, minZ -> maxX, maxY, maxZ
    
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, minZ), glm::vec3(minX, minY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, minY, minZ), glm::vec3(maxX, minY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(minX, maxY, minZ), glm::vec3(minX, maxY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(maxX, maxY, maxZ)));
}


// public methods:


const std::string& MeshModel::GetModelName()
{
    return modelName;
}

const float MeshModel::GetMin(int type)
{
    std::vector<float> allV;
    for(auto const& v: this->vertices) {
        allV.push_back(v[type]);
    }
    return *min_element(std::begin(allV), std::end(allV)); // c++11
}

const float MeshModel::GetMax(int type)
{
    std::vector<float> allV;
    for(auto const& v: this->vertices) {
        allV.push_back(v[type]);
    }
    return *max_element(std::begin(allV), std::end(allV)); // c++11
}

const std::vector<glm::vec3> MeshModel::GetVertices() const
{
    return this->vertices;
}

const std::vector<glm::vec3>& MeshModel::GetNormals() const
{
    return this->normals;
}

const std::vector<Face>& MeshModel::GetFaces() const
{
    return this->faces;
}

const glm::vec3 MeshModel::CalculateFaceNormal(Face face) const
{
    int vXIndex = face.GetVertexByIndex(0);
    int vYIndex = face.GetVertexByIndex(1);
    int vZIndex = face.GetVertexByIndex(2);
    
    glm::vec3 vertex1 = GetVertexByIndex(vXIndex);
    glm::vec3 vertex2 = GetVertexByIndex(vYIndex);
    glm::vec3 vertex3 = GetVertexByIndex(vZIndex);
    
    glm::vec3 ver1 = vertex2 - vertex1;
    glm::vec3 ver2 = vertex3 - vertex1;
    
    return cross(ver1, ver2);
}

const glm::vec3 MeshModel::GetVertexByIndex(int index) const
{
    return this->vertices[index];
}

const glm::vec3 MeshModel::GetNormalByIndex(int index) const
{
	return this->normals[index];
}


const std::vector<Line> MeshModel::GetBoundingBox() const
{
    return this->boundingBox;
}

const glm::mat4 MeshModel::CalculateWorldTransformation()
{
    glm::mat4 translateionMatrix = CalculateTranslationMatrix();
    glm::mat4 scaleMatrix = CalculateScaleMatrix();
    glm::mat4 rotationMatrix = CalculateRotationMatrix();
    
    this->worldTransform = glm::transpose(translateionMatrix) * scaleMatrix * rotationMatrix;
    
    return this->worldTransform;
}

const glm::mat4x4& MeshModel::GetWorldTransformation() const
{
	return this->worldTransform;
}

void MeshModel::SetColor(const glm::vec4& color)
{
	this->color = color;
}

const glm::vec4& MeshModel::GetColor() const
{
	return color;
}

const glm::vec3& MeshModel::GetScale() const
{
    return this->scale;
}
void MeshModel::SetScale(const glm::vec3& scale)
{
    this->scale = scale;
}

const glm::vec3& MeshModel::GetRotate() const
{
    return this->rotate;
}
void MeshModel::SetRotate(const glm::vec3& rotate)
{
    this->rotate = rotate;
}

const glm::vec3& MeshModel::GetTranslate() const
{
    return this->translate;
}
void MeshModel::SetTranslate(const glm::vec3& translate)
{
    this->translate = translate;
}

const glm::vec3 & MeshModel::GetVisibilityOptions()
{
	return this->visibilityOptions;
}

void MeshModel::SetVcisibilityOptions(const glm::vec3 & visibilityOptions)
{
	this->visibilityOptions = visibilityOptions;
}

glm::mat4 MeshModel::CalculateScaleMatrix()
{
	return glm::scale(this->scale);
}

glm::mat4 MeshModel::CalculateTranslationMatrix()
{
    return glm::mat4(1, 0, 0, translate.x,
                     0, 1, 0, translate.y,
                     0, 0, 1, translate.z,
                     0, 0, 0, 1
                     );
}

glm::mat4 MeshModel::CalculateRotationMatrix()
{
	float xRotation = this->rotate.x * M_PI / 180,
		  yRotation = this->rotate.y * M_PI / 180,
		  zRotation = this->rotate.z * M_PI / 180;

	glm::mat4 xRotationMatrix = glm::mat4(
		1, 0				  , 0						  , 0,
		0, glm::cos(xRotation), glm::sin(xRotation) * (-1), 0,
		0, glm::sin(xRotation), glm::cos(xRotation)		  , 0,
		0, 0				  , 0						  , 1
	);

	glm::mat4 yRotationMatrix = glm::mat4(
		glm::cos(yRotation), 0, glm::sin(yRotation), 0,
		0				   , 1, 0				   , 0,
		glm::sin(yRotation) * (-1), 0, glm::cos(yRotation), 0,
		0						  , 0, 0				  , 1
	);
	glm::mat4 zRotationMatirx = glm::mat4(
		glm::cos(zRotation), glm::sin(zRotation) * (-1), 0, 0,
		glm::sin(zRotation), glm::cos(zRotation)	   , 0, 0,
		0				   , 0						   , 1, 0,
		0				   , 0						   , 0, 1
	);

	return xRotationMatrix * yRotationMatrix * zRotationMatirx;
}



