#define _USE_MATH_DEFINES

#include "Renderer.h"
#include "InitShader.h"
#include "MeshModel.h"
#include "ShaderProgram.h"
#include "ImguiMenus.h"
#include <imgui/imgui.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

#define INDEX(width,x,y,c) ((x)+(y)*(width))*3+(c)

Renderer::Renderer(int viewportWidth, int viewportHeight, int viewportX, int viewportY) :
	colorBuffer(nullptr),
	zBuffer(nullptr)
{
	initOpenGLRendering();
	SetViewport(viewportWidth, viewportHeight, viewportX, viewportY);
}

Renderer::Renderer()
{
    
}
Renderer::~Renderer()
{
	if (colorBuffer)
	{
		delete[] colorBuffer;
	}
}

void Renderer::putPixel(int i, int j, const glm::vec3& color)
{
	if (i < 0) return; if (i >= viewportWidth) return;
	if (j < 0) return; if (j >= viewportHeight) return;
	colorBuffer[INDEX(viewportWidth, i, j, 0)] = color.x;
	colorBuffer[INDEX(viewportWidth, i, j, 1)] = color.y;
	colorBuffer[INDEX(viewportWidth, i, j, 2)] = color.z;
}

void Renderer::createBuffers(int viewportWidth, int viewportHeight)
{
	if (colorBuffer)
	{
		delete[] colorBuffer;
	}

	colorBuffer = new float[3* viewportWidth * viewportHeight];
	for (int x = 0; x < viewportWidth; x++)
	{
		for (int y = 0; y < viewportHeight; y++)
		{
			putPixel(x, y, glm::vec3(0.0f, 0.0f, 0.0f));
		}
	}
}

void Renderer::ClearColorBuffer(const glm::vec3& color)
{
	for (int i = 0; i < viewportWidth; i++)
	{
		for (int j = 0; j < viewportHeight; j++)
		{
			putPixel(i, j, color);
		}
	}
}

void Renderer::SetViewport(int viewportWidth, int viewportHeight, int viewportX, int viewportY)
{
	this->viewportX = viewportX;
	this->viewportY = viewportY;
	this->viewportWidth = viewportWidth;
	this->viewportHeight = viewportHeight;
	createBuffers(viewportWidth, viewportHeight);
	createOpenGLBuffer();
}


void Renderer::DrawLine(const glm::vec2& p1, const glm::vec2& p2, const glm::vec3& color)
{
    // Bresenham’s Line Drawing Algorithm
    
    // init points per vec
    int x0 = p1.x;
    int y0 = p1.y;
    int x1 = p2.x;
    int y1 = p2.y;
    
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;
    
    while(true){
        putPixel(x0,y0, color);
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}


glm::vec3 Renderer::MultiplyMatVec3(glm::mat4 mat, glm::vec3 vec3)
{
    glm::vec4 vec4 = mat * glm::vec4(vec3, 1);
    if (vec4.w == 0){
        vec4.w = 1;
    }
    return glm::vec3(vec4.x / vec4.w, vec4.y / vec4.w, vec4.z / vec4.w);
}

glm::vec3 halfAxesV3Global = glm::vec3(0);

void Renderer::DrawLine(const Line& line, glm::mat4& transMatrix, const glm::vec3& color)
{
    glm::vec3 p1 = MultiplyMatVec3(transMatrix, line.point1) + halfAxesV3Global;
    glm::vec3 p2 = MultiplyMatVec3(transMatrix, line.point2) + halfAxesV3Global;
    DrawLine(p1, p2, color);
}

// draw triangle by calling drawLine foreach rib
void Renderer::DrawTriangle(const std::vector<glm::vec3>& vertices, glm::mat4& transMatrix, const glm::vec3& color)
{
    if(vertices.size() != 3){
        throw "Triangle must have three vertices";
    }
    
    DrawLine(Line(vertices[0], vertices[1]), transMatrix, color);
    DrawLine(Line(vertices[0], vertices[2]), transMatrix, color);
    DrawLine(Line(vertices[1], vertices[2]), transMatrix, color);
}

void Renderer::DrawFaceNormal(const std::vector<glm::vec3>& vertices, glm::mat4& transformMatrix)
{
	glm::vec3
		mid = (vertices[0] + vertices[1] + vertices[2]) / glm::vec3(3, 3, 3),
		normal = glm::cross((vertices[1] - vertices[0]), (vertices[2] - vertices[0])),
		startPoint = mid - (normal * glm::vec3(0.2)),
		endPoint = mid + (normal * glm::vec3(2));
    
    Line line = Line(startPoint, endPoint);
	DrawLine(line, transformMatrix, glm::vec3(1, 0, 0));
}

// draw each line by the provided transformation matrix
void Renderer::DrawModelBoundingBox(MeshModel* model, glm::mat4 transformMatrix) {
	std::vector<Line> boundingBox = model->GetBoundingBox();

    for(int i=0; i<boundingBox.size(); i++)
    {
        DrawLine(boundingBox.at(i), transformMatrix, glm::vec3(1, 0, 0));
    }
}


// loop over model faces
// build face vertics from model vertices positions
// draw bounding box
void Renderer::DrawModel(MeshModel* model, glm::mat4& transformMatrix) {
    
    // get model faces
    // get model vertics
    // get model normals
    // get model color by checking if is active model -> green else darkGray
    
	std::vector<Face> faces = model->GetFaces();
	std::vector<glm::vec3> vertices = model->GetVertices();
	std::vector<glm::vec3> normals = model->GetNormals();

    // call draw bounding box if requested
    if (model->boundingBoxVisibility) {
		DrawModelBoundingBox(model, transformMatrix);
    }
    
    // loop over faces and draw each face by calling the DrawFace function
        // use the provided transformMatrix when drawing the Faces
        // check if draw face normals requested

	for (int i = 0; i < faces.size(); i++) {
		std::vector<glm::vec3> vertices;
		Face face = faces.at(i);
        for(int j=0; j<3; j++){
            vertices.push_back(model->GetVertexByIndex(face.GetVertexByIndex(j) - 1));
        }

        if (model->faceNoramlVisibility == 1) {
			DrawFaceNormal(vertices, transformMatrix);
		}
        if(model->verticesNoramlVisibility) {
            
        }
		DrawTriangle(vertices, transformMatrix, model->GetColor());
	}
}

void Renderer::Render(const Scene& scene)
{
	
    if(scene.GetAllCameras().size() == 0){
        return;
    }
    const glm::vec3 redColor = glm::vec3(1, 0, 0);
    const glm::vec3 greenColor = glm::vec3(0, 1, 0);
    const glm::vec3 blueColor = glm::vec3(0, 0, 1);
    const glm::vec3 blackColor = glm::vec3(0, 0, 0);
    const glm::vec3 greyColor = glm::vec3(0.4, 0.4, 0.4);
    
    const int centerWidth = (int)(viewportWidth / 2);
    const int centerHeight = (int)(viewportHeight / 2);
    halfAxesV3Global = glm::vec3(centerWidth, centerHeight, 0);
    glm::mat4 sceneMatrix = scene.CalculateTransformationMatrix();
    
    if(ShouldDisplayAxes()){
        // draw axes
        float length = (viewportWidth > viewportHeight ? viewportHeight : viewportWidth) * 0.8;

        DrawLine(Line(glm::vec3(-length, 0, 0), glm::vec3(length, 0, 0)), sceneMatrix, redColor);
        DrawLine(Line(glm::vec3(0, -length, 0), glm::vec3(0, length, 0)), sceneMatrix, greenColor);
        DrawLine(Line(glm::vec3(0, 0, -length), glm::vec3(0, 0, length)), sceneMatrix, blueColor);
    }
    
    // loop over cameras
        // calcualte foreach camera the transform matrix
        // skip drawing active camera
        // draw camera
	std::vector<Camera*> cameras = scene.GetAllCameras();
    int activeCameraIndex = scene.GetActiveCameraIndex();
    
    for(int i=0; i<cameras.size(); i++){
        if (i != activeCameraIndex) {
            Camera* camera = cameras.at(i);
            MeshModel model = camera->GetModel();
            glm::mat4 matrix = sceneMatrix * model.CalculateWorldTransformation();
            DrawModel(&model, matrix);
        }
    }
    
    // loop over models
        // calcualte foreach model the transform matrix
        // loop over model faces
            // draw face triangle
            // draw face normal
        // highlight active model

    std::vector<std::shared_ptr<MeshModel>> models = scene.GetAllModels();
    for(int i=0; i<models.size(); i++){
        if(!ShouldSelectOnlyActiveModel() || scene.GetActiveModelIndex() == i){
            MeshModel* model = &(*models.at(i));
            glm::mat4 matrix = sceneMatrix * (*model).CalculateWorldTransformation();
            DrawModel(model, matrix);
        }
    }
    
}

void Renderer::LoadShaders()
{
    colorShader.loadShaders("vshader_color.glsl", "fshader_color.glsl");
}

void Renderer::LoadTextures()
{
    //if (!texture1.loadTexture("bin\\Debug\\crate.jpg", true))
    {
        //  texture1.loadTexture("bin\\Release\\crate.jpg", true);
    }
}

//##############################
//##OpenGL stuff. Don't touch.##
//##############################

// Basic tutorial on how opengl works:
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/
// don't linger here for now, we will have a few tutorials about opengl later.
void Renderer::initOpenGLRendering()
{
	// Creates a unique identifier for an opengl texture.
	glGenTextures(1, &glScreenTex);

	// Same for vertex array object (VAO). VAO is a set of buffers that describe a renderable object.
	glGenVertexArrays(1, &glScreenVtc);

	GLuint buffer;

	// Makes this VAO the current one.
	glBindVertexArray(glScreenVtc);

	// Creates a unique identifier for a buffer.
	glGenBuffers(1, &buffer);

	// (-1, 1)____(1, 1)
	//	     |\  |
	//	     | \ | <--- The exture is drawn over two triangles that stretch over the screen.
	//	     |__\|
	// (-1,-1)    (1,-1)
	const GLfloat vtc[]={
		-1, -1,
		 1, -1,
		-1,  1,
		-1,  1,
		 1, -1,
		 1,  1
	};

	const GLfloat tex[]={
		0,0,
		1,0,
		0,1,
		0,1,
		1,0,
		1,1};

	// Makes this buffer the current one.
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	// This is the opengl way for doing malloc on the gpu. 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vtc)+sizeof(tex), NULL, GL_STATIC_DRAW);

	// memcopy vtc to buffer[0,sizeof(vtc)-1]
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vtc), vtc);

	// memcopy tex to buffer[sizeof(vtc),sizeof(vtc)+sizeof(tex)]
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vtc), sizeof(tex), tex);

	// Loads and compiles a sheder.
	GLuint program = InitShader( "vshader.glsl", "fshader.glsl" );

	// Make this program the current one.
	glUseProgram(program);

	// Tells the shader where to look for the vertex position data, and the data dimensions.
	GLint  vPosition = glGetAttribLocation( program, "vPosition" );
	glEnableVertexAttribArray( vPosition );
	glVertexAttribPointer( vPosition,2,GL_FLOAT,GL_FALSE,0,0 );

	// Same for texture coordinates data.
	GLint  vTexCoord = glGetAttribLocation( program, "vTexCoord" );
	glEnableVertexAttribArray( vTexCoord );
	glVertexAttribPointer( vTexCoord,2,GL_FLOAT,GL_FALSE,0,(GLvoid *)sizeof(vtc) );

	//glProgramUniform1i( program, glGetUniformLocation(program, "texture"), 0 );

	// Tells the shader to use GL_TEXTURE0 as the texture id.
	glUniform1i(glGetUniformLocation(program, "texture"),0);
}

void Renderer::createOpenGLBuffer()
{
	// Makes GL_TEXTURE0 the current active texture unit
	glActiveTexture(GL_TEXTURE0);

	// Makes glScreenTex (which was allocated earlier) the current texture.
	glBindTexture(GL_TEXTURE_2D, glScreenTex);

	// malloc for a texture on the gpu.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, viewportWidth, viewportHeight, 0, GL_RGB, GL_FLOAT, NULL);
	glViewport(0, 0, viewportWidth, viewportHeight);
}

void Renderer::SwapBuffers()
{
	// Makes GL_TEXTURE0 the current active texture unit
	glActiveTexture(GL_TEXTURE0);

	// Makes glScreenTex (which was allocated earlier) the current texture.
	glBindTexture(GL_TEXTURE_2D, glScreenTex);

	// memcopy's colorBuffer into the gpu.
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, viewportWidth, viewportHeight, GL_RGB, GL_FLOAT, colorBuffer);

	// Tells opengl to use mipmapping
	glGenerateMipmap(GL_TEXTURE_2D);

	// Make glScreenVtc current VAO
	glBindVertexArray(glScreenVtc);

	// Finally renders the data.
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
