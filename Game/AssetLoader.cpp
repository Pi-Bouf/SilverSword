#include "AssetLoader.h"

AssetLoader::AssetLoader(QString data)
{
	Console::WriteDebug("AssetLoader", "Loading asset " + data.toStdString());
	QFile file("Data/" + data);
	if (!file.open(QIODevice::ReadOnly)) {
		Console::WriteError("AssetLoader", "File " + data.toStdString() + " doesn't exist !");
	}

	QTextStream in(&file);

	assetName = in.readLine().mid(6);
	textureName = in.readLine().mid(9);

	QString vertices;

	while (!in.atEnd()) {
		QString line = in.readLine();
		if (line.mid(0, 2) == "#v")
		{
			vertices += line.mid(3);
		}
	}
	vertices.replace('\n', ', ');
	file.close();

	
	// Traitement vertices
	QStringList verticesList = vertices.split(", ");
	verticesArray = new float(verticesList.length());
	for (int cpt = 0; cpt < verticesList.length(); cpt++)
	{
		verticesArray[cpt] = verticesList[cpt].toFloat();
	}
	
	Console::WriteInfo("AssetLoader", " successfully loaded !");
}

AssetLoader::~AssetLoader()
{
}
