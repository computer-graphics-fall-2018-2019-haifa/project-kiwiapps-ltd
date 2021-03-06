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
scale({ 1,1,1 }),
rotate({ 0,0,0 }),
translate({ 0,0,0 }),
worldTransform(glm::mat4x4(1)),
boundingBoxVisibility(false),
verticesNoramlVisibility(false),
faceNoramlVisibility(false),
modelName(modelName),
textureEnabled(false),
ambientColor(0.5f),
diffuseColor(0.7f),
specularColor(0.2f)
{
    //init openGL vertex
    //need to check !!!!
    modelVertices.reserve(3 * faces.size());
    for (Face face : faces) {
        for (int i = 0; i < 3; i++)
        {
            Vertex vertex;
            int vertexIndex = face.GetVertexByIndex(i) - 1;
            
            vertex.position = vertices[vertexIndex];
            vertex.normal = normals[vertexIndex];
            
            if (textures.size() > 0)
            {
                int textureCoordsIndex = face.GetTextureIndex(i) - 1;
                vertex.textureCoords = textures[textureCoordsIndex];
            } else {
                vertex.textureCoords = {0, 0};
            }
            
            modelVertices.push_back(vertex);
        }
    }
    
    CalculateBoundingBox();
    color = glm::vec4(0);
    color.x = static_cast<float>(rand()) / RAND_MAX / 1.2; // dark colors
    color.y = static_cast<float>(rand()) / RAND_MAX / 1.2;
    color.z = static_cast<float>(rand()) / RAND_MAX / 1.2;
    color.w = 1.0f;
    
    
    initializeOpenGL();
    CalculateWorldTransformation();
}


void MeshModel::initializeOpenGL() {
    //GL stuff
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, modelVertices.size() * sizeof(Vertex), &modelVertices[0], GL_STATIC_DRAW);
    
    // load vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    // load normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    // load textures
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    
    // unbind
    glBindVertexArray(0);
    
    
    
    //bounding box gen
    glGenVertexArrays(1, &boundingBoxVao);
    glBindVertexArray(boundingBoxVao);
    
    glGenBuffers(1, &boundingBoxVbo);
    glBindBuffer(GL_ARRAY_BUFFER, boundingBoxVbo);
    glBufferData(GL_ARRAY_BUFFER, boundingBox.size() * sizeof(Vertex), &boundingBox[0], GL_STATIC_DRAW);
    
    // load vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    
    // load normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    
    // load textures
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoords));
    
    // unbind
    glBindVertexArray(0);
}


MeshModel::~MeshModel()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void MeshModel::CalculateBoundingBox()
{
    float minX = GetMin(0);
    float minY = GetMin(1);
    float minZ = GetMin(2);
    
    float maxX = GetMax(0);
    float maxY = GetMax(1);
    float maxZ = GetMax(2);
    
    
    
    Vertex v0, v1, v2, v3, v4, v5, v6, v7;
    v0.normal = v0.position = glm::vec3(minX, minY, minZ); // left low close 0
    v1.normal = v1.position = glm::vec3(maxX, minY, minZ); // right low close 1
    v2.normal = v2.position = glm::vec3(minX, maxY, minZ); // left high close 2
    v3.normal = v3.position = glm::vec3(maxX, maxY, minZ); // right high close 3
    v4.normal = v4.position = glm::vec3(minX, minY, maxZ); // left low far 4
    v5.normal = v5.position = glm::vec3(maxX, minY, maxZ); // right low far 5
    v6.normal = v6.position = glm::vec3(minX, maxY, maxZ); // left high far 6
    v7.normal = v7.position = glm::vec3(maxX, maxY, maxZ); // right high far 7
    v0.textureCoords = v1.textureCoords = v2.textureCoords = v3.textureCoords = v4.textureCoords = v5.textureCoords = v6.textureCoords = v7.textureCoords = glm::vec2(0.0f, 0.0f);
    boundingBox.reserve(36);
    boundingBox.push_back(v0); boundingBox.push_back(v1); boundingBox.push_back(v3);
    boundingBox.push_back(v0); boundingBox.push_back(v1); boundingBox.push_back(v2);
    boundingBox.push_back(v1); boundingBox.push_back(v3); boundingBox.push_back(v5);
    boundingBox.push_back(v1); boundingBox.push_back(v5); boundingBox.push_back(v7);
    boundingBox.push_back(v4); boundingBox.push_back(v5); boundingBox.push_back(v6);
    boundingBox.push_back(v5); boundingBox.push_back(v6); boundingBox.push_back(v7);
    boundingBox.push_back(v0); boundingBox.push_back(v2); boundingBox.push_back(v4);
    boundingBox.push_back(v2); boundingBox.push_back(v4); boundingBox.push_back(v6);
    boundingBox.push_back(v2); boundingBox.push_back(v3); boundingBox.push_back(v7);
    boundingBox.push_back(v2); boundingBox.push_back(v6); boundingBox.push_back(v7);
    boundingBox.push_back(v0); boundingBox.push_back(v1); boundingBox.push_back(v5);
    boundingBox.push_back(v0); boundingBox.push_back(v4); boundingBox.push_back(v5);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    this->boundingBox.clear();
    
    //  square 1
    //      minX, minY, minZ -> maxX, minY, minZ
    //      minX, minY, minZ -> minX, maxY, minZ
    //      maxX, maxY, minZ -> maxX, minY, minZ
    //      maxX, maxY, minZ -> minX, maxY, minZ
    
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, minZ), glm::vec3(maxX, minY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, minZ), glm::vec3(minX, maxY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(maxX, minY, minZ)));
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(minX, maxY, minZ)));
    
    //  square 2
    //      minX, minY, maxZ -> maxX, minY, maxZ
    //      minX, minY, maxZ -> minX, maxY, maxZ
    //      maxX, maxY, maxZ -> maxX, minY, maxZ
    //      maxX, maxY, maxZ -> minX, maxY, maxZ
    
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, maxZ), glm::vec3(maxX, minY, maxZ)));
    this->boundingBox.push_back(Line(glm::vec3(minX, minY, maxZ), glm::vec3(minX, maxY, maxZ)));
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
    this->boundingBox.push_back(Line(glm::vec3(maxX, maxY, minZ), glm::vec3(maxX, maxY, maxZ)));*/
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


const std::vector<Vertex> MeshModel::GetBoundingBox() const
{
    return this->boundingBox;
}

const glm::mat4 MeshModel::CalculateWorldTransformation()
{
    this->worldTransform =
        glm::transpose(Utils::CalculateTranslateMatrix(translate)) *
        Utils::CalculateRotateMatrix(rotate) *
        Utils::CalculateScaleMatrix(scale);
    
    return this->worldTransform;
}

const glm::mat4 MeshModel::CalculateInverseWorldTransformation()
{
    this->worldTransform = glm::inverse(CalculateWorldTransformation());
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


GLuint MeshModel::GetVAO() const{
    return this->vao;
}

GLuint MeshModel::GetVBO() const{
    return this->vbo;
}

const std::vector<Vertex>& MeshModel::GetAllVertex(){
    return this->modelVertices;
}


void MeshModel::LoadTexture(const char * path) {
    texture.loadTexture(path, true);
    textureEnabled = true;
}

void MeshModel::BindTexture() {
    texture.bind(0);
}

void MeshModel::UnbindTexture()
{
    texture.unbind(0);
}
