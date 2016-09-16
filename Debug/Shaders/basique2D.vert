// Version du GLSL

#version 150 core


// Entrée Shader

in vec2 in_Vertex;
in vec3 in_Color;

out vec3 color;

// Fonction main

void main()
{
    // Position finale du vertex
    gl_Position = vec4(in_Vertex, 0.1, 1.0);
	color = in_Color;
}
