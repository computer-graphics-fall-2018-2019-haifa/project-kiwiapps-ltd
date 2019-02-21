#include "Renderer.h"
#include "MeshModel.h"
#include "ShaderProgram.h"
#include "ImguiMenus.h"
#include <imgui/imgui.h>
#include <vector>
#include <memory>
#include <algorithm>

Renderer::Renderer()
{
}
Renderer::~Renderer()
{
    
}

void Renderer::Render(const std::shared_ptr<Scene>& scene, GLFWwindow* window)
{
    if (scene->GetCameraCount() < 1) {
        std::logic_error("No no Cameras loaded");
        return;
    }
    
    std::vector<std::shared_ptr<MeshModel>> models = scene->GetAllModels();
    std::vector<Camera*> cameras = scene->GetAllCameras();
    std::vector<Light*> lights = scene->GetAllLights();
    
    Camera activeCamera = scene->GetActiveCamera();
    
    glm::vec4 lightColors[20] = { glm::vec4(0) };
    glm::vec4 lightTranslations[20] = { glm::vec4(0) };
    
    for (int i = 0; i < 20; i++) {
        if (i < lights.size()) {
            Light* light = lights.at(i);
            lightColors[i] = glm::vec4(light->GetColor(), 1);
            lightTranslations[i] = glm::vec4(light->GetTranslation(), 1);
        }
    }

    
    colorShader.use();
    
    colorShader.setUniform("lightColors", lightColors);
    colorShader.setUniform("lightTranslations", lightTranslations);
    
    activeCamera.SetCameraLookAt();
    for (std::shared_ptr<MeshModel> model : models) {
        
        // Set the uniform variables
        colorShader.setUniform("model", model->GetWorldTransformation() * model->CalculateTranslationMatrix());
        colorShader.setUniform("view", activeCamera.GetViewTransformation());
        colorShader.setUniform("projection", activeCamera.GetProjectionTransformation());
        colorShader.setUniform("material.textureMap", 0);
        colorShader.setUniform("material.color", model->color);
        colorShader.setUniform("material.Ka", model->ambientColor);
        colorShader.setUniform("material.Kd", model->diffuseColor);
        colorShader.setUniform("material.Ks", model->specularColor);
        colorShader.setUniform("textureEnabled", model->textureEnabled);
        
        
        model->BindTexture();
        
        // Drag our model's faces (triangles) in fill mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(model->GetVAO());
        glDrawArrays(GL_TRIANGLES, 0, model->GetAllVertex().size());
        glBindVertexArray(0);
        
        model->UnbindTexture();
        
        colorShader.setUniform("color", model->color);

        // Drag our model's faces (triangles) in line mode (wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(model->GetVAO());
        glDrawArrays(GL_TRIANGLES, 0, model->GetAllVertex().size());
        glBindVertexArray(0);
    }
    
    // draw cameras
//    std::logic_error("need to check this!!! maybe change the impl remove inherit");
//    for (int i = 0; i < scene->GetCameraCount(); i++) {
//        if (scene->activeCameraIndex == i)
//            continue;
//        std::shared_ptr<MeshModel> cameraModel = cameras.at(i)->GetModel();
//        cameraModel->CalculateWorldTransformation();
//        // Draw Camera model
////        DrawModel(cameraModel, scene);
//    }
    
    //TODO : Draw lights
}

void Renderer::LoadShaders()
{
    colorShader.loadShaders("vshader.glsl", "fshader.glsl");
}
