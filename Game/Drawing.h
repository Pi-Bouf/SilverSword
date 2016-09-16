#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm.hpp>
#include <gtx\transform.hpp>
#include <gtc\type_ptr.hpp>
#include "Shader.h"
#include "Input.h"
#include "Texture.h"

using namespace std;
using namespace glm;

#ifndef BUFFER_OFFSET

#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

#endif

class Drawing
{
public:
	Drawing(string name, Input *e);
	void afficher(mat4 modelview, mat4 projection);
	~Drawing();

	void loadVBO();
	void updateVBO(void *donnee, int size, int offset);
	void loadVAO();

	void loadV();
private:
	string drawingName;
	Shader *m_shader;
	Texture texture;
	int nbrVertices;
	int nbrCouleurs;
	int nbrTextures;
	float *m_vertices;
	float *m_couleurs;
	float *m_textures;
	float angle = 0;
	Input *event;


	GLuint vboID;
	GLuint vaoID;
};

