/*
 * WindowsControlWidget.cpp
 *
 *  Created on: 2022年8月8日
 *      Author: huangsh
 */

#include <QKeyEvent>
#include "WindowsControlWidget.h"

WindowsControlWidget::WindowsControlWidget(QWidget *parent)
	: QTreeWidget(parent),mb_ctrl(false)
{
	// TODO Auto-generated constructor stub
	AddItem();
}

WindowsControlWidget::~WindowsControlWidget() {
	// TODO Auto-generated destructor stub
}

void WindowsControlWidget::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Control)
	{
		mb_ctrl = true;
	}
	else
	{
		mb_ctrl = false;
	}
	AddItem();
}

void WindowsControlWidget::AddItem()
{
	QIcon icon("lock.png");
	QTreeWidgetItem *item = new QTreeWidgetItem(this);
	item->setText(0, "yb3d_RTM");
	item->setIcon(0,icon);
	item->setCheckState(0,Qt::Checked);

	item = new QTreeWidgetItem(this);
	item->setText(0, "velana");
	item->setCheckState(0,Qt::Unchecked);

	if(mb_ctrl)
	{
		QTreeWidgetItem *item = new QTreeWidgetItem(this);
		item->setText(0, "ShotTest");
		item->setCheckState(0,Qt::Checked);
	}

	setHeaderHidden(true);
}

