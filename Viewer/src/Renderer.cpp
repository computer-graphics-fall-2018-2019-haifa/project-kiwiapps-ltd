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
    
    
    colorShader.use();
    
    for (std::shared_ptr<MeshModel> model : models) {
        
        // Set the uniform variables
        colorShader.setUniform("model", model->GetWorldTransformation() * model->CalculateTranslationMatrix());
        colorShader.setUniform("view", activeCamera.GetViewTransformation());
        colorShader.setUniform("projection", activeCamera.GetProjectionTransformation());
        colorShader.setUniform("material.textureMap", 0);
        
        // Set 'texture1' as the active texture at slot #0
        texture1.bind(0);
        
        // Drag our model's faces (triangles) in fill mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(model->GetVAO());
        glDrawArrays(GL_TRIANGLES, 0, model->GetAllVertex().size());
        glBindVertexArray(0);
        
        // Unset 'texture1' as the active texture at slot #0
        texture1.unbind(0);
        
        colorShader.setUniform("color", glm::vec3(0,0,0));
        
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
    colorShader.loadShaders("vshader_color.glsl", "fshader_color.glsl");
}

void Renderer::LoadTextures()
{
    if (GetTexturePath() != "" && !texture1.loadTexture(GetTexturePath(), true))
    {
        texture1.loadTexture(GetTexturePath(), true);
    }
}
