#include "Drawing.h"


Drawing::Drawing(string name, Input *e)
{
	drawingName = name;
	event = e;
	vboID = 0;
	vaoID = 0;
	m_shader = new Shader("Shaders/couleur3D.vert", "Shaders/couleur3D.frag");
	m_shader->load();

	texture.setImagePath("Textures/Herbe.jpg");
	texture.loadTexture();
	
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

	float texturesTMP[] = {
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4,
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4,
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4,
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4,
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4,
		0, 0, 4, 0, 4, 4,
		0, 0, 0, 4, 4, 4 };


	nbrVertices = sizeof(vertices) / sizeof(float);
	nbrCouleurs = sizeof(couleurs) / sizeof(float);
	nbrTextures = sizeof(texturesTMP) / sizeof(float);
	m_vertices = new float[nbrVertices];
	m_couleurs = new float[nbrCouleurs];
	m_textures = new float[nbrTextures];
	
	for (int i = 0; i < nbrVertices; i++)
	{
		m_vertices[i] = vertices[i];
	}
	for (int k = 0; k < nbrCouleurs; k++)
	{
		m_couleurs[k] = couleurs[k];
	}
	for (int j = 0; j < nbrTextures; j++)
	{
		m_textures[j] = texturesTMP[j];
	}
}

void Drawing::afficher(mat4 modelview, mat4 projection)
{
	glUseProgram(m_shader->getProgramID());

	glBindVertexArray(vaoID);

		glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));
		glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
		glUniform1f(glGetUniformLocation(m_shader->getProgramID(), "time"), SDL_GetTicks()*0.0005);

		//glBindTexture(GL_TEXTURE_2D, texture.getTextureID());
			glDrawArrays(GL_TRIANGLES, 0, nbrVertices / 3);
		//glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);

	glUseProgram(0);
}

void Drawing::updateVBO(void *donnee, int size, int offset)
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	if (adresseVBO == NULL)
	{
		cout << "Erreur au niveau de la récupération du VBO" << endl;
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return;
	}

	memcpy((char*)adresseVBO + offset, donnee, nbrVertices*sizeof(float));

	glUnmapBuffer(GL_ARRAY_BUFFER);
	adresseVBO = 0;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Drawing::loadV()
{
	// Si l'identifiant existe déjà, on supprime, évitant les fuites de mémoires
	if (glIsBuffer(vboID) == GL_TRUE)
		glDeleteBuffers(1, &vboID);

	// Génération identifiant
	glGenBuffers(1, &vboID);
	// Vérouillage
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	// On demande de la mémoire sur la carte graphique
	glBufferData(GL_ARRAY_BUFFER, nbrVertices*sizeof(float) + nbrCouleurs*sizeof(float), 0, GL_STATIC_DRAW);

	// On transmet directement les valeurs sur la carte graphique
	glBufferSubData(GL_ARRAY_BUFFER, 0, nbrVertices*sizeof(float), m_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, nbrVertices*sizeof(float), nbrCouleurs*sizeof(float), m_couleurs);

	// On retire le vérouillage
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	// Si l'identifiant existe déjà, on le supprime
	if (glIsVertexArray(vaoID) == GL_TRUE)
		glDeleteVertexArrays(1, &vaoID);
	// Génération de l'identifiant
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
		// Enregistrement dans la CG des procédures
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(nbrVertices*sizeof(float)));
		glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Déverouillage
	glBindVertexArray(0);

}

Drawing::~Drawing()
{
	glDeleteBuffers(1, &vboID);
	glDeleteVertexArrays(1, &vaoID);
}