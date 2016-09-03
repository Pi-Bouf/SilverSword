#ifndef DEF_TEXTURE
#define DEF_TEXTURE

#include <iostream>
#include <string>
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Texture
{
public:
	Texture();
	bool loadTexture();
	void setImagePath(string path);
	GLuint getTextureID();
	~Texture();
private:
	string image_path;
	GLuint textureID;
};
#endif