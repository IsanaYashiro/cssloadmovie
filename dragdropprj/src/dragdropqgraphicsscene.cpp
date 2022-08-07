#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "dragdropqgraphicsscene.h"

DragDropQGraphicsScene::DragDropQGraphicsScene(QObject *parent)
	: QGraphicsScene(parent)
{
}

DragDropQGraphicsScene::~DragDropQGraphicsScene()
{
}

void DragDropQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	update();
	QGraphicsScene::mouseMoveEvent(event);
}

//void LxGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
//{
//
//	QGraphicsScene::drawBackground(painter, rect);
//	painter->fillRect(sceneRect(), Qt::white);
//}
