#ifndef DEF_CONSOLE
#define DEF_CONSOLE
#include <Windows.h>
#include <iostream>
#include <QTime>

using namespace std;

class Console
{
#define stdOutput GetStdHandle(STD_OUTPUT_HANDLE)

public:
	static void ConsoleText(string clas, string msg, int text, int back);
	static void WriteLine(string clas, string msg);
	static void WriteInfo(string clas, string msg);
	static void WriteError(string clas, string msg);
	static void WriteDebug(string clas, string msg);
	static unsigned short getAttribute(int text, int back);
};

#endif