#include "Lab10OOP.h"
#include <QtWidgets/QApplication>

#include <memory>
#include "FileRepository.h"
#include "Service.h"
#include "GUI.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	unique_ptr<FileRepository> repo = make_unique<FileRepository>();
	//repo->setFileLocation("victims.txt");
	Service service{ repo.get() };

	vector<Victim> victims = service.getAllVictims();

	cout << victims.size();

	GUI guiInterface{ service };
	guiInterface.show();  
	 
	return a.exec();
}
