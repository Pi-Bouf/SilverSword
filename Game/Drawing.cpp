#include "Drawing.h"


Drawing::Drawing(string name)
{
	drawingName = name;
	m_shader = new Shader("Shaders/couleur3D.vert", "Shaders/couleur3D.frag");
	m_shader->charger();
	
	float vertices[] = { -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0,     // Face 1
		-1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0,     // Face 1

		1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0,       // Face 2
		1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0,         // Face 2

		-1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0,      // Face 3
		-1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0,    // Face 3

		-1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0,        // Face 4
		-1.0, -1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0,        // Face 4

		-1.0, -1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0,     // Face 5
		-1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0,     // Face 5

		-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0,         // Face 6
		-1.0, 1.0, 1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0 };      // Face 6

	float couleurs[] = { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1
		1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 1

		0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 2
		0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 2

		0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 3
		0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 3

		1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 4
		1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,           // Face 4

		0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 5
		0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,           // Face 5

		0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,           // Face 6
		0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };          // Face 6

	nbrVertices = sizeof(vertices) / sizeof(float);


	m_vertices = new float[nbrVertices];
	m_couleurs = new float[nbrVertices];
	for (int i = 0; i < nbrVertices; i++)
	{
		m_vertices[i] = vertices[i];
		m_couleurs[i] = couleurs[i];
	}
}

void Drawing::afficher(mat4 modelview, mat4 projection)
{
	glUseProgram(m_shader->getProgramID());


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, m_couleurs);
	glEnableVertexAttribArray(1);


	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));

	glDrawArrays(GL_TRIANGLES, 0, nbrVertices/3);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glUseProgram(0);
}