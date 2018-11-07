#pragma once
#include "Scene.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

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
    void drawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color);
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

    void  DrawTriangles(const std::vector<glm::vec3>*  vertexPositions,
                        const std::vector<glm::vec3>*  normalPositions,
                        const std::vector<glm::vec3>*  texturePositions);

    void  SetCameraTransform(const  glm::mat4x4&  cTransform);
    void  SetProjection(const  glm::mat4x4&  projection);
    void  SetModelTransforms(const  glm::mat4x4&  mTransform,...);
    // void  ClearDepthBuffer();
    // void  SetDemoBuffer();
	// Add more methods/functionality as needed...
};
