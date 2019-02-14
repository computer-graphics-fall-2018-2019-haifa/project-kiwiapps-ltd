#define _USE_MATH_DEFINES

#include <imgui/imgui.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"
#include "ImguiMenus.h"
#include "Light.h"

// Global declarations
ImGuiIO* imgui;
GLFWwindow* window;
double zoomFactor = 1;
int windowWidth = 1280;
int windowHeight = 720;
const char* windowTitle = "Mesh Viewer";
bool zoomChanged = false;
bool cameraAndLightsInitialized = false;
std::shared_ptr<Scene> scene;

const glm::vec3& defaultEye = glm::vec3(0, 0, 10);
const glm::vec3& defaultAt = glm::vec3(0, 0, 0);
const glm::vec3& defaultUp = glm::vec3(0, 1, 0);

// Function declarations
GLFWwindow* SetupGlfwWindow(int w, int h, const char* window_name);
ImGuiIO& SetupImgui(GLFWwindow* window);
bool Setup(int windowWidth, int windowHeight, const char* windowName);
void Cleanup();

static void GlfwErrorCallback(int error, const char* description);
void StartFrame();
void RenderFrame();

void glfw_OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset);
void glfw_OnFramebufferSize(GLFWwindow* window, int width, int height);

float GetAspectRatio();
//void HandleImguiInput();

Renderer renderer;

int main(int argc, char **argv)
{
	// Create GLFW window
    if (!Setup(windowWidth, windowHeight, windowTitle))
    {
        std::cerr << "Setup failed" << std::endl;
        return -1;
    }

    scene = std::make_shared<Scene>();
    
    // setup renderer
    renderer.LoadShaders();
    
    while (!glfwWindowShouldClose(window))
    {
        if(!cameraAndLightsInitialized){
            if(GetCameraPath() != "" && GetLightPath() != "" && GetTexturePath() != ""){
                cameraAndLightsInitialized = true;
                renderer.LoadTextures();
                
                // add default camera after getting the absolute .obj path
                Camera* defaultCam = new Camera(defaultEye, defaultAt, defaultUp, GetAspectRatio());
                scene->AddCamera(defaultCam);
                
                // add default light after getting the absolute .obj path
                Light* defaultLight = new Light();
                //            scene->AddLight(defaultLight);
            }
        }
        
        // Poll and process events
        glfwPollEvents();
        
        StartFrame();
        
        // Imgui stuff
        DrawImguiMenus(*imgui, scene, window);
        
        RenderFrame();
    }
    
	// If we're here, then we're done. Cleanup memory.
	Cleanup();
    return 0;
}

GLFWwindow* SetupGlfwWindow(int w, int h, const char* window_name)
{
    // Intialize GLFW
    if (!glfwInit())
    {
        // An error occured
        std::cerr << "GLFW initialization failed" << std::endl;
        return nullptr;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
    // forward compatible with newer versions of OpenGL as they become available but not backward compatible (it will not run on devices that do not support OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create an OpenGL 3.3 core, forward compatible context window
    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    
    // Move OpenGL context to the newly created window
    glfwMakeContextCurrent(window);
    
    // Setup window events callbacks
    glfwSetFramebufferSizeCallback(window, glfw_OnFramebufferSize);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // An error occured
        std::cerr << "GLAD initialization failed" << std::endl;
        return nullptr;
    }
    
    return window;
}

ImGuiIO& SetupImgui(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	// Setup style
    ImGui::StyleColorsDark();
	return io;
}

bool Setup(int windowWidth, int windowHeight, const char* windowName)
{
    GLFWwindow* window = SetupGlfwWindow(windowWidth, windowHeight, windowName);
    if (!window)
    {
        std::cerr << "Window setup failed" << std::endl;
        return false;
    }
    
    imgui = &SetupImgui(window);
    
    glClearColor(GetClearColor().r, GetClearColor().g, GetClearColor().b, GetClearColor().a);
    glEnable(GL_DEPTH_TEST);
    
    return true;
}

void Cleanup()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

static void GlfwErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

void StartFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void RenderFrame()
{
    // Render the menus
    ImGui::Render();
    //    HandleImguiInput();
    
    // Clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// Render the scene
    renderer.Render(scene, window);

    // Imgui stuff
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // Swap front and back buffers
    glfwSwapBuffers(window);
}

//-----------------------------------------------------------------------------
// Is called when the window is resized
//-----------------------------------------------------------------------------
void glfw_OnFramebufferSize(GLFWwindow* window, int width, int height)
{
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, windowWidth, windowHeight);
    // TODO: create set aspect ratio function
    // scene->GetActiveCamera().SetAspectRatio(GetAspectRatio());
}

void glfw_OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
    zoomFactor = glm::pow(1.1, -yoffset);
    zoomChanged = true;
}

float GetAspectRatio()
{
    return static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
}
