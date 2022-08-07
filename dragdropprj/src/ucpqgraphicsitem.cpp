#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QDebug>

#include "ucpqgraphicsitem.h"

/** ============================ucp item============================*/

UCPQGraphicsItem::UCPQGraphicsItem(QGraphicsItem*parent /*= nullptr*/)
	:QGraphicsItem(parent)
{

}

//LxGraphicsUCPItem::~LxGraphicsUCPItem()
//{
//	for (auto line : mvLine)
//	{
//		line->getSrcItem()->clearLine();
//
//		scene()->removeItem(line);
//		delete line;
//		line = nullptr;
//	}
//}

void UCPQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	painter->drawRect(-3, -3, 6, 6);
}

QRectF UCPQGraphicsItem::boundingRect() const
{
	return QRectF(-5, -5, 10, 10);
}



/** ============================dcp item============================*/

DCPQGraphicsItem::DCPQGraphicsItem(QGraphicsItem*parent /*= nullptr*/)
	:QGraphicsItem(parent)
{
	setFlag(GraphicsItemFlag::ItemIsSelectable);
}

//LxGraphicsDCPItem::~LxGraphicsDCPItem()
//{
//	mLine->getDstItem()->removeLine(mLine);
//
//	scene()->removeItem(mLine);
//	delete mLine;
//	mLine = nullptr;
//}

void DCPQGraphicsItem::setDCPText(QString text)
{
	for (int i = 1; i < text.size(); i += 2)
		text.insert(i, '\n');
	mstr_text = text;
}

void DCPQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	if (mstr_text != "")
	{
		painter->save();

		QFont font;
		font.setPixelSize(10);
		font.setBold(true);
		painter->setFont(font);
		painter->drawRect(-5, -5, 10, 10);
		painter->drawText(0, 5, 10, 30, Qt::AlignLeft | Qt::AlignTop, mstr_text);
		painter->restore();
	}
	else
	{
		painter->drawRect(-5, -5, 10, 10);
	}
}

QRectF DCPQGraphicsItem::boundingRect() const
{
	return QRectF(-5, -5, 15, 40);
}

void DCPQGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

	//mStartPt = mapToScene(event->pos());
	mt_startPt = scenePos();

	/**该dcp已经有了一个line,需要删除已有的line*/  
	if (mp_line != nullptr)
	{
		mp_line->getDstItem()->removeLine(mp_line);

		scene()->removeItem(mp_line);
		delete mp_line;
		mp_line = nullptr;
	}

    mp_line = new UCPQGrphicsCurveLineItem(this, nullptr);
	scene()->addItem(mp_line);


	QGraphicsItem::mousePressEvent(event);
}

void DCPQGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	mt_endPt = mapToScene(event->pos());

	qDebug() << "mouse move ... end pt " << mt_endPt;

	mp_line->setSrcDstPt(mt_startPt, mt_endPt);

	QGraphicsItem::mouseMoveEvent(event);
}

void DCPQGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF releasePt = mapToScene(event->pos());

	bool lineValid = false;
    UCPQGraphicsItem* dstItem=nullptr;
	for (auto item : scene()->items(releasePt))
	{
        dstItem = qgraphicsitem_cast<UCPQGraphicsItem*>(item);
        if (dstItem)
		{
			lineValid = true;
			break;
		}
	}

	if (!lineValid)
	{
		scene()->removeItem(mp_line);
		delete mp_line;
		mp_line = nullptr;
	}
	else
	{
		/**连线成功*/
		dstItem->addLine(mp_line);   ///< 记录该line 到dstItem 
		mp_line->setDstItem(dstItem);
	}

	scene()->update();

	QGraphicsItem::mouseReleaseEvent(event);
}



/**============================ curve line item =================================*/

UCPQGrphicsCurveLineItem::UCPQGrphicsCurveLineItem(DCPQGraphicsItem* srcItem, UCPQGraphicsItem*dstItem, QGraphicsItem*parent/*=nullptr*/)
	:QGraphicsItem(parent)
{
	mp_srcItem = srcItem;
	mp_dstItem = dstItem;
}

void UCPQGrphicsCurveLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	if (!mb_valid)
		return;

	//qDebug() << "line paint ................";
	//painter->drawRect(boundingRect());

	if (mp_srcItem != nullptr && mp_dstItem != nullptr)
	{
		mt_srcPt = mapFromItem(mp_srcItem, 0, 0);
		mt_dstPt = mapFromItem(mp_dstItem, 0, 0);
	}


	QPainterPath path(mt_srcPt);
	
	QPointF c1;
	QPointF c2;

	/**c1 控制start 点 c2控制end点*/
	qreal dX = mt_dstPt.x() - mt_srcPt.x();
	qreal dY = mt_dstPt.y() - mt_srcPt.y();
	/**目标点在下方*/
	if (dY >= 0)
	{
		c1 = QPointF(mt_srcPt.x(), mt_srcPt.y() + dY / 2);
		c2 = QPointF(mt_dstPt.x(), mt_srcPt.y() + dY / 2);
	}
	else
	{
		c1 = QPointF(mt_srcPt.x() + dX / 2, mt_srcPt.y() - dY);
		c2 = QPointF(mt_dstPt.x() - dX / 2, mt_dstPt.y() + dY);
	}

	/**draw curve line */
	path.cubicTo(c1, c2, mt_dstPt);

	painter->setPen(Qt::red);
	painter->drawPath(path);

}

QRectF UCPQGrphicsCurveLineItem::boundingRect() const
{
	if (!mb_valid)
		return QRectF();
	qDebug() << "line boundingRect ................";

	qreal penWidth = 1;
	//qreal extra = (penWidth + mArrowSize) / 2.0;
	qreal extra = 5;

	return QRectF(mt_srcPt, QSize(mt_dstPt.x() - mt_srcPt.x(), mt_dstPt.y() - mt_srcPt.y()))
		.normalized()
		.adjusted(-extra, -extra, extra, extra);
}



/**============================  body item =================================*/

BodyQGraphicsItem::BodyQGraphicsItem(int shape,QGraphicsItem*parent/*=nullptr*/)
	:QGraphicsItem(parent),mn_shape(shape)
{
	setFlags(GraphicsItemFlag::ItemIsMovable | GraphicsItemFlag::ItemIsSelectable);
}

void BodyQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	if(mn_shape == 0)
		painter->drawRoundedRect(-30, -30, 60, 60, 10, 10);
	else if(mn_shape == 1)
		painter->drawEllipse(-30, -30, 60, 60);
}

QRectF BodyQGraphicsItem::boundingRect() const
{
	return QRectF(-30,-30,60,60);
}

/**============================ viz item =================================*/

VizQGraphicsItem::VizQGraphicsItem(lxQVizItemType itemType,QGraphicsItem*parent /*= nullptr*/)
{
    qDebug()<<"enter viz";
	switch (itemType)
	{
	case Start:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(1, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(0, 35);
		break;
	}
	case CheckDI:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(0, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem2 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(-12, 35);
		downItem2->setPos(12, 35);
		downItem1->setDCPText("0");
		downItem2->setDCPText("1");
		qDebug() << "bodyItem " << bodyItem;
		qDebug() << "upItem " << upItem;
		qDebug() << "downItem1 " << downItem1;
		qDebug() << "downItem2 " << downItem2;
		break;
	}
	case WaitDI:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(0, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem2 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(-12, 35);
		downItem2->setPos(12, 35);
		downItem1->setDCPText("0");
		downItem2->setDCPText("1");
		break;
	}
	case SetDO:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(0, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem2 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(-12, 35);
		downItem2->setPos(12, 35);
		downItem1->setDCPText("0");
		downItem2->setDCPText("1");
		break;
	}
	case RelMove:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(0, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem2 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(-12, 35);
		downItem2->setPos(12, 35);
		downItem1->setDCPText("成功");
		downItem2->setDCPText("失败");
		break;
	}
	case Move:
	{
        BodyQGraphicsItem* bodyItem = new BodyQGraphicsItem(0, this);
        UCPQGraphicsItem* upItem = new UCPQGraphicsItem(bodyItem);
        DCPQGraphicsItem* downItem1 = new DCPQGraphicsItem(bodyItem);
		upItem->setPos(0, -33);
		downItem1->setPos(0, 35);
		break;
	}
	default:
		break;
	}

}

void VizQGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	//painter->drawRect(boundingRect());
}

QRectF VizQGraphicsItem::boundingRect() const
{
	//return QRectF(-35, -35, 70, 70);
	return QRectF();
}

