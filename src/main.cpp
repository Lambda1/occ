#include "VirtualScreen.h"

int main()
{
	occ::VirtualScreen screen(10,10,2);

	screen.SetScreen(5, 5, 255, 255, 255);
	screen.Display();

	return 0;
}
