#version 460 core

// positions / corordinates
layout (location = 0) in vec3 aPos;
// colors
layout (location = 1) in vec3 aColor;

// outputs the color for Fragment Shader
out vec3 color;

// Controls the scale of the vertices
uniform float scale;

void main()
{
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	color = aColor;
}