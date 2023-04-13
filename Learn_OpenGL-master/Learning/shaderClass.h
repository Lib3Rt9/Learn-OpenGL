#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

using namespace std;

string get_file_contents(const char* filename);

class Shader
{
public:
	// Reference ID - Shader Program
	GLuint ID;

	// Constructor - build the Shader Program from 2 different shaders
	Shader(const char* vertexFile, const char* fragmentFile);


	// activate an delete the Shader Program
	void Activate();
	void Delete();
};

#endif