#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// include the new created headers
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"


using namespace std;


// vertices coordinates
GLfloat vertices[] =
{
	//               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down

#pragma region region3

#pragma endregion

};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // lower left triangle
	3, 2, 4, // lower right triangle
	5, 4, 1 // upper trianglle
};


int main()
{
	// initializw GLFW
	glfwInit();

	// tell GLFW what version of OpenGLis in using
	// using OpenGL 4.6
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	// tell glfw - using the the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// create a GLFWwindow object of 800x800 pixels with the name of Learning
	GLFWwindow* window = glfwCreateWindow(800, 800, "Learning", NULL, NULL);
	// error check if window fail to create
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	// introduce the window into the current context
	glfwMakeContextCurrent(window);


	// load GLAD - configures OpenGL
	gladLoadGL();

	// specify the viewport of OpenGL in the Window
	// viewport goes from x = 0, y = 0 to x = 800, y = 800 
	glViewport(0, 0, 800, 800);


	// replace old functions with the new functions in classes

	// generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// links VBO to VAO
	// links VBO attributes to VAO
	//VAO1.LinkVBO(VBO1, 0);
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

#pragma region region1

#pragma endregion


	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		//specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.9f);
		// clean the back buffer and assign the neaw color
		glClear(GL_COLOR_BUFFER_BIT);

		// activate shaderProgram, which shader is wanted to be used
		// glUseProgram(shaderProgram);
		shaderProgram.Activate();

		// bind VAO -> OpenGL knows to use it
		//glBindVertexArray(VAO);
		VAO1.Bind();
		
		// draw triangles using GL_TRIANGLES primitive
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		// swap the ;back bufer with the front bufer
		glfwSwapBuffers(window);

		// take care of alll GLFEW events
		glfwPollEvents();
	}

	// clean and tidy up

#pragma region region2

#pragma endregion


	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// delete window before ending the program
	glfwDestroyWindow(window);
	// terminate the GLFW before ending the program
	glfwTerminate();

	return 0;
}