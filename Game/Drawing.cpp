#include "Drawing.h"


Drawing::Drawing(string name, Input *e)
{
	drawingName = name;
	event = e;
	m_shader = new Shader("Shaders/texture.vert", "Shaders/texture.frag");
	m_shader->charger();

	texture.setImagePath("Textures/Herbe.jpg");
	texture.loadTexture();
	
	float vertices[] = { -5, 0, -5, -5, 0, 5, 5, 0, 5,
		5, 0, 5, 5, 0, -5, -5, 0, -5 };

	float couleurs[] = { 
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,
		0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8};

	float texturesTMP[] = { 0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4 };

	nbrVertices = sizeof(vertices) / sizeof(float);
	nbrTextures = sizeof(texturesTMP) / sizeof(float);


	m_vertices = new float[nbrVertices];
	m_couleurs = new float[nbrVertices];
	m_textures = new float[nbrTextures];
	for (int i = 0; i < nbrVertices; i++)
	{
		m_vertices[i] = vertices[i];
		m_couleurs[i] = couleurs[i];
	}
	for (int j = 0; j < nbrTextures; j++)
	{
		m_textures[j] = texturesTMP[j];
	}

}

void Drawing::afficher(mat4 modelview, mat4 projection)
{
	glUseProgram(m_shader->getProgramID());

	if (event->getKey(SDL_SCANCODE_Y))
		cout << "IT WORKS !" << endl;

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, m_textures);
	glEnableVertexAttribArray(2);

	//modelview = rotate(modelview, angle, vec3(0.0, 1.0, 0.0));

	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));

	glBindTexture(GL_TEXTURE_2D, texture.getTextureID());
	glDrawArrays(GL_TRIANGLES, 0, nbrVertices/3);
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(0);

	glUseProgram(0);

	angle += 0.01;
	if (angle > 360)
	{
		angle = 0;
	}
}