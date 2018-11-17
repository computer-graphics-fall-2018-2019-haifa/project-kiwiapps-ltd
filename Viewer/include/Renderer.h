#pragma once
#include "Scene.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <list>

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

public:
	Renderer(int viewportWidth, int viewportHeight, int viewportX = 0, int viewportY = 0);
	~Renderer();

	void Render(const Scene& scene);
	void SwapBuffers();
	void ClearColorBuffer(const glm::vec3& color);
	void SetViewport(int viewportWidth, int viewportHeight, int viewportX = 0, int viewportY = 0);

    void DrawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color);
    void DrawTriangle(const std::vector<glm::vec3>& vertices, const glm::vec3& color);
    void DrawFace(MeshModel model, Face face, const bool drawNormals, const glm::vec3& color);
    void DrawModel(MeshModel* model, glm::mat4 transformMatrix);
    void DrawModelBoundingBox(MeshModel* model, glm::mat4 transformMatrix);

};
