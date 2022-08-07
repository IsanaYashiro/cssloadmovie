#pragma once

#include <QObject>
#include <QGraphicsItem>

#include "common.h"

class UCPQGrphicsCurveLineItem;

/** ucp : up connect point*/  
class UCPQGraphicsItem : public QGraphicsItem
{
public:
    UCPQGraphicsItem(QGraphicsItem*parent = nullptr);
	//~LxGraphicsUCPItem();

	enum { Type = UserType + 2 };
	int type()const override { return Type; };

    void addLine(UCPQGrphicsCurveLineItem* line) { mlist_Line.push_back(line); };
    void removeLine(UCPQGrphicsCurveLineItem* line) { mlist_Line.removeAll(line); };

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
	QRectF boundingRect() const override;

private:
    QList<UCPQGrphicsCurveLineItem*> mlist_Line;   ///< 一个ucp 可能有多条line 进入

};

/** dcp : down connect point */
class DCPQGraphicsItem : public QGraphicsItem
{
public:
    DCPQGraphicsItem(QGraphicsItem*parent = nullptr);
	//~LxGraphicsDCPItem();
	void setDCPText(QString text);
	void clearLine() { mp_line = nullptr; };
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
	QRectF boundingRect() const override;


	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
	QString mstr_text = "";
	QPointF mt_startPt, mt_endPt;
    UCPQGrphicsCurveLineItem* mp_line = nullptr;   ///< 一个dcp 只有一条line 出去
};


/** curve line*/
class UCPQGrphicsCurveLineItem :public QGraphicsItem
{
public:
    UCPQGrphicsCurveLineItem(DCPQGraphicsItem* srcItem, UCPQGraphicsItem*dstItem,QGraphicsItem*parent=nullptr);

	enum {Type = UserType + 1};
	int type()const override { return Type;  };

	void setSrcDstPt(QPointF srcPt, QPointF dstPt) { mt_srcPt = srcPt; mt_dstPt = dstPt; mb_valid = true; update(); };
    void setDstItem(UCPQGraphicsItem* dstItem) { mp_dstItem = dstItem; };

    DCPQGraphicsItem* getSrcItem() { return mp_srcItem; };
    UCPQGraphicsItem* getDstItem() { return mp_dstItem; };
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
	QRectF boundingRect() const override;

private:
    DCPQGraphicsItem* mp_srcItem;
    UCPQGraphicsItem* mp_dstItem;
	QPointF mt_srcPt, mt_dstPt;
	bool mb_valid = false;             ///< line 是否有效,当有起点和终点的时候才为有效
};



/**body item */ 
class BodyQGraphicsItem : public QGraphicsItem
{
public:
    BodyQGraphicsItem(int shape=0,QGraphicsItem*parent=nullptr);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
	QRectF boundingRect() const override;


private:
	int mn_shape=0; ///< 0 rect,1 circle
};

/** viz item */
class VizQGraphicsItem : public QGraphicsItem
{
public:
    VizQGraphicsItem(lxQVizItemType itemType,QGraphicsItem*parent = nullptr);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
	QRectF boundingRect() const override;

};



// vis item 
//class LxGraphicsVisItem : public QGraphicsItem
//{
//public:
//	LxGraphicsVisItem(QGraphicsItem*parent = nullptr);
//
//protected:
//	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */) override;
//	QRectF boundingRect() const override;
//};
