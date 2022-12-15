#include "VirtualScreen.h"

#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	occ::VirtualScreen screen(400, 200, 2);

	int r, g, b;
	for (int i = 0; i < 200; ++i)
	{
		for (int j = 0; j < 400; ++j)
		{
			std::cin >> r >> g >> b;
			screen.SetScreen(j, i, r, g, b);
		}
	}

#ifdef _MSC_VER
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(stdHandle, &mode);
	SetConsoleMode(stdHandle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif // _MSC_VER

	screen.EnableBackGroundColor(true);
	
	screen.Display();
	std::this_thread::sleep_for(std::chrono::microseconds(1000000));
	
	screen.Clear();
	std::this_thread::sleep_for(std::chrono::microseconds(1000000));

	return 0;
}
