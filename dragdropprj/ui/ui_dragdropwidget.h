/********************************************************************************
** Form generated from reading UI file 'dragdropwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGDROPWIDGET_H
#define UI_DRAGDROPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QUndoView>
#include <QtWidgets/QWidget>
#include "dragdropqgraphicsview.h"
#include "itemqtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_DragDropWidget
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QSplitter *splitter;
    ItemQTreeWidget *treeWidget;
    QUndoView *undoView;
    DragDropQGraphicsView *graphicsView;
    QGroupBox *groupBox;

    void setupUi(QWidget *DragDropWidget)
    {
        if (DragDropWidget->objectName().isEmpty())
            DragDropWidget->setObjectName(QString::fromUtf8("DragDropWidget"));
        DragDropWidget->resize(915, 624);
        gridLayout = new QGridLayout(DragDropWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_3 = new QSplitter(DragDropWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        treeWidget = new ItemQTreeWidget(splitter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->setDragEnabled(true);
        treeWidget->setIndentation(10);
        treeWidget->setHeaderHidden(true);
        splitter->addWidget(treeWidget);
        undoView = new QUndoView(splitter);
        undoView->setObjectName(QString::fromUtf8("undoView"));
        splitter->addWidget(undoView);
        splitter_2->addWidget(splitter);
        graphicsView = new DragDropQGraphicsView(splitter_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        splitter_2->addWidget(graphicsView);
        splitter_3->addWidget(splitter_2);
        groupBox = new QGroupBox(splitter_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        splitter_3->addWidget(groupBox);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);


        retranslateUi(DragDropWidget);

        QMetaObject::connectSlotsByName(DragDropWidget);
    } // setupUi

    void retranslateUi(QWidget *DragDropWidget)
    {
        DragDropWidget->setWindowTitle(QCoreApplication::translate("DragDropWidget", "DragDropWidget", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("DragDropWidget", "1", nullptr));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class DragDropWidget: public Ui_DragDropWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGDROPWIDGET_H
