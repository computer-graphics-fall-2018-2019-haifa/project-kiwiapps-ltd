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

Camera::Camera(const glm::vec3& eye, const glm::vec3& at, const glm::vec3& up) :
eye(eye),
at(at),
up(up),
projectionType(0),
zoom(1),
aspectRatio(1),
nearP(10),
fovy(45),
farP(1000),
height(2),
model(MeshModel(Utils::LoadMeshModel(GetCameraPath())))
{
	SetCameraLookAt(eye, at, up);
    SetOrthographicProjection();
    model.scale = {1, 1, 1};
}

Camera::~Camera()
{
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
    // https://www.dropbox.com/s/9e8fqucirrwcgng/TranformationsAgain.pptx?dl=0#
    // page 64
    // lookAt() with vec3 instead of vec4
    
    SetZoom(zoom);
    this->eye = eye;
    this->at = at;
    this->up = up;
    
//    up4 = rotationMatrix * up4;

    glm::vec4 z  =  normalize(glm::vec4(eye,1.0f)  - glm::vec4(at, eye.z));
    glm::vec3 z3 = glm::vec3(z.x, z.y, z.z);
    glm::vec3 x3 = glm::normalize(glm::cross(up, z3));
    glm::vec3 y3 = glm::normalize(glm::cross(z3, x3));
    
    glm::vec4 x  =  glm::vec4(x3, 1.0f);
    glm::vec4 y  =  glm::vec4(y3, 1.0f);
    glm::vec4 t  =  glm::vec4(0.0, 0.0, 0.0, 1.0);
    glm::mat4 c  =  glm::transpose(glm::mat4(x,  y,  z,  t));
    
    glm::mat4 translateEye = glm::translate(-eye);
    
    this->model.SetTranslate(eye);
    this->model.SetRotate(up);
    this->viewTransformation = c * translateEye * glm::scale(glm::vec3(zoom));
    
}


void Camera::SetOrthographicProjection()
{
    SetOrthographicProjection(this->height, this->aspectRatio, this->nearP, this->farP);
}

void Camera::SetOrthographicProjection(
	const float height,
	const float aspectRatio,
	const float nearP,
	const float farP)
{
    this->height = height;
    this->aspectRatio = aspectRatio;
    this->nearP = nearP;
    this->farP = farP;
    this->projectionType = 0;
    
    float nearWidth = height * aspectRatio;
    
    float top = 0.5 * height;
    float bottom = -top;
    float right = 0.5 * nearWidth;
    float left = -right;
    
//    this->projectionTransformation =
//    glm::mat4(
//       2 / (right - left)               , 0                                , 0                            , 0,
//       0                                , 2 / (top - bottom)               , 0                            , 0,
//       0                                , 0                                , 2 / (nearP - farP)             , 0,
//       -(right + left) / (right - left) , -(top + bottom) / (top - bottom) , -(farP + nearP) / (farP - nearP) , 1
//   );
    
    this->projectionTransformation = glm::ortho(left, right, bottom, top, nearP, farP);
}

void Camera::SetPerspectiveProjection()
{
    SetPerspectiveProjection(this->fovy, this->aspectRatio, this->nearP, this->farP);
}

void Camera::SetPerspectiveProjection(
	const float fovy,
	const float aspectRatio,
	const float nearP,
	const float farP)
{
    this->fovy = fovy;
    this->aspectRatio = aspectRatio;
    this->nearP = nearP;
    this->farP = farP;
    this->projectionType = 1;
    
    float nearHeight = (farP - nearP) * tan(fovy * M_PI / 180);
    float nearWidth = nearHeight * aspectRatio;
    
    float top = 0.5 * nearHeight;
//    float bottom = -top;
    float right = 0.5 * nearWidth;
//    float left = -right;
    
//    glm::vec4 r1 = glm::vec4((2 * nearP) / (right - left), 0, (right + left) / (right - left), 0);
//    glm::vec4 r2 = glm::vec4(0, (2 * nearP) / (top - bottom), (top + bottom) / (top - bottom), 0);
//    glm::vec4 r3 = glm::vec4(0, 0, -(farP + nearP) / (farP - nearP), -(2 * farP * nearP) / (farP - nearP));
//    glm::vec4 r4 = glm::vec4(0, 0, -1, 0);
    
//    glm::mat4 matrix = glm::mat4(r1, r2, r3, r4);
    glm::mat4 matrix = glm::perspective(fovy, aspectRatio, nearP, farP);
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

const glm::mat4 Camera::CalculateWorldTransformation()
{
    glm::mat4 scaleMat = glm::scale(glm::vec3(zoom));
    glm::mat4 rotateMat = CalculateRotationMatrix();
    glm::mat4 translateMat = glm::mat4(1, 0, 0, eye.x,
                                       0, 1, 0, eye.y,
                                       0, 0, 1, eye.z,
                                       0, 0, 0, 1
                                       );
    
    return glm::transpose(translateMat) * rotateMat * scaleMat;
}


const glm::mat4 Camera::CalculateRotationMatrix()
{
    glm::vec3 rotationAngle = glm::vec3(glm::angle(this->at, this->eye));
    glm::vec3 rotation = this->up * glm::vec3(M_PI / 180);
    
    glm::mat4 xRotationMatrix = glm::mat4(
                                          1, 0                   , 0                          , 0,
                                          0, glm::cos(rotation.x), glm::sin(rotation.x) * (-1), 0,
                                          0, glm::sin(rotation.x), glm::cos(rotation.x)       , 0,
                                          0, 0                   , 0                          , 1
                                          );
    
    glm::mat4 yRotationMatrix = glm::mat4(
                                          glm::cos(rotation.y)       , 0, glm::sin(rotation.y), 0,
                                          0                          , 1, 0                   , 0,
                                          glm::sin(rotation.y) * (-1), 0, glm::cos(rotation.y), 0,
                                          0                          , 0, 0                   , 1
                                          );
    glm::mat4 zRotationMatirx = glm::mat4(
                                          glm::cos(rotation.z), glm::sin(rotation.z) * (-1) , 0, 0,
                                          glm::sin(rotation.z), glm::cos(rotation.z)        , 0, 0,
                                          0                   , 0                           , 1, 0,
                                          0                   , 0                           , 0, 1
                                          );
    
    return xRotationMatrix * yRotationMatrix * zRotationMatirx;
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
MeshModel Camera::GetModel()
{
    return this->model;
}
void Camera::SetModelName(std::string name)
{
    this->model.modelName = name;
}
                                                             

