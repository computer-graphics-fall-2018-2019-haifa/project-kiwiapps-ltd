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


bool showDemoWindow = false;
bool showAnotherWindow = false;
bool drawNormalVertex = false;
bool drawNormalFace = false;

glm::vec4 clearColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.00f);

// pages
bool aboutPageVisible = false;
bool settingsPageVisible = false;
bool newCameraPageVisible = false;

// configurations
bool displayFPSConfig = false;
bool displayAxesConfig = true;
bool displaySelectedModelOnlyConfig = false;
int projectionTypeConfig = 0;
float incrementalSizeConfig = 1.0f;
std::string cameraObjPath = "";

// new camera page
bool newCameraResult = false;
static glm::vec3 eye = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 at = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 up = glm::vec3(0.0f, 0.0f, 0.0f);


const glm::vec4& GetClearColor()
{
	return clearColor;
}

void DisplayAlertCameraObj(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("Welcome to MeshModel Viewer", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowSize(ImVec2(std::min(400, display_w), std::min(300, display_h)));
    ImGui::SetWindowPos(ImVec2((display_w - std::min(400, display_w))/2, 100));
    ImGui::Text("Assigment No. : 1");
    ImGui::Text("");
    ImGui::Text("Students:");
    ImGui::Text("   - David Antoon (204489470)");
    ImGui::Text("   - Ameer Dow    (203844956)");
    ImGui::Text("");
    
    ImGui::Text("In order to start the Viewer, please choose the \nCamera Model object file path:\n(you can always change it by going to File -> Settings)");
    ImGui::Text("");
    if(ImGui::Button("Browse")){
        nfdchar_t *outPath = NULL;
        nfdresult_t result = NFD_OpenDialog("obj;", NULL, &outPath);
        if (result == NFD_OKAY) {
            printf("DisplayAlertCameraObj() camera obj Loaded\n");
            cameraObjPath = outPath;
            free(outPath);
        }
    }
    ImGui::End();
}

void buildMainMenu(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("", 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove );
    ImGui::SetWindowSize(ImVec2((float)mainMenuWidth, (float)display_h - 22));
    ImGui::SetWindowPos(ImVec2(2, 20));
    
    ImGui::Checkbox("Demo Window", &showDemoWindow);
    ImGui::Text("OBJ settings:");
    ImGui::Checkbox("Draw OBJ normal-per-vertex", &drawNormalVertex);
    ImGui::Checkbox("Draw OBJ normal-per-face", &drawNormalFace);
    ImGui::Text("");
    
    ImGui::End();
}

void BuildToolbar(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("About", ""))
            {
                aboutPageVisible = true;
            }
            if (ImGui::MenuItem("Settings", ""))
            {
                settingsPageVisible = true;
            }
            if (ImGui::MenuItem("Exit", "CTRL+Q"))
            {
                glfwSetWindowShouldClose(window, true);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Insert"))
        {
            if (ImGui::MenuItem("Load model from file"))
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
            if (ImGui::MenuItem("New camera"))
            {
                newCameraPageVisible = true;
            }
            if (ImGui::BeginMenu("New PrimMesh Model"))
            {
                ImGui::MenuItem("Cube");
                ImGui::MenuItem("Pyramid");
                ImGui::MenuItem("Sphere");
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View"))
        {
            ImGui::MenuItem("Display FPS", "", &displayFPSConfig);
            ImGui::MenuItem("Display Axes", "", &displayAxesConfig);
            ImGui::MenuItem("Display only selected Model", "", &displaySelectedModelOnlyConfig);
            
            if (ImGui::BeginMenu("Projection Type", ""))
            {
                if(ImGui::MenuItem("Orthographic", "" , projectionTypeConfig == 0))
                {
                    projectionTypeConfig = 0;
                    Camera* camera = scene.GetAllCameras().at(scene.GetActiveCameraIndex());
                    camera->SetOrthographicProjection();
                }
                if(ImGui::MenuItem("Perspective", "" , projectionTypeConfig == 1)) {
                    projectionTypeConfig = 1;
                    Camera* camera = scene.GetAllCameras().at(scene.GetActiveCameraIndex());
                    camera->SetPerspectiveProjection();
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void BuildAboutPage(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("About", &aboutPageVisible, ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(300, 200));
    ImGui::SetWindowPos(ImVec2((display_w - 300)/2, 100));
    
    ImGui::Text("");
    ImGui::Text("Assigment No. : 1");
    ImGui::Text("");
    ImGui::Text("Students:");
    ImGui::Text("   - David Antoon (204489470)");
    ImGui::Text("   - Ameer Dow    (203844956)");
    ImGui::Text("");
    
    ImGui::End();
}

void BuildSettingsPage(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("Settings", &settingsPageVisible, ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(std::min(600, display_w), std::min(300, display_h)));
    ImGui::SetWindowPos(ImVec2((display_w - std::min(600, display_w))/2, 100));
    ImGui::Text("Background color:");
    ImGui::ColorEdit3("", (float*) &clearColor);
    ImGui::Text("Step size of incremental:");
    ImGui::SliderFloat("", &incrementalSizeConfig, 0.1f, 5.0f);
    ImGui::Text("Camera Path: %s", cameraObjPath.c_str());
    if(ImGui::Button("Choose Camera.obj path")){
        nfdchar_t *outPath = NULL;
        nfdresult_t result = NFD_OpenDialog("obj;", NULL, &outPath);
        if (result == NFD_OKAY) {
            printf("BuildSettingsPage() camera obj Loaded\n");
            cameraObjPath = outPath;
            free(outPath);
        }
    }
    ImGui::End();
}

void DisplayFPSPage(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("FPS Stats", &displayFPSConfig, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowSize(ImVec2(200, 70));
    ImGui::SetWindowPos(ImVec2(display_w - 200, display_h - 70));
    ImGui::Text("FPS : %.1f", ImGui::GetIO().Framerate);
    ImGui::Text("Time: %.3f (ms/frame)", 1000.0f / ImGui::GetIO().Framerate);
    ImGui::End();
}

void BuildVectorInput(const char* title, const char* xId, const char* yId, const char* zId, glm::vec3& vector)
{
    ImGui::Text("%s", title);
    ImGui::PushItemWidth(80);
    ImGui::SameLine(); ImGui::InputFloat(xId, &vector[0]);
    ImGui::SameLine(); ImGui::Text(",");
    ImGui::SameLine(); ImGui::InputFloat(yId, &vector[1]);
    ImGui::SameLine(); ImGui::Text(",");
    ImGui::SameLine(); ImGui::InputFloat(zId, &vector[2]);
    ImGui::SameLine(); ImGui::Text(")");
    ImGui::PopItemWidth();
}

void DisplayAddNewCamera(ImGuiIO& io, Scene& scene, GLFWwindow* window, int display_w, int display_h)
{
    if(newCameraResult){
        newCameraPageVisible = false;
        newCameraResult = false;
        Camera* camera = new Camera(eye, at, up);
        scene.AddCamera(camera);
        return;
    }
    

    ImGui::Begin("Add New Camera", &newCameraPageVisible, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowPos(ImVec2(mainMenuWidth+10, 20));
    
    ImGui::BeginGroup();
    
    ImGui::Text("Add new camera to the scene, please specify the camera eye, at, up position:\n\n");
    
    BuildVectorInput("Eye position: (", "##eyeX", "##eyeY", "##eyeZ", eye);
    BuildVectorInput("At position:  (", "##ayX", "##atY", "##atZ", at);
    BuildVectorInput("Up position:  (", "##upX", "##upY", "##upZ", up);
    
    
    if (ImGui::Button("Cancel")){
        newCameraPageVisible = false;
        newCameraResult = false;
        eye = glm::vec3(0.0f, 0.0f, 0.0f);
        at = glm::vec3(0.0f, 0.0f, 0.0f);
        up = glm::vec3(0.0f, 0.0f, 0.0f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Add")){
        newCameraResult = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Random")){
        eye = glm::vec3((static_cast<float>(rand())/RAND_MAX) * 200, (static_cast<float>(rand())/RAND_MAX) * 200, (static_cast<float>(rand())/RAND_MAX) * 200);
        at = glm::vec3(0.0f);
        up = glm::vec3(0.0f, 1.0f, 0.0f);
        newCameraResult = true;
    }
    
    ImGui::EndGroup();
    ImGui::End();
}

void DrawImguiMenus(ImGuiIO& io, Scene& scene, GLFWwindow* window)
{
    int display_w = 0 , display_h = 0;
    glfwPollEvents();
    glfwGetFramebufferSize( window , &display_w , &display_h);
    
    if(cameraObjPath == "")
    {
        DisplayAlertCameraObj(io, scene, window, display_w, display_h);
        return;
    }
    
    BuildToolbar(io, scene, window, display_w, display_h);
    buildMainMenu(io, scene, window, display_w, display_h);
    if(aboutPageVisible) BuildAboutPage(io, scene, window, display_w, display_h);
    if(settingsPageVisible) BuildSettingsPage(io, scene, window, display_w, display_h);
    if(displayFPSConfig) DisplayFPSPage(io, scene, window, display_w, display_h);
    if(newCameraPageVisible) DisplayAddNewCamera(io, scene, window, display_w, display_h);
    if(showDemoWindow) ImGui::ShowDemoWindow(&showDemoWindow);
    
}


const std::string GetCameraPath()
{
    return cameraObjPath;
}

const bool ShouldDisplayAxes()
{
    return displayAxesConfig;
}
