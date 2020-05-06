#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>


#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"

int main() {
	{
		Repository repo{};
		Service service{ repo };
		UI ui{ service };
		ui.run();

		//testAll();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}