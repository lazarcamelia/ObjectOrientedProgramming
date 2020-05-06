 #define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include "FileRepository.h"
#include "Service.h"
#include "UI.h"
#include "tests.h"
#include <cstring>
#include <sstream>


string readFileLocation() {
	stringstream input;
	string fileLocation;
	std::cin >> fileLocation;
	cin.get();
	getline(std::cin, fileLocation);

	return fileLocation;
}

int main() {
	{
		string fileLocation = readFileLocation();
		FileRepository repo{ fileLocation };
		Service service{ repo };
		UI ui{ service };
		ui.run();

		testAll();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}