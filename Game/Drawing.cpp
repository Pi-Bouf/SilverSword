#include "Drawing.h"


Drawing::Drawing(string name)
{
	drawingName = name;
	m_shader = new Shader("Shaders/couleur3D.vert", "Shaders/couleur3D.frag");
	m_shader->charger();
	
	float vertices[] = { 8.000000, -0.200000, 8.000000, -7.999997, -0.200000, -8.000003, 8.000000, -0.200000, -8.000000,
		-8.000000, 0.200000, -8.000000, 7.999995, 0.200000, 8.000005, 8.000004, 0.200000, -7.999996,
		8.000004, 0.200000, -7.999996, 8.000000, -0.200000, 8.000000, 8.000000, -0.200000, -8.000000,
		7.999995, 0.200000, 8.000005, -8.000001, -0.200000, 7.999999, 8.000000, -0.200000, 8.000000,
		-8.000003, 0.200000, 7.999997, -7.999997, -0.200000, -8.000003, -8.000001, -0.200000, 7.999999,
		8.000000, -0.200000, -8.000000, -8.000000, 0.200000, -8.000000, 8.000004, 0.200000, -7.999996,
		8.000000, -0.200000, 8.000000, -8.000001, -0.200000, 7.999999, -7.999997, -0.200000, -8.000003,
		-8.000000, 0.200000, -8.000000, -8.000003, 0.200000, 7.999997, 7.999995, 0.200000, 8.000005,
		8.000004, 0.200000, -7.999996, 7.999995, 0.200000, 8.000005, 8.000000, -0.200000, 8.000000,
		7.999995, 0.200000, 8.000005, -8.000003, 0.200000, 7.999997, -8.000001, -0.200000, 7.999999,
		-8.000003, 0.200000, 7.999997, -8.000000, 0.200000, -8.000000, -7.999997, -0.200000, -8.000003,
		8.000000, -0.200000, -8.000000, -7.999997, -0.200000, -8.000003, -8.000000, 0.200000, -8.000000 };      // Face 6

	float couleurs[] = { 
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,           // Face 1
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,           // Face 1

		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 2
		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 2

		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 3
		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 3

		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,           // Face 4
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,           // Face 4

		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 5
		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 5

		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4,           // Face 6
		0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4 };          // Face 6

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

	modelview = rotate(modelview, angle, vec3(0.0, 1.0, 0.0));

	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));

	glDrawArrays(GL_TRIANGLES, 0, nbrVertices/3);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glUseProgram(0);

	angle += 0.005;
	if (angle > 360)
	{
		angle = 0;
	}
}