#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <SOIL/SOIL.h>

// Shader, glm
#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//stdio
#include <stdio.h>




// Window dimensions
const GLuint roomWidth = 800, roomHeight = 600;
GLuint roomLength = 800;

char * filename = "picture.bmp";




int main()
{

	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(roomWidth, roomHeight, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, roomWidth, roomHeight);

	
	// Build and compile our shader program
	Shader ourShader("C:/Песочница/OpenGLProjects/SemestrProblem/SemestrProblem/Shader.vs", "C:/Песочница/OpenGLProjects/SemestrProblem/SemestrProblem/Shader.frag");

	
	glClearColor(1.0f, 0.11f, 0.87f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	//Reading pixels
	GLubyte * data = (GLubyte *)malloc(3 * roomWidth * roomHeight);
	if (data)
	{
		glReadPixels(0, 0, roomWidth, roomHeight, GL_RGB, GL_UNSIGNED_BYTE, data);
	}

	//Creating image
	SOIL_save_image(filename, SOIL_SAVE_TYPE_BMP, roomWidth, roomHeight, 3, data);

	free(data);
	glfwTerminate();

	return 0;
}
