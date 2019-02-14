#define _USE_MATH_DEFINES

#include "Renderer.h"
#include "InitShader.h"
#include "MeshModel.h"
#include "ShaderProgram.h"
#include "ImguiMenus.h"
#include <imgui/imgui.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

#define INDEX(width,x,y,c) ((x)+(y)*(width))*3+(c)

Renderer::Renderer()
{
    
}
Renderer::~Renderer()
{
    
}
//
//void Renderer::putPixel(int i, int j, const glm::vec3& color)
//{
//    if (i < 0) return; if (i >= viewportWidth) return;
//    if (j < 0) return; if (j >= viewportHeight) return;
//    colorBuffer[INDEX(viewportWidth, i, j, 0)] = color.x;
//    colorBuffer[INDEX(viewportWidth, i, j, 1)] = color.y;
//    colorBuffer[INDEX(viewportWidth, i, j, 2)] = color.z;
//}
//
//void Renderer::createBuffers(int viewportWidth, int viewportHeight)
//{
//    if (colorBuffer)
//    {
//        delete[] colorBuffer;
//    }
//
//    colorBuffer = new float[3* viewportWidth * viewportHeight];
//    for (int x = 0; x < viewportWidth; x++)
//    {
//        for (int y = 0; y < viewportHeight; y++)
//        {
//            putPixel(x, y, glm::vec3(0.0f, 0.0f, 0.0f));
//        }
//    }
//}
//
//void Renderer::ClearColorBuffer(const glm::vec3& color)
//{
//    for (int i = 0; i < viewportWidth; i++)
//    {
//        for (int j = 0; j < viewportHeight; j++)
//        {
//            putPixel(i, j, color);
//        }
//    }
//}

//void Renderer::DrawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color)
//{
//    // Bresenham’s Line Drawing Algorithm
//
//    // init points per vec
//    int x0 = p1.x;
//    int y0 = p1.y;
//    int x1 = p2.x;
//    int y1 = p2.y;
//
//    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
//    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
//    int err = (dx>dy ? dx : -dy)/2, e2;
//
//    while(true){
//        putPixel(x0,y0, color);
//        if (x0==x1 && y0==y1) break;
//        e2 = err;
//        if (e2 >-dx) { err -= dy; x0 += sx; }
//        if (e2 < dy) { err += dx; y0 += sy; }
//    }
//}

//
//glm::vec3 Renderer::MultiplyMatVec3(glm::mat4 mat, glm::vec3 vec3)
//{
//    glm::vec4 vec4 = mat * glm::vec4(vec3, 1);
//    if (vec4.w == 0){
//        vec4.w = 1;
//    }
//    return glm::vec3(vec4.x / vec4.w, vec4.y / vec4.w, vec4.z / vec4.w);
//}
//
//glm::vec3 halfAxesV3Global = glm::vec3(0);
//
//void Renderer::DrawLine(const Line& line, glm::mat4& transMatrix, const glm::vec3& color)
//{
//    glm::vec3 p1 = MultiplyMatVec3(transMatrix, line.point1) + halfAxesV3Global;
//    glm::vec3 p2 = MultiplyMatVec3(transMatrix, line.point2) + halfAxesV3Global;
//    DrawLine(p1, p2, color);
//}
//
//// draw triangle by calling drawLine foreach rib
//void Renderer::DrawTriangle(const std::vector<glm::vec3>& vertices, glm::mat4& transMatrix, const glm::vec3& color)
//{
//    if(vertices.size() != 3){
//        throw "Triangle must have three vertices";
//    }
//
//    DrawLine(Line(vertices[0], vertices[1]), transMatrix, color);
//    DrawLine(Line(vertices[0], vertices[2]), transMatrix, color);
//    DrawLine(Line(vertices[1], vertices[2]), transMatrix, color);
//}
//
//void Renderer::DrawFaceNormal(const std::vector<glm::vec3>& vertices, glm::mat4& transformMatrix)
//{
//    glm::vec3
//        mid = (vertices[0] + vertices[1] + vertices[2]) / glm::vec3(3, 3, 3),
//        normal = glm::cross((vertices[1] - vertices[0]), (vertices[2] - vertices[0])),
//        startPoint = mid - (normal * glm::vec3(0.2)),
//        endPoint = mid + (normal * glm::vec3(2));
//
//    Line line = Line(startPoint, endPoint);
//    DrawLine(line, transformMatrix, glm::vec3(1, 0, 0));
//}
//
//// draw each line by the provided transformation matrix
//void Renderer::DrawModelBoundingBox(MeshModel* model, glm::mat4 transformMatrix) {
//    std::vector<Line> boundingBox = model->GetBoundingBox();
//
//    for(int i=0; i<boundingBox.size(); i++)
//    {
//        DrawLine(boundingBox.at(i), transformMatrix, glm::vec3(1, 0, 0));
//    }
//}

//
// loop over model faces
// build face vertics from model vertices positions
// draw bounding box
void Renderer::DrawModel(std::shared_ptr<MeshModel> model, const std::shared_ptr<Scene>& scene) {
    glm::mat4 modelMat = model->GetWorldTransformation();
    
    // Set the uniform variables
    colorShader.setUniform("model", modelMat);
    colorShader.setUniform("material.color", model->color);
//    colorShader.setUniform("useTexture", model->useTexture);

//    if (model->fill) {
//        // Set the model's texture as the active texture at slot #0
//        model->BindTexture();
//
//        // Drag our model's faces (triangles) in fill mode
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glBindVertexArray(model->GetVAO());
//        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)model->GetModelVertices().size());
//        glBindVertexArray(0);
//
//        // Unset the model's texture as the active texture at slot #0
//        model->UnbindTexture();
//    }
    
//    if (model->showWire) {
        // Drag our model's faces (triangles) in line mode (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(model->GetVAO());
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)model->GetAllVertex().size());
        glBindVertexArray(0);
//    }
    
//    // get model faces
//    // get model vertics
//    // get model normals
//    // get model color by checking if is active model -> green else darkGray
//
//    std::vector<Face> faces = model->GetFaces();
//    std::vector<glm::vec3> vertices = model->GetVertices();
//    std::vector<glm::vec3> normals = model->GetNormals();
//
//    // call draw bounding box if requested
//    if (model->boundingBoxVisibility) {
////        DrawModelBoundingBox(model, transformMatrix);
//    }
//
//    // loop over faces and draw each face by calling the DrawFace function
//        // use the provided transformMatrix when drawing the Faces
//        // check if draw face normals requested
//
//    for (int i = 0; i < faces.size(); i++) {
//        std::vector<glm::vec3> vertices;
//        Face face = faces.at(i);
//        for(int j=0; j<3; j++){
//            vertices.push_back(model->GetVertexByIndex(face.GetVertexByIndex(j) - 1));
//        }
//
//        if (model->faceNoramlVisibility == 1) {
////            DrawFaceNormal(vertices, transformMatrix);
//        }
//        if(model->verticesNoramlVisibility) {
//
//        }
////        DrawTriangle(vertices, transformMatrix, model->GetColor());
//    }
}

void Renderer::Render(const std::shared_ptr<Scene>& scene, GLFWwindow* window)
{
    if (!scene->GetCameraCount()) {
        return;
    }
    
    std::vector<std::shared_ptr<MeshModel> > models = scene->GetAllModels();
    std::vector<Camera*> cameras = scene->GetAllCameras();
    std::vector<Light*> lights = scene->GetAllLights();
    
    Camera activeCamera = scene->GetActiveCamera();
    glm::mat4 viewMat = activeCamera.GetTransformation();
    glm::mat4 objMat = activeCamera.CalculateWorldTransformation();
    glm::mat4 projMat = activeCamera.GetProjection();
    glm::vec4 lightColors[5] = { glm::vec4(0) };
    glm::vec4 lightLocations[5] = { glm::vec4(0) };
    
    for (int i = 0; i < 5; i++) {
        if (i < lights.size()) {
            Light* light = lights.at(i);
            lightColors[i] = glm::vec4(light->GetColor(), 1);
//            lightLocations[i] = glm::vec4(light->GetLocation(), 1);
        }
    }
    
    colorShader.use();
    
    // camera params
    colorShader.setUniform("view", viewMat * objMat);
    colorShader.setUniform("projection", projMat);
    colorShader.setUniform("lightColors", *lightColors);
    colorShader.setUniform("lightLocations", *lightLocations);
    
    // draw models
    for (std::shared_ptr<MeshModel> model : models) {
        model->CalculateWorldTransformation();
        DrawModel(model, scene);
    }
    
    // draw cameras
    std::logic_error("need to check this!!! maybe change the impl remove inherit");
    for (int i = 0; i < scene->GetCameraCount(); i++) {
        if (scene->activeCameraIndex == i)
            continue;
        std::shared_ptr<MeshModel> cameraModel = cameras.at(i)->GetModel();
        cameraModel->scale = glm::vec3(0.1);
        cameraModel->CalculateWorldTransformation();
        //TODO: Draw Camera
        DrawModel(cameraModel, scene);
    }
    
    //TODO : Draw lights
}

void Renderer::LoadShaders()
{
    colorShader.loadShaders("vshader_color.glsl", "fshader_color.glsl");
}

void Renderer::LoadTextures()
{
    if (GetTexturePath() != "" && !texture1.loadTexture(GetTexturePath(), true))
    {
        texture1.loadTexture(GetTexturePath(), true);
    }
}
