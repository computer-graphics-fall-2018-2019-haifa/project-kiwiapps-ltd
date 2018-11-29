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

// others
bool lockScale = true;
bool lockRotate = true;
bool lockTranslate = true;

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
    std::vector<std::shared_ptr<MeshModel>> models = scene.GetAllModels();
    std::vector<Camera*> cameras = scene.GetAllCameras();
    
    ImGui::Begin("", 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove );
    ImGui::SetWindowSize(ImVec2((float)mainMenuWidth, (float)display_h - 22));
    ImGui::SetWindowPos(ImVec2(2, 20));
    
    if(models.size() == 0){
        ImGui::Text("\n           *** No loaded models yet! ***\n");
        ImGui::Text("              Load model by going to \n            Insert -> Load model from file...\n");
        ImGui::Text("");
    } else if (ImGui::CollapsingHeader("Models")) {
        std::shared_ptr<MeshModel> activeModel = models.at(scene.activeModelIndex);
        char** modelNames = new char*[models.size()];
        for (int i = 0; i < models.size(); i++)
        {
            modelNames[i] = const_cast<char*>((*models[i]).GetModelName().c_str());
        }
        
        ImGui::Text("Selected Model:");
        ImGui::SameLine();
        ImGui::Combo("##selectedModel", &scene.activeModelIndex, modelNames, models.size());
        delete [] modelNames;
        
        
        ImGui::Text("Model Color:");
        ImGui::SameLine();
        ImGui::ColorEdit3("##modelColor", (float*)&(activeModel->color));
        
        ImGui::Text("Draw Options:");
        ImGui::Text("Draw Vertices Normals:");
        ImGui::SameLine();
        ImGui::Checkbox("##vn", &(activeModel->verticesNoramlVisibility));
        ImGui::Text("Draw Faces Normals:");
        ImGui::SameLine();
        ImGui::Checkbox("##fn", &(activeModel->faceNoramlVisibility));
        ImGui::Text("Draw Bounding Box:");
        ImGui::SameLine();
        ImGui::Checkbox("##boundBox", &(activeModel->boundingBoxVisibility));
        
        ImGui::Separator();
        
        ImGui::Text("Lock Scale:");
        ImGui::SameLine();
        ImGui::Checkbox("##lockScaleCheckbox", &lockScale);
        ImGui::Text("Scale X:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleX", &(activeModel->scale.x), 1.0f, 500.0f);
        ImGui::Text("Scale Y:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleY", &(activeModel->scale.y), 1.0f, 500.0f);
        ImGui::Text("Scale Z:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleZ", &(activeModel->scale.z), 1.0f, 500.0f);
    
        ImGui::Separator();
        
        ImGui::Text("Lock Rotate:");
        ImGui::SameLine();
        ImGui::Checkbox("##lockRotateCheckbox", &lockRotate);
        ImGui::Text("Rotate X:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockRotate ? "##lockedRotate" : "##RotateX", &(activeModel->rotate.x), -360.0f, 360.0f);
        ImGui::Text("Rotate Y:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockRotate ? "##lockedRotate" : "##RotateY", &(activeModel->rotate.y), -360.0f, 360.0f);
        ImGui::Text("Rotate Z:");
        ImGui::SameLine();
        ImGui::SliderFloat(lockRotate ? "##lockedRotate" : "##RotateZ", &(activeModel->rotate.z), -360.0f, 360.0f);
        
        ImGui::Separator();
    
        ImGui::Text("Translation X:");
        ImGui::SameLine();
        ImGui::SliderFloat("##TranslationX", &(activeModel->translate.x), -1000.0f, 1000.0f);
        ImGui::Text("Translation Y:");
        ImGui::SameLine();
        ImGui::SliderFloat("##TranslationY", &(activeModel->translate.y), -1000.0f, 1000.0f);
        ImGui::Text("Translation Z:");
        ImGui::SameLine();
        ImGui::SliderFloat("##TranslationZ", &(activeModel->translate.z), -1000.0f, 1000.0f);

    }
    
    
    if (ImGui::CollapsingHeader("Cameras")) {
        Camera* activeCamera = cameras.at(scene.activeCameraIndex);
        char** cameraNames = new char*[cameras.size()];
        for (int i = 0; i < cameras.size(); i++){
            cameraNames[i] = const_cast<char*>(cameras.at(i)->GetModel().GetModelName().c_str());
        }
        
        ImGui::Text("Selected Camera:");
        ImGui::SameLine();
        ImGui::Combo("##selectedCamera", &scene.activeCameraIndex, cameraNames, cameras.size());
        
        
        ImGui::Text("Zooming: ");
        ImGui::SameLine();
        ImGui::SliderFloat("##cameraZoom", &(activeCamera->zoom), 0.100f, 50.0f, "%.2f", 10.0f);
        activeCamera->SetCameraLookAt();
        
        bool isOrth = activeCamera->GetProjectionType() == 0;
        ImGui::SliderFloat(isOrth ? "Height": "Fovy", isOrth ? &(activeCamera->height) : &(activeCamera->fovy), 1.0f, 100.0f);
        ImGui::SliderFloat("Aspect Ratio", &(activeCamera->aspectRatio), 0.1f, 2.0f);
        ImGui::SliderFloat("Near", &(activeCamera->nearP), 1.0f, 1000.0f);
        ImGui::SliderFloat("Far", &(activeCamera->farP), 1.0f, 1000.0f);
        if(isOrth){
            activeCamera->SetOrthographicProjection();
        } else {
            activeCamera->SetPerspectiveProjection();
        }
        
        int colSize = ((mainMenuWidth - 82)/3)/3;
        ImGui::Text("\n|       Eye       |        Up       |        At       |");
        ImGui::Text(  "|   X    Y    Z   |   X    Y    Z   |   X    Y    Z   |\n");
        
        ImGui::PushID(0);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(200, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));

        ImGui::VSliderFloat("##eyeX", ImVec2(colSize, 100), &(activeCamera->eye.x), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##eyeY", ImVec2(colSize, 100), &(activeCamera->eye.y), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##eyeZ", ImVec2(colSize, 100), &(activeCamera->eye.z), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
        ImGui::PushID(1);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(0, 200, 0));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));
        ImGui::VSliderFloat("##upX", ImVec2(colSize, 100), &(activeCamera->up.x), -10,10, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##upY", ImVec2(colSize, 100), &(activeCamera->up.y), 0.1,10, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##upZ", ImVec2(colSize, 100), &(activeCamera->up.z), -10,10, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
        ImGui::PushID(2);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(0, 0, 200));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));
        ImGui::VSliderFloat("##atX", ImVec2(colSize, 100), &(activeCamera->at.x), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##atY", ImVec2(colSize, 100), &(activeCamera->at.y), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::VSliderFloat("##atZ", ImVec2(colSize, 100), &(activeCamera->at.z), -2000,2000, "%.0f", incrementalSizeConfig);
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
    }
    
    
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
        ImGui::MenuItem("Help", "", &showDemoWindow);
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
        up = glm::vec3(0.0f, 1.0f, 0.0f);
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

const bool ShouldSelectOnlyActiveModel()
{
    return displaySelectedModelOnlyConfig;
}
