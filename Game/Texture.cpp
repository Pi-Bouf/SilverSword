#include "Texture.h"


Texture::Texture()
{
	textureID = 0;
}

SDL_Surface* Texture::pixelReverse(SDL_Surface *surface)
{
	SDL_Surface *reverseImage = SDL_CreateRGBSurface(0, surface->w, surface->h, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask);

	// Tableau intermédiaire
	unsigned char* pixelsSources = (unsigned char*)surface->pixels;
	unsigned char* pixelsReverse = (unsigned char*)reverseImage->pixels;

	for (int i = 0; i < surface->h; i++)
	{
		for (int j = 0; j < surface->w * surface->format->BytesPerPixel; j++)
			pixelsReverse[(surface->w * surface->format->BytesPerPixel * (surface->h - 1 - i)) + j] = pixelsSources[(surface->w * surface->format->BytesPerPixel * i) + j];
	}

	return reverseImage;
}

bool Texture::loadTexture()
{
	// Création d'une surface
	SDL_Surface *sdlImage_base = IMG_Load(image_path.c_str());
	// Test s'il y a une erreur
	if (sdlImage_base == 0)
	{
		cout << "Error loading texture: " << SDL_GetError() << endl;
		return false;
	}

	SDL_Surface *sdlImage = pixelReverse(sdlImage_base);
	SDL_FreeSurface(sdlImage_base);

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
