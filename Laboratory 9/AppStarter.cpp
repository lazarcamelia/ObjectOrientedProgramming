 #define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include "FileRepository.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"
#include <cstring>
#include <sstream>

int main() {
	{
		UI ui;
		ui.run();

		//testAll();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}