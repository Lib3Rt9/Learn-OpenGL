#include "VAO.h"

// constructor that generates a VAO ID
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

// links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	//glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, GLsizei(stride), offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

// binds the VAO
void VAO::Bind()
{
	glBindVertexArray(ID);
}

// unbinds the VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

// deletes the VAO
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}