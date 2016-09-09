#include "Shader.h"

Shader::Shader(string vertex, string fragment)
{
	m_vertexID = 0;
	m_fragmentID = 0;
	m_programID = 0;
	m_vertexSource = vertex;
	m_fragmentSource = fragment;
}

bool Shader::load()
{


	if (!compileShader(m_vertexID, GL_VERTEX_SHADER, m_vertexSource))
		return false;

	if (!compileShader(m_fragmentID, GL_FRAGMENT_SHADER, m_fragmentSource))
		return false;

	m_programID = glCreateProgram();

	glAttachShader(m_programID, m_vertexID);
	glAttachShader(m_programID, m_fragmentID);

	glBindAttribLocation(m_programID, 0, "in_Vertex");
	glBindAttribLocation(m_programID, 1, "in_Color");
	glBindAttribLocation(m_programID, 2, "in_TexCoord0");

	glLinkProgram(m_programID);

	GLint linkError(0);
	glGetProgramiv(m_programID, GL_LINK_STATUS, &linkError);

	if (linkError != GL_TRUE)
	{
		GLint sizeError(0);
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &sizeError);

		char* error = new char[sizeError + 1];

		glGetProgramInfoLog(m_programID, sizeError, &sizeError, error);
		error[sizeError] += '\0';

		cout << "Erreur linkage: " << error << endl;

		delete[] error;
		glDeleteProgram(m_programID);

		return false;
	}

	return true;
}

bool Shader::compileShader(GLuint& shader, GLenum type, string const& fichierSource)
{

	shader = glCreateShader(type);
	if (shader == 0)
	{
		cout << "Erreur, ce type de shader (" << type << ") n'existe pas !" << endl;
	}

	ifstream file(fichierSource.c_str());

	if (!file)
	{
		cout << "Impossible d'ouvrir le fichier " << fichierSource.c_str() << " !" << endl;
		return false;
	}

	string line;
	string completeSource;

	while (getline(file, line))
		completeSource += line + "\n";

	file.close();

	const GLchar* stringCodeSource = completeSource.c_str();

	glShaderSource(shader, 1, &stringCodeSource, 0);
	glCompileShader(shader);


	GLint compilationError(0);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationError);

	if (compilationError != GL_TRUE)
	{

		GLint sizeError(0);
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &sizeError);
		char *error = new char[sizeError + 1];

		glGetShaderInfoLog(shader, sizeError, &sizeError, error);
		error[sizeError] = '\0';

		cout << error << endl;

		delete[] error;
		glDeleteShader(shader);

		return false;
	}

	return true;
}

GLuint Shader::getProgramID() const
{
	return m_programID;
}


Shader::~Shader()
{
	glDeleteShader(m_vertexID);
	glDeleteShader(m_fragmentID);
	glDeleteShader(m_programID);
}