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
bool displayFPSConfig = true;
bool displayAxesConfig = true;
bool displaySelectedModelOnlyConfig = false;
int projectionTypeConfig = 1;
float incrementalSizeConfig = 1.0f;

std::string cameraObjPath = "/Users/davidantoon/git/project-kiwiapps-ltd/Data/camera.obj";
std::string lightObjPath = "/Users/davidantoon/git/project-kiwiapps-ltd/Data/sphere.obj";

// new camera page
bool newCameraResult = false;
static glm::vec3 eye = glm::vec3(0.0f, 0.0f, 100.0f);
static glm::vec3 at = glm::vec3(0.0f, 0.0f, 0.0f);
static glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);

// others
bool lockScale = true;
bool lockRotate = true;
bool lockTranslate = true;

float cameraZoom = 1;

const glm::vec4& GetClearColor()
{
	return clearColor;
}

void DisplayAlertCameraObj(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("Welcome to MeshModel Viewer", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowSize(ImVec2(std::min(400, display_w), std::min(300, display_h)));
    ImGui::SetWindowPos(ImVec2((display_w - std::min(400, display_w))/2, 100));
    ImGui::Text("Assigment No. : 3");
    ImGui::Text("");
    ImGui::Text("Students:");
    ImGui::Text("   - David Antoon (204489470)");
    ImGui::Text("   - Ameer Dow    (203844956)");
    ImGui::Text("");
    
    ImGui::TextWrapped("In order to start the Viewer, you have to provide three objects: Camera, Light and Crate Texture, please choose the Camera Model object file path:\n\nNote: you can always change it by going to File -> Settings");
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

void DisplayAlertLightObj(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("Welcome to MeshModel Viewer", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowSize(ImVec2(std::min(600, display_w), std::min(300, display_h)));
    ImGui::SetWindowPos(ImVec2((display_w - std::min(600, display_w))/2, 100));
    ImGui::Text("Assigment No. : 3");
    ImGui::Text("");
    ImGui::Text("Students:");
    ImGui::Text("   - David Antoon (204489470)");
    ImGui::Text("   - Ameer Dow    (203844956)");
    ImGui::Text("");
    
    ImGui::TextWrapped("Selected Camera Path:\n\"%s\"\n", GetCameraPath().c_str());
    
    ImGui::TextWrapped("Please provide the light Model object file:");
    ImGui::TextWrapped("");
    if(ImGui::Button("Browse")){
        nfdchar_t *outPath = NULL;
        nfdresult_t result = NFD_OpenDialog("obj;", NULL, &outPath);
        if (result == NFD_OKAY) {
            printf("DisplayAlertLightObj() light obj Loaded\n");
            lightObjPath = outPath;
            free(outPath);
        }
    }
    ImGui::End();
}

void buildMainMenu(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    std::vector<std::shared_ptr<MeshModel>> models = scene->GetAllModels();
    std::vector<Camera*> cameras = scene->GetAllCameras();
	Camera* activeCamera = cameras.at(scene->activeCameraIndex);
    
    ImGui::Begin("", 0 , ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove );
    ImGui::SetWindowSize(ImVec2((float)mainMenuWidth, (float)display_h - 22));
    ImGui::SetWindowPos(ImVec2(2, 20));
    
    if(models.size() == 0){
        ImGui::Text("\n           *** No loaded models yet! ***\n");
        ImGui::Text("              Load model by going to \n            Insert -> Load model from file...\n");
        ImGui::Text("");
    } else if (ImGui::CollapsingHeader("Models") && models.size() > 0) {
        std::shared_ptr<MeshModel> activeModel = models.at(scene->activeModelIndex);
        char** modelNames = new char*[models.size()];
        for (int i = 0; i < models.size(); i++)
        {
            modelNames[i] = const_cast<char*>((*models[i]).GetModelName().c_str());
        }
        
        ImGui::Text("Selected Model:");
        ImGui::SameLine();
        ImGui::Combo("##selectedModel", &(scene->activeModelIndex), modelNames, models.size());
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
        
		if (ImGui::Button("Focus")) {
			activeCamera->at = activeModel->translate;
            activeCamera->SetCameraLookAt();
		}
        ImGui::Separator();
        
        if(activeModel->textureEnabled){
            if (ImGui::Button("Unload Texture")) {
                activeModel->textureEnabled = false;
            }
        } else {
            if (ImGui::Button("Load Texture")) {
                nfdchar_t *outPath = NULL;
                nfdresult_t result = NFD_OpenDialog("jpg,jpeg;", NULL, &outPath);
                if (result == NFD_OKAY) {
                    activeModel->LoadTexture(outPath);
                    free(outPath);
                }
            }
        }
        ImGui::Separator();
        
        bool changed = false;
        ImGui::Text("Lock Scale:");
        ImGui::SameLine();
        ImGui::Checkbox("##lockScaleCheckbox", &lockScale);
        if (lockScale) {
            if(ImGui::SliderFloat("Scale", &(activeModel->scale.x), 0.0f, 3.0f)){
                float x = activeModel->scale.x;
                activeModel->scale = { x, x, x };
                activeModel->CalculateWorldTransformation();
            }
        }
        else {
            ImGui::Text("Scale X:");
            ImGui::SameLine();
            if(ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleX", &(activeModel->scale.x), 0.0f, 3.0f))
            {
                changed = true;
            }
            ImGui::Text("Scale Y:");
            ImGui::SameLine();
            if(ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleY", &(activeModel->scale.y), 0.0f, 3.0f))
            {
                changed = true;
            }
            ImGui::Text("Scale Z:");
            ImGui::SameLine();
            if(ImGui::SliderFloat(lockScale ? "##lockedScale" : "##ScaleZ", &(activeModel->scale.z), 0.0f, 3.0f))
            {
                changed = true;
            }
        }
        ImGui::Separator();

        ImGui::Text("Lock Rotate:");
        ImGui::SameLine();
        ImGui::Checkbox("##lockRotateCheckbox", &lockRotate);
        if (lockRotate) {
            if(ImGui::SliderFloat("Rotate all", &(activeModel->rotate.x), 0.0f, 5.0f)){
                float x = activeModel->rotate.x;
                activeModel->rotate = { x, x, x };
                activeModel->CalculateWorldTransformation();
            }
        }
        else {
            if(ImGui::SliderFloat("Rotate X", &(activeModel->rotate.x), 0.0f, 5.0f))
            {
                changed = true;
            }
            if(ImGui::SliderFloat("Rotate Y", &(activeModel->rotate.y), 0.0f, 5.0f))
            {
                changed = true;
            }
            if(ImGui::SliderFloat("Rotate Z", &(activeModel->rotate.z), 0.0f, 5.0f))
            {
                changed = true;
            }
        }
        ImGui::Separator();
        ImGui::Text("Translation X:");
        ImGui::SameLine();
        if(ImGui::SliderFloat("##TranslationX", &(activeModel->translate.x), -5.0f, 5.0f))
        {
            changed = true;
        }
        ImGui::Text("Translation Y:");
        ImGui::SameLine();
        if(ImGui::SliderFloat("##TranslationY", &(activeModel->translate.y), -5.0f, 5.0f))
        {
            changed = true;
        }
        ImGui::Text("Translation Z:");
        ImGui::SameLine();
        if(ImGui::SliderFloat("##TranslationZ", &(activeModel->translate.z), -5.0f, 5.0f))
        {
            changed = true;
        }
        
        if(changed)
        {
            activeModel->CalculateWorldTransformation();
        }
 
        ImGui::Separator();
        ImGui::Text("Reflection:");
        ImGui::SliderFloat("Ambient", &(activeModel->ambientColor), 0.0f, 1.0f);
        ImGui::SliderFloat("Diffuse", &(activeModel->diffuseColor), 0.0f, 1.0f);
        ImGui::SliderFloat("Specular", &(activeModel->specularColor), 0.0f, 1.0f);
    }
    
    
    if (ImGui::CollapsingHeader("Cameras")) {
        char** cameraNames = new char*[cameras.size()];
        for (int i = 0; i < cameras.size(); i++){
            cameraNames[i] = const_cast<char*>(cameras.at(i)->GetModel()->GetModelName().c_str());
        }
        
        ImGui::Text("Selected Camera:");
        ImGui::SameLine();
        ImGui::Combo("##selectedCamera", &(scene->activeCameraIndex), cameraNames, cameras.size());
        
        
        ImGui::Text("Zooming: ");
        ImGui::SameLine();
        if (ImGui::SliderFloat("##cameraZoom", &(activeCamera->zoom), 0.100f, 50.0f, "%.2f", 5.0f))
        {
            activeCamera->CalculateProjectionMatrix();
            activeCamera->SetCameraLookAt();
        }
        ImGui::Separator();
        if(ImGui::RadioButton("Orthographic", &(activeCamera->projectionType), 0))
        {
            activeCamera->SwitchToOrthographic();
        }
        if(ImGui::RadioButton("Perspective", &(activeCamera->projectionType), 1))
        {
            activeCamera->SwitchToPrespective();
        }
        ImGui::Separator();
        bool isOrth = activeCamera->GetProjectionType() == 0;
        if(isOrth){
            ImGui::SliderFloat("Height", &(activeCamera->height), 0.01f, 200.0f);
        } else {
            ImGui::SliderFloat("Fovy", &(activeCamera->fovy), 0.01f, 3.14f);
        }
        ImGui::SliderFloat("Aspect Ratio", &(activeCamera->aspectRatio), 0.1f, 2.0f);
        ImGui::SliderFloat("Near", &(activeCamera->nearP), 1.0f, 200.0f);
        ImGui::SliderFloat("Far", &(activeCamera->farP), 1.0f, 200.0f);
        activeCamera->CalculateProjectionMatrix();
        ImGui::Separator();
        
        int colSize = ((mainMenuWidth - 82)/3)/3;
        ImGui::Text("\n|       Eye       |        Up       |        At       |");
        ImGui::Text(  "|   X    Y    Z   |   X    Y    Z   |   X    Y    Z   |\n");
        
        ImGui::PushID(0);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(200, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));

        if(ImGui::VSliderFloat("##eyeX", ImVec2(colSize, 200), &(activeCamera->eye.x), -199,199, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##eyeY", ImVec2(colSize, 200), &(activeCamera->eye.y), -199,199, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##eyeZ", ImVec2(colSize, 200), &(activeCamera->eye.z), -199,199, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
        ImGui::PushID(1);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(0, 200, 0));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));
        if(ImGui::VSliderFloat("##upX", ImVec2(colSize, 200), &(activeCamera->up.x), -10,10, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##upY", ImVec2(colSize, 200), &(activeCamera->up.y), 0.1,10, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##upZ", ImVec2(colSize, 200), &(activeCamera->up.z), -10,10, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
        ImGui::PushID(2);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(0, 0, 200));
        ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor(255, 255, 255));
        if(ImGui::VSliderFloat("##atX", ImVec2(colSize, 200), &(activeCamera->at.x), -30,30, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##atY", ImVec2(colSize, 200), &(activeCamera->at.y), -30,30, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        if(ImGui::VSliderFloat("##atZ", ImVec2(colSize, 200), &(activeCamera->at.z), -30,30, "%f"))
        {
            activeCamera->SetCameraLookAt();
        }
        ImGui::SameLine();
        ImGui::PopStyleColor(2);
        ImGui::PopID();
        
    }
    
    
    ImGui::End();
}

void BuildToolbar(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
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
                    scene->AddModel(Utils::LoadMeshModelPointer(outPath));
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
            ImGui::EndMenu();
        }
        ImGui::MenuItem("Help", "", &showDemoWindow);
        ImGui::EndMainMenuBar();
    }
}

void BuildAboutPage(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("About", &aboutPageVisible, ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(300, 200));
    ImGui::SetWindowPos(ImVec2((display_w - 300)/2, 100));
    
    ImGui::Text("");
    ImGui::Text("Assigment No. : 3");
    ImGui::Text("");
    ImGui::Text("Students:");
    ImGui::Text("   - David Antoon (204489470)");
    ImGui::Text("   - Ameer Dow    (203844956)");
    ImGui::Text("");
    
    ImGui::End();
}

void BuildSettingsPage(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    ImGui::Begin("Settings", &settingsPageVisible, ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(std::min(600, display_w), std::min(300, display_h)));
    ImGui::SetWindowPos(ImVec2((display_w - std::min(600, display_w))/2, 100));
    ImGui::Text("Background color:");
    if (ImGui::ColorEdit3("", (float*)&clearColor))
    {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    }
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

void DisplayFPSPage(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
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

void DisplayAddNewCamera(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window, int display_w, int display_h)
{
    if(newCameraResult){
        newCameraPageVisible = false;
        newCameraResult = false;
        Camera* camera = new Camera(eye, at, up, scene->GetActiveCamera().aspectRatio);
        scene->AddCamera(camera);
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

void DrawImguiMenus(ImGuiIO& io, const std::shared_ptr<Scene>& scene, GLFWwindow* window)
{
    int display_w = 0 , display_h = 0;
    glfwGetWindowSize(window, &display_w, &display_h);
    
    if(cameraObjPath == "")
    {
        DisplayAlertCameraObj(io, scene, window, display_w, display_h);
        return;
    }
    
    if(lightObjPath == "")
    {
        DisplayAlertLightObj(io, scene, window, display_w, display_h);
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

const std::string GetLightPath()
{
    return lightObjPath;
}

const bool ShouldDisplayAxes()
{
    return displayAxesConfig;
}

const bool ShouldSelectOnlyActiveModel()
{
    return displaySelectedModelOnlyConfig;
}
