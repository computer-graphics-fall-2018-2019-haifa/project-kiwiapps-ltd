#include "Scene.h"
#include "MeshModel.h"
#include <string>

Scene::Scene() :
	activeCameraIndex(-1),
	activeModelIndex(-1)
{
}

void Scene::AddModel(const std::shared_ptr<MeshModel>& model)
{
	models.push_back(model);
    activeModelIndex = models.size() - 1;
}

const int Scene::GetModelCount() const
{
	return models.size();
}

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
	// implementation suggestion...
	if (index >= 0 && index < cameras.size())
	{
		activeCameraIndex = index;
	}
}

const int Scene::GetActiveCameraIndex() const
{
	return activeCameraIndex;
}

void Scene::SetActiveModelIndex(int index)
{
	// implementation suggestion...
	if (index >= 0 && index < models.size())
	{
		activeModelIndex = index;
	}
}

const int Scene::GetActiveModelIndex() const
{
	return activeModelIndex;
}

std::vector<Camera*> Scene::GetAllCameras() const
{
    return cameras;
}

const std::vector<std::shared_ptr<MeshModel>> Scene::GetAllModels() const
{
    return models;
}

std::vector<Light*> Scene::GetAllLights() const
{
    return lights;
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
const Camera& Scene::GetActiveCamera() {
    return *cameras.at(activeCameraIndex);
}

const std::shared_ptr<MeshModel> Scene::GetModelByIndex(int index) const
{
    if(index >= 0 && index < models.size())
    {
        return models.at(index);
    } else {
        std::cerr << "Failed to get model, please check index " << index << std::endl;
        throw "Failed to get model, please check index " + std::to_string(index);
    }
}


glm::mat4 Scene::CalculateTransformationMatrix() const
{
    Camera* camera = this->cameras.at(activeCameraIndex);
    camera->SetCameraLookAt();

    glm::mat4
        projectionTrans = camera->GetProjection(),
        viewTrans = camera->GetTransformation();

//        worldTrans = camera->CalculateWorldTransformation();
//        worldTrans = glm::mat4(1);
    
    return projectionTrans * viewTrans;
}


