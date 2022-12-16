#include "VirtualScreen.h"

#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	const uint32_t width = 200u;
	const uint32_t height = 100u;
	occ::VirtualScreen screen(width, height, 2);
	uint16_t r, g, b;
	for (uint32_t i = 0u; i < height; ++i)
	{
		for (uint32_t j = 0u; j < width; ++j)
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
