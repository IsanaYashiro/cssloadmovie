/*
 * WindowsControlWidget.h
 *
 *  Created on: 2022年8月8日
 *      Author: huangsh
 */

#ifndef WINDOWSCONTROLWIDGET_H_
#define WINDOWSCONTROLWIDGET_H_

#include <QTreeWidget>


class WindowsControlWidget : public QTreeWidget
{

public:
	WindowsControlWidget(QWidget *parent);
	virtual ~WindowsControlWidget();

protected:


private:
	void AddItem();

private:
	bool mb_ctrl;
};

#endif /* WINDOWSCONTROLWIDGET_H_ */
