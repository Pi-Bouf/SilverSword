#include "Texture.h"


Texture::Texture()
{
	textureID = 0;
}

bool Texture::loadTexture()
{
	// Création d'une surface
	SDL_Surface *sdlImage = IMG_Load(image_path.c_str());
	// Test s'il y a une erreur
	if (sdlImage == 0)
	{
		cout << "Error loading texture: " << SDL_GetError() << endl;
		return false;
	}
	// Génération d'un ID de texture
	glGenTextures(1, &textureID);
	// Verouillage de la texture (sinon on ne peut pas travailler dessus)
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Vérification si l'image détient la composante alpha ou pas
	GLenum internalFormat(0);
	GLenum format(0);
	if (sdlImage->format->BytesPerPixel == 3)
	{
		internalFormat = GL_RGB;
		if (sdlImage->format->Rmask == 0xff)
		{
			format = GL_RGB;
		} else {
			format = GL_BGR;
		}
	}
	else if (sdlImage->format->BytesPerPixel == 4)
	{
		internalFormat = GL_RGBA;
		if (sdlImage->format->Rmask == 0xff)
		{
			format = GL_RGBA;
		}
		else {
			format = GL_BGRA;
		}
	}
	else {
		cout << "Error on pixel checking !" << SDL_GetError() << endl;
		SDL_FreeSurface(sdlImage);
		return false;
	}

	// Création de la texture 2D
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, sdlImage->w, sdlImage->h, 0, format, GL_UNSIGNED_BYTE, sdlImage->pixels);

	// On lisse les textures proches
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// On affiche avec moins de qualité les textures distantes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(sdlImage);
	return true;
}

void Texture::setImagePath(string path)
{
	image_path = path;
}

GLuint Texture::getTextureID()
{
	return textureID;
}

Texture::~Texture()
{
}
