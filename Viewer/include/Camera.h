#pragma once
#include <memory>
#include <glm/glm.hpp>
#include "MeshModel.h"

/*
 * Camera class. This class takes care of all the camera transformations and manipulations.
 *
 * Implementation suggestion:
 * --------------------------
 * Make the Camera class be a subclass of MeshModel, so you can easily and elegantly render 
 * the cameras you have added to the scene.
 */
class Camera
{
private:
    glm::vec3 eye;
    glm::vec3 at;
    glm::vec3 up;
    // 0 => orth , 1 => perspective
    int projectionType;

	glm::mat4x4 viewTransformation;
	glm::mat4x4 projectionTransformation;
	float zoom;
    float aspectRatio;
    float nearP;
    float fovy;
    float farP;
    float height;
    MeshModel model;

public:
	Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up);
	~Camera();

	void SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up);
	void SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float zoom);

    void SetOrthographicProjection();
	void SetOrthographicProjection(
		const float height,
		const float aspectRatio,
		const float nearP,
		const float farP);

    void SetPerspectiveProjection();
	void SetPerspectiveProjection(
		const float fovy,
		const float aspect,
		const float nearP,
		const float farP);

    const glm::mat4 GetTransformation();
    const glm::mat4 GetProjection();
    const glm::mat4 CalculateWorldTransformation();
    const glm::mat4 CalculateRotationMatrix();
    
    const float GetZoom();
    void SetZoom(const float zoom);
    
    const glm::vec3 GetEye();
    const glm::vec3 GetAt();
    const glm::vec3 GetUp();
    const float GetAspectRatio();
    const float GetNear();
    const float GetFovy();
    const float GetFar();
    const float GetHeight();
    const float GetProjectionType();
    MeshModel GetModel();
};
