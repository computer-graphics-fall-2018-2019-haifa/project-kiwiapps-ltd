#pragma once
#include <memory>
#include <iostream>
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
    // 0 => orth , 1 => perspective
    int projectionType;
    float zoom;
    
	glm::mat4x4 viewTransformation;
	glm::mat4x4 projectionTransformation;
    std::shared_ptr<MeshModel> model;

public:
    Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float aspectRatio);
	~Camera();
    
    glm::vec3 eye;
    glm::vec3 at;
    glm::vec3 up;
    float aspectRatio;
    float nearP;
    float fovy;
    float farP;
    float height;

    const glm::mat4 GetViewTransformation();
    const glm::mat4 GetProjectionTransformation();
    
    void SetOrthographicProjection(const float height, const float aspectRatio, const float nearP, const float farP);
    void SetPerspectiveProjection(const float fovy, const float aspectRatio, const float nearP, const float farP);
    
    void CalculateProjectionMatrix();
    void SwitchToOrthographic();
    void SwitchToPrespective();
    const float GetProjectionType();
    
    std::shared_ptr<MeshModel> GetModel();
    void SetModelName(std::string name);
    
    void SetCameraLookAt();
	void SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up);
	void SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float zoom);
    
    const float GetZoom();
    void SetZoom(const float zoom);

};
