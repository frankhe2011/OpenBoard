

#ifndef UBMAINWINDOW_H_
#define UBMAINWINDOW_H_

#include <QMainWindow>
#include <QWidget>

class QStackedLayout;

#include "ui_mainWindow.h"

class UBMainWindow : public QMainWindow, public Ui::MainWindow
{
    public:

        UBMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
        virtual ~UBMainWindow();

        void addBoardWidget(QWidget *pWidget);
        void switchToBoardWidget();

        void addWebWidget(QWidget *pWidget);
        void switchToWebWidget();

        void addDocumentsWidget(QWidget *pWidget);
        void switchToDocumentsWidget();

    protected:

        virtual void keyPressEvent(QKeyEvent *event);

        virtual QMenu* createPopupMenu ()
        {
            // no pop up on toolbar
            return 0;
        }

        QStackedLayout* mStackedLayout;

        QWidget *mBoardWidget;
        QWidget *mWebWidget;
        QWidget *mDocumentsWidget;

};

#endif /* UBMAINWINDOW_H_ */