#pragma once

#include <QWidget>
#include <QAction>
#include <QUndoStack>
#include "ui_dragdropwidget.h"

class DragDropWidget : public QWidget
{
	Q_OBJECT

public:
	DragDropWidget(QWidget *parent = Q_NULLPTR);
	~DragDropWidget();

private slots:
    void SlotDelectAct();


private:
    Ui::DragDropWidget ui;

	// action 
	QAction* mpDeleteAct;
	QAction* mpRedoAct;
	QAction* mpUndoAct;



	QUndoStack* mpUndoStack;


};
