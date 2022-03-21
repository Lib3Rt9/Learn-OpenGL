#include "shaderClass.h"

using namespace std;

string get_file_contents(const char* filename)
{
	ifstream in(filename, ios::binary);
	if (in)
	{
		string contents;
		in.seekg(0, ios::end);
		contents.resize(in.tellg());
		in.seekg(0, ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// constructor - build the Shader Program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// read vertexFile and fragmentFile and store the strings
	string vertexCode = get_file_contents(vertexFile);
	string fragmentCode = get_file_contents(fragmentFile);

	// convert the shader source strings into character arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
	// attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	
	// compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	// attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	
	// compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);


	// create Shader Program Object and get its reference
	ID = glCreateProgram();
	
	// attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	
	// wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);


	// delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

// activates the Shader Program
void Shader::Activate()
{
	glUseProgram(ID);
}

// deletes the Shader Program
void Shader::Delete()
{
	glDeleteProgram(ID);
}