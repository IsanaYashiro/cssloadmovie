#pragma once

#include <QTreeWidget>

class ItemQTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	ItemQTreeWidget(QWidget *parent);
	~ItemQTreeWidget();
protected:
	void mouseMoveEvent(QMouseEvent *event) override;

private:
	void addItem();
};
