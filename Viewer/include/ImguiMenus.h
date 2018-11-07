#pragma once
#include <imgui/imgui.h>
#include "Scene.h"
#include "imgui_impl_glfw.h"

void DrawImguiMenus(ImGuiIO& io, Scene& scene, GLFWwindow* window);
const glm::vec4& GetClearColor();
