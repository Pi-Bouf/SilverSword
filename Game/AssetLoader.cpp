#include "AssetLoader.h"
#include <iostream>

using namespace std;

AssetLoader::AssetLoader(QString data)
{
	QFile file("Data/data_skybox");
	if (!file.open(QIODevice::ReadOnly)) {
	}

	QTextStream in(&file);

	while (!in.atEnd()) {
		QString line = in.readLine();
		qDebug() << line;
	}

	file.close();

	/*
	string lineFile;
	string verticesSource;
	getline(file, lineFile);
	assetName = lineFile.substr(6, lineFile.length());
	getline(file, lineFile);
	textureName = lineFile.substr(8, lineFile.length());

	while (getline(file, lineFile))
	{
		if (lineFile.substr(0, 2) == "#v")
		{
			verticesSource += lineFile.substr(3, lineFile.length());
		}
	}

	QString zorro = "ok";
	*/
	//cout << "Asset " + assetName + " loaded !" << endl;
}

AssetLoader::~AssetLoader()
{
}
