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
public:
	Scene();

    int activeCameraIndex;
    int activeModelIndex;
    
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
    const std::vector<std::shared_ptr<MeshModel>> GetAllModels() const;
    const std::shared_ptr<MeshModel> GetModelByIndex(int index) const;
    
    // Lights functions
    void AddLight(Light* light);
    const int GetLightsCount() const;
    const Light& GetLightByIndex(int index);
    std::vector<Light*> GetAllLights() const;
    
    
//    glm::mat4 CalculateTransformationMatrix() const;
    
};
