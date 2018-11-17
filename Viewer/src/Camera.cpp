#define _USE_MATH_DEFINES
#include <math.h>
#include "Camera.h"
#include "Utils.h"
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Camera::Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) :
eye(eye),
at(at),
up(up),
projectionType(0),
zoom(1.0),
aspectRatio(1),
nearP(20),
fovy(0),
farP(500),
height(2),
model(MeshModel(Utils::LoadMeshModel("/Users/davidantoon/git/project-kiwiapps-ltd/Data/camera.obj")))
{
	SetCameraLookAt(eye, at, up);
}

Camera::~Camera()
{
}

void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) 
{
    SetCameraLookAt(eye, at, up, 1.0);
}
void Camera::SetCameraLookAt(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up, float zoom)
{
    // https://www.dropbox.com/s/9e8fqucirrwcgng/TranformationsAgain.pptx?dl=0#
    // page 64
    // lookAt() with vec3 instead of vec4
    
    SetZoom(zoom);
    this->eye = eye;
    this->at = at;
    this->up = up;

    glm::vec4 z  =  normalize(glm::vec4(eye, 1)  - glm::vec4(at, 1));
    glm::vec3 z3 = glm::vec3(z.x, z.y, z.z);
    glm::vec3 x3 = glm::normalize(glm::cross(up, z3));
    glm::vec3 y3 = glm::normalize(glm::cross(z3, z3));
    
    glm::vec4 x  =  glm::vec4(x3, 1);
    glm::vec4 y  =  glm::vec4(y3, 1);
    glm::vec4 t  =  glm::vec4(0.0, 0.0, 0.0, 1.0);
    glm::mat4 c  =  glm::mat4(x,  y,  z,  t);
    
    glm::mat4 traslateMat = glm::mat4(1, 0, 0, 0,
                                      0, 1, 0, 0,
                                      0, 0, 1, 0,
                                      -eye[0],-eye[1],-eye[2], 1);
    
    this->viewTransformation = c *  traslateMat;
}


void Camera::SetOrthographicProjection()
{
    SetOrthographicProjection(this->height, this->aspectRatio, this->nearP, this->farP);
}

void Camera::SetOrthographicProjection(
	const float height,
	const float aspectRatio,
	const float near,
	const float far)
{
    this->height = height;
    this->aspectRatio = aspectRatio;
    this->nearP = near;
    this->farP = far;
    this->projectionType = 0;
    
    
}

void Camera::SetPerspectiveProjection()
{
    SetPerspectiveProjection(this->fovy, this->aspectRatio, this->nearP, this->farP);
}

void Camera::SetPerspectiveProjection(
	const float fovy,
	const float aspectRatio,
	const float near,
	const float far)
{
    this->fovy = fovy;
    this->aspectRatio = aspectRatio;
    this->nearP = near;
    this->farP = far;
    this->projectionType = 1;
    
    float nearHeight = (far - near) * tan(fovy * M_PI);
    float nearWidth = nearHeight * aspectRatio;
    
    float top = near * nearHeight;
    float bottom = -top;
    float right = near * nearWidth;
    float left = -right;
    
    glm::vec4 r1 = glm::vec4((2 * near) / nearWidth, 0, (right + left) / (right - left), 0);
    glm::vec4 r2 = glm::vec4(0, -(2 * near) / nearHeight, (top + bottom) / (top - bottom), 0);
    glm::vec4 r3 = glm::vec4(0, 0, -(far + near) / (far - near), -(2 * far * near) / (far - near));
    glm::vec4 r4 = glm::vec4(0, 0, -1, 0);
    glm::mat4 matrix = glm::mat4(r1, r2, r3, r4);
    this->projectionTransformation = matrix;
}

const float Camera::GetZoom()
{
    return this->zoom;
}
void Camera::SetZoom(const float zoom)
{
    this->zoom = zoom;
}

const glm::mat4 Camera::GetTransformation()
{
    return this->viewTransformation;
}
const glm::mat4 Camera::GetProjection()
{
    return this->projectionTransformation;
}

const glm::vec3 Camera::GetEye()
{
    return this->eye;
}
const glm::vec3 Camera::GetAt()
{
    return this->at;
}
const glm::vec3 Camera::GetUp()
{
    return this->up;
}
const float Camera::GetAspectRatio()
{
    return this->aspectRatio;
}
const float Camera::GetNear()
{
    return this->nearP;
}
const float Camera::GetFovy()
{
    return this->fovy;
}
const float Camera::GetFar()
{
    return this->farP;
}
const float Camera::GetHeight()
{
    return this->height;
}
const float Camera::GetProjectionType()
{
    return this->projectionType;
}
const MeshModel Camera::GetModel()
{
    return this->model;
}

