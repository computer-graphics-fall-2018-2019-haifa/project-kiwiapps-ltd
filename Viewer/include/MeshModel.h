#pragma once
#include <glm/glm.hpp>
#include <string>
#include <memory>
#include "Face.h"
#include "Line.h"
#include <glm/gtc/matrix_transform.hpp>

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
    std::vector<Line> boundingBox;
    
	glm::mat4x4 worldTransform;
	std::string modelName;

    void CalculateBoundingBox();

public:
	MeshModel(const std::vector<Face>& faces, const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& textures, const std::string& modelName = "");
	virtual ~MeshModel();
    const std::string& GetModelName();

    // set public to change it by ref
    bool boundingBoxVisibility;
    bool verticesNoramlVisibility;
    bool faceNoramlVisibility;
    glm::vec4 color;
    // scale, rotate, translate
    glm::vec3 scale;
    glm::vec3 rotate;
    glm::vec3 translate;
    
    //get minimum index value in all the verticses
    // 0 -> x, 1 -> y, 2 -> z
    const float GetMin(int type);
    //get maximum  value in all the vertices
    // 0 -> x, 1 -> y, 2 -> z
    const float GetMax(int type);
    
    const std::vector<glm::vec3> GetVertices() const;
    const std::vector<glm::vec3>& GetNormals() const;
    const std::vector<Face>& GetFaces() const;
    const glm::vec3 CalculateFaceNormal(Face face) const;
    const glm::vec3 GetVertexByIndex(int index) const;
    const glm::vec3 GetNormalByIndex(int index) const;
    const std::vector<Line> GetBoundingBox() const;
    
    const glm::mat4 CalculateWorldTransformation();
    
    // getter setters
	const glm::mat4x4& GetWorldTransformation() const;

	const glm::vec4& GetColor() const;
	void SetColor(const glm::vec4& color);
    
    const glm::vec3& GetScale() const;
    void SetScale(const glm::vec3& scale);
    
    const glm::vec3& GetRotate() const;
    void SetRotate(const glm::vec3& rotate);
    
    const glm::vec3& GetTranslate() const;
    void SetTranslate(const glm::vec3& translate);

	glm::mat4 CalculateScaleMatrix();
	glm::mat4 CalculateTranslationMatrix();
	glm::mat4 CalculateRotationMatrix();

};
