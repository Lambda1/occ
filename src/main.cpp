#include "VirtualScreen.h"

#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

int main()
{
	occ::VirtualScreen screen(10,10,2);

#ifdef _MSC_VER
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(stdHandle, &mode);
	SetConsoleMode(stdHandle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif // _MSC_VER

	screen.SetScreen(5, 5, 255, 255, 255);
	screen.Display();

	return 0;
}
