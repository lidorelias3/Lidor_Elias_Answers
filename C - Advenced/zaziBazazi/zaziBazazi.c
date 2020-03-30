#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	
	while (1)
	{
		getch(stdin);
		wprintf(L"יזאזאב יזאז\n");
	}
}
