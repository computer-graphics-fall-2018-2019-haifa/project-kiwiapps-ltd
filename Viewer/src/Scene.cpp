#include "Scene.h"
#include "MeshModel.h"
#include <string>

Scene::Scene() :
	activeCameraIndex(-1),
	activeModelIndex(-1),
    activeLightIndex(-1)
{
}

Scene::~Scene(){

}


// Camera functions
void Scene::AddCamera(Camera* camera)
{
    cameras.push_back(camera);
    activeCameraIndex = cameras.size() - 1;
    
    for(int i=0; i < cameras.size(); i++){
        cameras.at(i)->SetModelName("Camera_" + std::to_string(i+1));
    }
}

const int Scene::GetCameraCount() const
{
    return cameras.size();
}

void Scene::SetActiveCameraIndex(int index)
{
    if (index >= 0 && index < cameras.size())
    {
        activeCameraIndex = index;
    }
}

const Camera& Scene::GetCameraByIndex(int index)
{
    if(index >= 0 && index < cameras.size())
    {
        return *cameras.at(index);
    } else {
        std::cerr << "Failed to get camera, please check index " << index << std::endl;
        throw "Failed to get camera, please check index " + std::to_string(index);
    }
}

const Camera& Scene::GetActiveCamera()
{
    return *cameras.at(activeCameraIndex);
}

std::vector<Camera*> Scene::GetAllCameras() const
{
    return cameras;
}


// Model functions
void Scene::AddModel(const std::shared_ptr<MeshModel>& model)
{
    models.push_back(model);
    activeModelIndex = models.size() - 1;
}

const int Scene::GetModelCount() const
{
    return models.size();
}

void Scene::SetActiveModelIndex(int index)
{
    if (index >= 0 && index < models.size())
    {
        activeModelIndex = index;
    }
}

const std::shared_ptr<MeshModel> Scene::GetModelByIndex(int index)
{
    if(index >= 0 && index < models.size())
    {
        return models.at(index);
    } else {
        std::cerr << "Failed to get model, please check index " << index << std::endl;
        throw "Failed to get model, please check index " + std::to_string(index);
    }
}

const std::shared_ptr<MeshModel> Scene::getActiveModel()
{
    return models.at(activeModelIndex);
}

const std::vector<std::shared_ptr<MeshModel>> Scene::GetAllModels() const
{
    return models;
}

// Lights functions
void Scene::AddLight(Light* light)
{
    lights.push_back(light);
    activeLightIndex = models.size() - 1;
    for(int i=0; i < lights.size(); i++){
        lights.at(i)->SetModelName("Light_" + std::to_string(i+1));
    }
}

const int Scene::GetLightsCount() const
{
    return lights.size();
}

void Scene::SetActiveLightIndex(int index)
{
    if (index >= 0 && index < lights.size())
    {
        activeLightIndex = index;
    }
}

const Light& Scene::GetLightByIndex(int index)
{
    if(index >= 0 && index < lights.size())
    {
        return *lights.at(index);
    } else {
        std::cerr << "Failed to get light, please check index " << index << std::endl;
        throw "Failed to get light, please check index " + std::to_string(index);
    }
}

const Light& Scene::GetActiveLight()
{
    return *lights.at(activeLightIndex);
}

std::vector<Light*> Scene::GetAllLights() const
{
    return lights;
}

glm::mat4 Scene::CalculateWorldTransformationMatrix() const
{
    Camera* camera = this->cameras.at(activeCameraIndex);
    camera->SetCameraLookAt();

    glm::mat4
        projectionTrans = camera->GetProjection(),
        viewTrans = camera->GetTransformation();

    return projectionTrans * viewTrans;
}


