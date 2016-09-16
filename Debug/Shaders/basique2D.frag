// Version du GLSL

#version 150 core


// Sortie Shader
out vec4 out_Color;

in vec3 color;

// Fonction main

void main()
{
    // Couleur finale du pixel

    out_Color = vec4(color, 1.0);
}
