#ifndef DEF_ASSETLOADER
#define DEF_ASSETLOADER
#include <iostream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include "Console.h"

using namespace std;

class AssetLoader
{
public:
	AssetLoader(QString data);
	~AssetLoader();

private:
	QString assetName;
	QString textureName;
	float *verticesArray;
};

#endif