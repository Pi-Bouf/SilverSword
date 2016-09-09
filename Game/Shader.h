#ifndef DEF_SHADER
#define DEF_SHADER

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

using namespace std;

class Shader
{
public:
	Shader(string vertexSource, string fragmentSource);
	bool load();
	bool compileShader(GLuint &shader, GLenum type, string const &fichierSource);
	~Shader();

private:
	string m_vertexSource;
	string m_fragmentSource;
	GLuint m_vertexID;
	GLuint m_fragmentID;
	GLuint m_programID;
public:
	GLuint getProgramID() const;
};

#endif