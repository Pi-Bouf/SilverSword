#include "AssetLoader.h"

AssetLoader::AssetLoader(string data)
{
	cout << "HEY" << endl;
	string path = "Data/" + data;
	ifstream file(path.c_str());

	if (!file)
	{
		cout << "ERROR ! The data file " + path + " cannot be loaded !" << endl;
	}
}

AssetLoader::~AssetLoader()
{
}
