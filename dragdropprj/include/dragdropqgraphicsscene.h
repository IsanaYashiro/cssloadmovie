#pragma once

#include <QGraphicsScene>

class DragDropQGraphicsScene : public QGraphicsScene
{
	Q_OBJECT

public:
	DragDropQGraphicsScene(QObject *parent=nullptr);
	~DragDropQGraphicsScene();

protected:
	//void drawBackground(QPainter *painter, const QRectF &rect) override;

	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

};
