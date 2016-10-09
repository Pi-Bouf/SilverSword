#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>


class AssetLoader
{
public:
	AssetLoader(QString data);
	~AssetLoader();

private:
	QString assetName;
	QString textureName;
};

