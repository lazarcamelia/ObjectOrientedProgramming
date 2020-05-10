#include "BonusLab10.h"

#include <memory>
#include "FileRepository.h"
#include "Service.h"
#include "GUI.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    unique_ptr<FileRepository> repo = make_unique<FileRepository>();
    Service service{ repo.get() };

    GUI guiInterface{ service };
    guiInterface.show();

	return a.exec();
}
