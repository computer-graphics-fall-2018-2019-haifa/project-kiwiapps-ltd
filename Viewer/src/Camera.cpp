#define GLM_ENABLE_EXPERIMENTAL
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "Camera.h"
#include "Utils.h"
#include <vector>
#include <iostream>
#include "ImguiMenus.h"

Camera::Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float aspectRatio) :
projectionType(1),
zoom(1.0f),
eye(eye),
at(at),
up(up),
aspectRatio(aspectRatio),
nearP(0.1f),
fovy(glm::pi<float>() / 4.0f),
farP(200.0f),
height(5)
{
    this->model = std::make_shared<MeshModel>(Utils::LoadMeshModel(GetCameraPath()));
    
    CalculateProjectionMatrix();
    SetCameraLookAt(eye, at, up);
}

Camera::~Camera()
{
}

const glm::mat4 Camera::GetViewTransformation() const
{
    return viewTransformation;
}

const glm::mat4 Camera::GetProjectionTransformation()  const
{
    return projectionTransformation;
}

void Camera::SetOrthographicProjection(const float height, const float aspectRatio, const float nearP, const float farP)
{
    this->height = height;
    this->aspectRatio = aspectRatio;
    this->nearP = nearP;
    this->farP = farP;
    this->projectionType = 0;
    float zoomHight = height * zoom;
    float width = aspectRatio * zoomHight;
    projectionTransformation = glm::ortho(-width / 2, width / 2, -zoomHight / 2, zoomHight / 2, nearP, farP);
}

void Camera::SetPerspectiveProjection(const float fovy, const float aspectRatio, const float nearP, const float farP)
{
    this->fovy = fovy;
    this->aspectRatio = aspectRatio;
    this->nearP = nearP;
    this->farP = farP;
    this->projectionType = 1;
    float zoomFovy = fovy * zoom;
    zoomFovy = zoomFovy > glm::pi<float>() ? glm::pi<float>() : zoomFovy;
    projectionTransformation = glm::perspective(zoomFovy, aspectRatio, nearP, farP);
}

void Camera::CalculateProjectionMatrix()
{
    if (this->projectionType == 0) {
        SetOrthographicProjection(height, aspectRatio, nearP, farP);
    } else {
        SetPerspectiveProjection(fovy, aspectRatio, nearP, farP);
    }
}

void Camera::SwitchToOrthographic()
{
    this->projectionType = 0;
}

void Camera::SwitchToPrespective()
{
    this->projectionType = 1;
}

const float Camera::GetProjectionType()
{
    return this->projectionType;
}

std::shared_ptr<MeshModel> Camera::GetModel()
{
    return this->model;
}

void Camera::SetModelName(std::string name)
{
    this->model->modelName = name;
}

void Camera::SetCameraLookAt()
{
    SetCameraLookAt(eye, at, up, zoom);
}
void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) 
{
    SetCameraLookAt(eye, at, up, zoom);
}
void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float zoom)
{
    // display the camera model inversed to look at
    model->CalculateInverseWorldTransformation();
    this->viewTransformation = glm::lookAt(eye, at, up);
}

const float Camera::GetZoom()
{
    return this->zoom;
}
void Camera::SetZoom(const float zoom)
{
    this->zoom = this->zoom * zoom;
    CalculateProjectionMatrix();
}


const float Camera::GetAspectRatio()
{
    return aspectRatio;
}
void Camera::SetAspectRatio(const float aspectRatio)
{
    this->aspectRatio = aspectRatio;
    CalculateProjectionMatrix();
}
