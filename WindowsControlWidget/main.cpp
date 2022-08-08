/*
 * main.cpp
 *
 *  Created on: 2022年8月8日
 *      Author: huangsh
 */
#include <QApplication>
#include "WindowsControlWidget.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	WindowsControlWidget w(nullptr);
	w.show();


	return a.exec();
}



