#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>
#include "MeshModel.h"
#include "Camera.h"
#include "Light.h"

/*
 * Scene class.
 * This class holds all the scene information (models, cameras, lights, etc..)
 */
class Scene {
private:
	std::vector<std::shared_ptr<MeshModel>> models;
	std::vector<Camera*> cameras;
    std::vector<Light*> lights;
    
    int activeCameraIndex;
    int activeModelIndex;
    int activeLightIndex;
public:
	Scene();

    // Camera functions
    void AddCamera(Camera* camera);
	const int GetCameraCount() const;
	void SetActiveCameraIndex(int index);
	const int GetActiveCameraIndex() const;
    const Camera& GetCameraByIndex(int index);
    const Camera& GetActiveCamera();
    std::vector<Camera*> GetAllCameras() const;
    
    // Model functions
    void AddModel(const std::shared_ptr<MeshModel>& model);
    const int GetModelCount() const;
	void SetActiveModelIndex(int index);
	const int GetActiveModelIndex() const;
    const std::shared_ptr<MeshModel> GetModelByIndex(int index);
    const std::shared_ptr<MeshModel> getActiveModel();
    const std::vector<std::shared_ptr<MeshModel>> GetAllModels() const;
    
    // Lights functions
    void AddLight(Light* light);
    const int GetLightsCount() const;
    void SetActiveLightIndex(int index);
    const int GetActiveLightIndex() const;
    const Light& GetLightByIndex(int index);
    const Light& GetActiveLight();
    std::vector<Light*> GetAllLights() const;
    
//    glm::mat4 CalculateTransformationMatrix() const;
    
};
