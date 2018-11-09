#define _USE_MATH_DEFINES

#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Camera::Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) :
	zoom(1.0)
{
	SetCameraLookAt(eye, at, up);
}

Camera::~Camera()
{
}

void Camera::SetTransformation(const glm::mat4x4 & transform)
{
}

void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) 
{
	SetZoom(1.0);
	glm::vec3 z = normalize(eye - at);
	glm::vec3 x = normalize(cross(up, z));
	glm::vec3 y = normalize(cross(z, x));
}
void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float zoom)
{
	SetZoom(zoom);
	glm::vec3 z = normalize(eye - at);
	glm::vec3 x = normalize(cross(up, z));
	glm::vec3 y = normalize(cross(z, x));

}

void Camera::SetProjection(const glm::mat4x4 & projection)
{
}

void Camera::SetOrthographicProjection(
	const float height,
	const float aspectRatio,
	const float near,
	const float far)
{

}

void Camera::SetPerspectiveProjection(
	const float fovy,
	const float aspectRatio,
	const float near,
	const float far)
{

}

void Camera::SetZoom(const float zoom)
{
	this->zoom = zoom;
}