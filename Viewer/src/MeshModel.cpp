#include "MeshModel.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

MeshModel::MeshModel(const std::vector<Face>& faces, const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& textures, const std::string& modelName) :
faces(faces),
vertices(vertices),
normals(normals),
textures(textures),
worldTransform(glm::mat4x4(1)),
modelName(modelName),
scale({ 1,1,1 }),
rotate({ 0,0,0 }),
translate({ 0,0,0 }),
visibilityOptions({ 0,0,0 })
{
}

MeshModel::~MeshModel()
{
    
}

void MeshModel::SetWorldTransformation(const glm::mat4x4& worldTransform)
{
	this->worldTransform = worldTransform;
}

const glm::mat4x4& MeshModel::GetWorldTransformation() const
{
	return worldTransform;
}

void MeshModel::SetColor(const glm::vec4& color)
{
	this->color = color;
}

const glm::vec4& MeshModel::GetColor() const
{
	return color;
}

const std::string& MeshModel::GetModelName()
{
	return modelName;
}

const glm::vec3 MeshModel::CalculateFaceNormal(Face face){
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

const glm::vec3 MeshModel::GetVertexByIndex(int index){
    return this->vertices[index];
}

const float MeshModel::GetMin(int type){
    std::vector<float> allV;
    for(auto const& v: this->vertices) {
        allV.push_back(v[type]);
    }
    return *min_element(std::begin(allV), std::end(allV)); // c++11
}

const float MeshModel::GetMax(int type){
    std::vector<float> allV;
    for(auto const& v: this->vertices) {
        allV.push_back(v[type]);
    }
    return *max_element(std::begin(allV), std::end(allV)); // c++11
}

std::vector<Line> MeshModel::CalculateBoundingBox(){
    float minX = GetMin(0);
    float minY = GetMin(1);
    float minZ = GetMin(2);
    
    float maxX = GetMax(0);
    float maxY = GetMax(1);
    float maxZ = GetMax(2);

    this->boundingBox.clear();
    
    // store drawing lines instead of points

    
    // TODO: change every line to push_back directly
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, minZ), glm::vec3(minX, maxY, minZ)));
    
	addLine(glm::vec3(minX, minY, minZ), glm::vec3(minX, maxY, minZ));
	addLine(glm::vec3(minX, minY, minZ), glm::vec3(maxX, minY, minZ));
	addLine(glm::vec3(minX, minY, minZ), glm::vec3(minX, minY, maxZ));

	addLine(glm::vec3(minX, maxY, minZ), glm::vec3(minX, maxY, maxZ));
	addLine(glm::vec3(minX, maxY, minZ), glm::vec3(maxX, maxY, minZ));

	addLine(glm::vec3(maxX, minY, minZ), glm::vec3(maxX, maxY, minZ));
	addLine(glm::vec3(maxX, minY, minZ), glm::vec3(maxX, maxY, maxZ));

	addLine(glm::vec3(maxX, minY, maxZ), glm::vec3(maxX, maxY, maxZ));
	addLine(glm::vec3(maxX, minY, maxZ), glm::vec3(minX, minY, maxZ));

	addLine(glm::vec3(maxX, maxY, maxZ), glm::vec3(maxX, maxY, minZ));
	addLine(glm::vec3(maxX, maxY, maxZ), glm::vec3(minX, maxY, maxZ));
	
	addLine(glm::vec3(minX, maxY, maxZ), glm::vec3(minX, minY, maxZ));

    return this->boundingBox;
}



void MeshModel::addLine(glm::vec3& p1, glm::vec3& p2) {
	this->boundingBox.push_back(Line(p1, p2));
}








