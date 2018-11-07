#include "Scene.h"
#include "MeshModel.h"
#include <string>

Scene::Scene() :
	activeCameraIndex(0),
	activeModelIndex(0)
{

}

void Scene::AddModel(const std::shared_ptr<MeshModel>& model)
{
	models.push_back(model);
}

const int Scene::GetModelCount() const
{
	return models.size();
}

void Scene::AddCamera(const Camera& camera)
{
	cameras.push_back(camera);
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

const std::vector<Camera> Scene::GetAllCameras() const
{
    return cameras;
}

const std::vector<std::shared_ptr<MeshModel>> Scene::GetAllModels() const
{
    return models;
}


const Camera Scene::GetCameraByIndex(int index) const
{
    if(index > 0 && index < cameras.size())
    {
        return cameras.at(index);
    } else {
        std::cerr << "Failed to get camera, please check index " << index << std::endl;
        throw "Failed to get camera, please check index " + std::to_string(index);
    }
}
const std::shared_ptr<MeshModel> Scene::GetModelByIndex(int index) const
{
    if(index > 0 && index < models.size())
    {
        return models.at(index);
    } else {
        std::cerr << "Failed to get model, please check index " << index << std::endl;
        throw "Failed to get model, please check index " + std::to_string(index);
    }
}






