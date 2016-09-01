#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm.hpp>
#include <gtx\transform.hpp>
#include <gtc\type_ptr.hpp>
#include "Shader.h"

using namespace std;
using namespace glm;

class Drawing
{
public:
	Drawing(string name);
	void afficher(mat4 modelview, mat4 projection);
private:
	string drawingName;
	Shader *m_shader;
	int nbrVertices;
	float *m_vertices;
	float *m_couleurs;

	float angle = 0;
};

