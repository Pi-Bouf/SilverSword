#include "AssetLoader.h"

AssetLoader::AssetLoader(string data)
{
	cout << "AssetLoader for " + data << endl;
	string path = "Data/" + data;
	ifstream file(path.c_str());

	if (!file)
	{
		cout << "ERROR ! The data file " + path + " cannot be loaded !" << endl;
	}
	else
	{
		cout << "File " + path + " loaded !" << endl;
	}
}

AssetLoader::~AssetLoader()
{
}
