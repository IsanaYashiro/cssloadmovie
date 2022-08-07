#include "dragdropqgraphicsview.h"

#include "common.h"

#include <QDebug>
#include <QDropEvent>
#include <QSharedPointer>
#include "itemqtreewidget.h"

#include "dragdropqgraphicsscene.h"
#include "ucpqgraphicsitem.h"

DragDropQGraphicsView::DragDropQGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
	DragDropQGraphicsScene* scene = new DragDropQGraphicsScene(this);
	scene->setSceneRect(-300, -400, 600, 800);
	setScene(scene);

	/**设置scene的背景色为gray,此时会填满整个 view，可以通过重写scene的drawbackgroud来标识scene*/
	//scene->setBackgroundBrush(Qt::darkGray);

	setAcceptDrops(true);
	setRenderHint(QPainter::Antialiasing);
	setTransformationAnchor(QGraphicsView::NoAnchor);
}

DragDropQGraphicsView::~DragDropQGraphicsView()
{
}

void DragDropQGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
	event->setAccepted(true);
}


void DragDropQGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{

}

void DragDropQGraphicsView::dropEvent(QDropEvent *event)
{
	ItemQTreeWidget* srcWidget = qobject_cast<ItemQTreeWidget*>(event->source());
	if (!srcWidget)
		return;

	QVariant vizItemType = srcWidget->currentItem()->data(0, gn_vizItemTypeRole);

	if (!vizItemType.isValid())
		return;

	//qDebug() << "source is " << srcWidget->currentItem()->text(0);
	//qDebug() << " role data is " << srcWidget->currentItem()->data(0, itemTypeRole);
	//qDebug() << "viz item type is " << vizItemType;

	QPointF pos = mapToScene(event->pos());

    VizQGraphicsItem* vizItem = new VizQGraphicsItem(lxQVizItemType(vizItemType.toInt()));
	vizItem->setPos(pos);
	scene()->addItem(vizItem);

	qDebug() <<"drop item size "  << scene()->items().size();

}

void DragDropQGraphicsView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Control)
	{
		mb_ctrl = true;
	}
	switch (event->key())
	{
	case Qt::Key_Delete:

		break;
	default:
		break;
	}

}

void DragDropQGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Control)
	{
		mb_ctrl = false;
	}
}

void DragDropQGraphicsView::wheelEvent(QWheelEvent *event)
{
	/**
		ctrl +  zoom in
		ctrl -  zoom out
	*/
    if (mb_ctrl)
    {
        //按住ctrl时xy同时缩放，使用angleDelta().y()代替
        scaleView(std::pow(2, event->angleDelta().y() / 240.0));  //event->delta()
//        qDebug()<<"11 delta=="<<event->delta();
    }
	else
    {
        translateViewY(event->angleDelta().y()/10.);
//        qDebug()<<"22 delta=="<<event->angleDelta().y();
//        qDebug()<<event->angleDelta().y();
    }

}

void DragDropQGraphicsView::mousePressEvent(QMouseEvent *event)
{
	// test curve line 
	//for (auto item : scene()->items())
	//{
	//	if (LxGrphicsCurveLineItem* line = qgraphicsitem_cast<LxGrphicsCurveLineItem*>(item))
	//	{
	//		line->setDstPt(mapToScene(event->pos()));
	//		scene()->update();
	//	}
	//}

	qDebug() << "view scene pos " << mapToScene(event->pos());
	qDebug() << "scene is " << scene();


	QGraphicsView::mousePressEvent(event);
}

void DragDropQGraphicsView::scaleView(qreal scaleFactor)
{
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

	if (factor < 0.07 || factor > 100)
		return;

	scale(scaleFactor, scaleFactor);
}

void DragDropQGraphicsView::translateViewY(qreal dy)
{
	translate(0,dy);
}
