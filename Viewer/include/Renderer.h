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
	float *zBuffer;
	int viewportWidth;
	int viewportHeight;
	int viewportX;
	int viewportY;

	void putPixel(int x, int y, const glm::vec3& color);
	void createBuffers(int viewportWidth, int viewportHeight);

	GLuint glScreenTex;
	GLuint glScreenVtc;

	void createOpenGLBuffer();
	void initOpenGLRendering();
    
    //homework 3
    ShaderProgram lightShader;
    ShaderProgram colorShader;
    Texture2D texture1;

public:
    Renderer();
	Renderer(int viewportWidth, int viewportHeight, int viewportX = 0, int viewportY = 0);
	~Renderer();

	void Render(const Scene& scene);
	void SwapBuffers();
	void ClearColorBuffer(const glm::vec3& color);
	void SetViewport(int viewportWidth, int viewportHeight, int viewportX = 0, int viewportY = 0);

    void DrawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color);
    glm::vec3 MultiplyMatVec3(glm::mat4 mat, glm::vec3 vec3);
    void DrawLine(const Line& line, glm::mat4& transMatrix, const glm::vec3& color);
    void DrawTriangle(const std::vector<glm::vec3>& vertices, glm::mat4& transMatrix, const glm::vec3& color);
    void DrawFaceNormal(const std::vector<glm::vec3>& vertices, glm::mat4& transformMatrix);
    void DrawModel(MeshModel* model, glm::mat4& transformMatrix);
    void DrawModelBoundingBox(MeshModel* model, glm::mat4 transformMatrix);

    //homework 3
    void LoadShaders();
    void LoadTextures();
    
};
