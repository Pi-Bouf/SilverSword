#include "Console.h"

enum color
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};

void Console::ConsoleText(string clas, string msg, int text, int back)
{
	QTime time;
	time.start();
	SetConsoleTextAttribute(stdOutput, getAttribute(text, back));
	cout << "[" << time.toString("hh:mm:ss::zzz").toStdString() << "][" << clas << "] " << msg << endl;
}

void Console::WriteLine(string clas, string msg)
{
	ConsoleText(clas, msg, 10, 0);
}

void Console::WriteInfo(string clas, string msg)
{
	ConsoleText(clas, msg, 15, 0);
}

void Console::WriteError(string clas, string msg)
{
	ConsoleText(clas, msg, 4, 0);
}

void Console::WriteDebug(string clas, string msg)
{
	ConsoleText(clas, msg, 11, 0);
}

unsigned short Console::getAttribute(int text, int back)
{
	return (unsigned)back << 4 | (unsigned)text;
}
