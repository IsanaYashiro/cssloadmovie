#include <QtWidgets/QApplication>

#include "dragdropwidget.h"
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	DragDropWidget w;
	w.show();


	return a.exec();
}
