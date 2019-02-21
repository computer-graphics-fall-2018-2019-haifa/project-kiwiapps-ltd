#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <list>
#include <memory>
#include "Texture2D.h"

/*
 * Renderer class.
 */
class Renderer
{
private:
	float *colorBuffer;

	GLuint glScreenTex;
	GLuint glScreenVtc;

	void createOpenGLBuffer();
	void initOpenGLRendering();
    
    ShaderProgram lightShader;
    ShaderProgram colorShader;
    Texture2D texture1;

public:
    Renderer();
	~Renderer();

	void Render(const std::shared_ptr<Scene>& scene, GLFWwindow* window);
//    void SwapBuffers();
//    void ClearColorBuffer(const glm::vec3& color);

//    void DrawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color);
//    glm::vec3 MultiplyMatVec3(glm::mat4 mat, glm::vec3 vec3);
//    void DrawLine(const Line& line, glm::mat4& transMatrix, const glm::vec3& color);
//    void DrawTriangle(const std::vector<glm::vec3>& vertices, glm::mat4& transMatrix, const glm::vec3& color);
//    void DrawFaceNormal(const std::vector<glm::vec3>& vertices, glm::mat4& transformMatrix);
//    void DrawModelBoundingBox(MeshModel* model, glm::mat4 transformMatrix);

    void LoadShaders();
    void LoadTextures();
    
};
