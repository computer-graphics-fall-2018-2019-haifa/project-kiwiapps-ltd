#pragma once
#include <imgui/imgui.h>
#include "Scene.h"
#include "imgui_impl_glfw.h"

void DrawImguiMenus(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window);
const glm::vec4& GetClearColor();
void BuildVectorInput(const char* title, const char* xId, const char* yId, const char* zId, glm::vec3& vector);

const std::string GetCameraPath();
const std::string GetLightPath();
const std::string GetTexturePath();
const bool ShouldDisplayAxes();
const bool ShouldSelectOnlyActiveModel();
