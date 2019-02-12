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
    
	void AddModel(const std::shared_ptr<MeshModel>& model);
	const int GetModelCount() const;

    void AddCamera(Camera* camera);
	const int GetCameraCount() const;
    
    void AddLight(Light * light);
    
	void SetActiveCameraIndex(int index);
	const int GetActiveCameraIndex() const;

	void SetActiveModelIndex(int index);
	const int GetActiveModelIndex() const;

    std::vector<Camera*> GetAllCameras() const;
    const std::vector<std::shared_ptr<MeshModel>> GetAllModels() const;
    
    const Camera& GetCameraByIndex(int index);
    const Camera& GetActiveCamera();
    const std::shared_ptr<MeshModel> GetModelByIndex(int index) const;
    
    glm::mat4 CalculateTransformationMatrix() const;
    
};
