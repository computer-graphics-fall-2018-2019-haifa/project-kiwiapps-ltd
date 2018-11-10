#pragma once
#define _USE_MATH_DEFINES

#include "ImguiMenus.h"
#include "MeshModel.h"
#include "Utils.h"
#include <cmath>
#include <memory>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <nfd.h>
#include <random>
#include <GLFW/glfw3.h>

static const int mainMenuWidth = 400;


bool addCameraWindow = false;
bool addCameraWindowResult = false;
static glm::vec3 eye = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 at = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 up = glm::vec3(0.0f, 0.0f, 0.0f);


bool showDemoWindow = false;

bool showAnotherWindow = false;

bool drawNormalVertex = false;
bool drawNormalFace = false;

glm::vec4 clearColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.00f);

const glm::vec4& GetClearColor()
{
	return clearColor;
}

void DrawImguiMenus(ImGuiIO& io, Scene& scene, GLFWwindow* window)
{
	// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	if (showDemoWindow)
	{
		ImGui::ShowDemoWindow(&showDemoWindow);
	}

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
        int display_w = 0 , display_h = 0;
        glfwPollEvents();
        glfwGetFramebufferSize( window , &display_w , &display_h );
        
        ImGui::Begin("", 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove );
        ImGui::SetWindowSize(ImVec2((float)mainMenuWidth, (float)display_h - 22));
        ImGui::SetWindowPos(ImVec2(2, 20));
        
        ImGui::Checkbox("Demo Window", &showDemoWindow);
        ImGui::Text("OBJ settings:");
        ImGui::Checkbox("Draw OBJ normal-per-vertex", &drawNormalVertex);
        ImGui::Checkbox("Draw OBJ normal-per-face", &drawNormalFace);
        ImGui::Text("");
        
        
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	// 3. Show another simple window.
	if (showAnotherWindow)
	{
		ImGui::Begin("Another Window", &showAnotherWindow);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
		{
			showAnotherWindow = false;
		}
		ImGui::End();
	}

	// 4. Demonstrate creating a fullscreen menu bar and populating it.
	{
//        ImGuiWindowFlags flags = ImGuiWindowFlags_NoFocusOnAppearing;
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Load Model...", "CTRL+O"))
				{
					nfdchar_t *outPath = NULL;
					nfdresult_t result = NFD_OpenDialog("obj;png,jpg", NULL, &outPath);
					if (result == NFD_OKAY) {
                        printf("Load_Model obj Loaded\n");
						scene.AddModel(std::make_shared<MeshModel>(Utils::LoadMeshModel(outPath)));
						free(outPath);
					}
					else if (result == NFD_CANCEL) {
                        printf("Load_Model canceled\n");
					}
					else {
                        printf("Load_Model Failed to Error\n");
					}

				}
                if (ImGui::MenuItem("Exit", "CTRL+Q")){
                    glfwSetWindowShouldClose(window, true);
                }
				ImGui::EndMenu();
			}
            if (ImGui::BeginMenu("Insert"))
            {
                if (ImGui::MenuItem("New Camera"))
                {
                    addCameraWindow = true;
                }
                ImGui::EndMenu();
            }
			ImGui::EndMainMenuBar();
		}
	}
    
    
    if(addCameraWindow) ShowAddCameraMenu();
    else {
        if(addCameraWindowResult){
            addCameraWindowResult = false;
            const Camera* camera = new Camera(eye, at, up);
            scene.AddCamera(*camera);
        }
        eye = glm::vec3(0.0f, 0.0f, 0.0f);
        at = glm::vec3(0.0f, 0.0f, 0.0f);
        up = glm::vec3(0.0f, 0.0f, 0.0f);
    }
}

void ShowAddCameraMenu() {

    ImGui::Begin("Add Camera", &addCameraWindow, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowPos(ImVec2(mainMenuWidth+10, 20));
    
    ImGui::BeginGroup();
    
    ImGui::Text("Add new camera to the scene, please specify the camera eye, at, up position:\n\n");
    
    BuildVectorInput("Eye position: (", "##eyeX", "##eyeY", "##eyeZ", eye);
    BuildVectorInput("At position:  (", "##ayX", "##atY", "##atZ", at);
    BuildVectorInput("Up position:  (", "##upX", "##upY", "##upZ", up);


    if (ImGui::Button("Cancel")){
        addCameraWindow = false;
        addCameraWindowResult = false;
        eye = glm::vec3(0.0f, 0.0f, 0.0f);
        at = glm::vec3(0.0f, 0.0f, 0.0f);
        up = glm::vec3(0.0f, 0.0f, 0.0f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Add")){
        addCameraWindow = false;
        addCameraWindowResult = true;
    }
    
    ImGui::EndGroup();
    ImGui::End();
}

void BuildVectorInput(const char* title, const char* xId, const char* yId, const char* zId, glm::vec3& vector){
    
    ImGui::Text(title);
    ImGui::PushItemWidth(80);
    ImGui::SameLine(); ImGui::InputFloat(xId, &vector[0]);
    ImGui::SameLine(); ImGui::Text(",");
    ImGui::SameLine(); ImGui::InputFloat(yId, &vector[1]);
    ImGui::SameLine(); ImGui::Text(",");
    ImGui::SameLine(); ImGui::InputFloat(zId, &vector[2]);
    ImGui::SameLine(); ImGui::Text(")");
    ImGui::PopItemWidth();
}
