#pragma once

#define GLM_ENABLE_EXPERIMENTAL 1
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
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
    glm::mat4 worldTransformation;
    
public:
	Scene();
    ~Scene();
    
    int activeCameraIndex;
    int activeModelIndex;
    int activeLightIndex;
    
    glm::vec3 scale;
    glm::vec3 rotate;
    glm::vec3 translate;
    
    // Camera functions
    void AddCamera(Camera* camera);
	const int GetCameraCount() const;
	void SetActiveCameraIndex(int index);
    const Camera& GetCameraByIndex(int index);
    const Camera& GetActiveCamera();
    std::vector<Camera*> GetAllCameras() const;
    
    // Model functions
    void AddModel(const std::shared_ptr<MeshModel>& model);
    const int GetModelCount() const;
	void SetActiveModelIndex(int index);
    const std::shared_ptr<MeshModel> GetModelByIndex(int index);
    const std::shared_ptr<MeshModel> getActiveModel();
    const std::vector<std::shared_ptr<MeshModel>> GetAllModels() const;
    
    // Lights functions
    void AddLight(Light* light);
    const int GetLightsCount() const;
    void SetActiveLightIndex(int index);
    const Light& GetLightByIndex(int index);
    const Light& GetActiveLight();
    std::vector<Light*> GetAllLights() const;
    
    void CalculateWorldTransformationMatrix();
    glm::mat4 GetWorldTransformationMatrix() const;
};
