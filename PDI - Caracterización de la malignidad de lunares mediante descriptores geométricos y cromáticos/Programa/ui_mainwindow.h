/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "myqgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_imagen;
    QAction *actionBarras_Horizontales;
    QAction *actionExportar_datos;
    QWidget *centralWidget;
    myQGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label_6;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    myQGraphicsView *graphicsView_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_4;
    QDateEdit *dateEdit;
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(827, 631);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(221, 221, 221, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionAbrir_imagen = new QAction(MainWindow);
        actionAbrir_imagen->setObjectName(QStringLiteral("actionAbrir_imagen"));
        actionBarras_Horizontales = new QAction(MainWindow);
        actionBarras_Horizontales->setObjectName(QStringLiteral("actionBarras_Horizontales"));
        actionExportar_datos = new QAction(MainWindow);
        actionExportar_datos->setObjectName(QStringLiteral("actionExportar_datos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new myQGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(420, 10, 400, 400));
        graphicsView->setMaximumSize(QSize(400, 400));
        graphicsView->setMouseTracking(true);
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(370, 460, 111, 31));
        QPalette palette1;
        QBrush brush2(QColor(151, 199, 225, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        QBrush brush4(QColor(137, 208, 229, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        pushButton->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("Khmer UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
        pushButton->setCheckable(false);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(570, 430, 131, 21));
        QPalette palette2;
        QBrush brush6(QColor(17, 11, 189, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_6->setPalette(palette2);
        QFont font1;
        font1.setFamily(QStringLiteral("Khmer UI"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(720, 490, 64, 31));
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(720, 520, 64, 31));
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(720, 550, 64, 31));
        lcdNumber_3->setFrameShadow(QFrame::Sunken);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_4 = new QLCDNumber(centralWidget);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(720, 460, 64, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        lcdNumber_4->setPalette(palette3);
        lcdNumber_4->setFrameShadow(QFrame::Sunken);
        lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 520, 111, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        pushButton_2->setPalette(palette4);
        QFont font2;
        font2.setFamily(QStringLiteral("Khmer UI"));
        font2.setPointSize(10);
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(370, 490, 111, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        pushButton_3->setPalette(palette5);
        pushButton_3->setFont(font2);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(370, 550, 111, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        pushButton_4->setPalette(palette6);
        pushButton_4->setFont(font2);
        graphicsView_2 = new myQGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 10, 400, 400));
        graphicsView_2->setMaximumSize(QSize(400, 400));
        graphicsView_2->setMouseTracking(true);
        graphicsView_2->setFrameShape(QFrame::NoFrame);
        graphicsView_2->setFrameShadow(QFrame::Plain);
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(580, 460, 111, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        pushButton_5->setPalette(palette7);
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 490, 111, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        pushButton_6->setPalette(palette8);
        pushButton_6->setFont(font);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 520, 111, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        pushButton_7->setPalette(palette9);
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(580, 550, 111, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        pushButton_8->setPalette(palette10);
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(710, 410, 111, 23));
        QPalette palette11;
        QBrush brush7(QColor(156, 179, 241, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(84, 103, 227, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush8);
        QBrush brush9(QColor(255, 0, 4, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush10(QColor(0, 170, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        pushButton_9->setPalette(palette11);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 430, 151, 21));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_7->setPalette(palette12);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 470, 121, 20));
        lineEdit->setMaxLength(32767);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 430, 151, 21));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_8->setPalette(palette13);
        QFont font3;
        font3.setFamily(QStringLiteral("Khmer UI"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 470, 111, 21));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_9->setPalette(palette14);
        QFont font4;
        font4.setFamily(QStringLiteral("Khmer UI"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 500, 111, 21));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_10->setPalette(palette15);
        label_10->setFont(font4);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 500, 121, 20));
        lineEdit_2->setMaxLength(32767);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 530, 111, 21));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_11->setPalette(palette16);
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 560, 111, 21));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        label_12->setPalette(palette17);
        label_12->setFont(font4);
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 530, 121, 20));
        lineEdit_4->setMaxLength(32767);
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 560, 121, 22));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(300, 430, 20, 151));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(530, 430, 20, 151));
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setFrameShape(QFrame::VLine);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 827, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir_imagen);
        menuArchivo->addAction(actionExportar_datos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbrir_imagen->setText(QApplication::translate("MainWindow", "Abrir imagen", 0));
        actionBarras_Horizontales->setText(QApplication::translate("MainWindow", "Barras Horizontales", 0));
        actionExportar_datos->setText(QApplication::translate("MainWindow", "Exportar datos", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Binarizaci\303\263n", 0));
        label_6->setText(QApplication::translate("MainWindow", "Indicadores", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Erosi\303\263n", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Dilataci\303\263n", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Crec. regi\303\263n", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Di\303\241metro", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Simetr\303\255a", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Borde", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Color", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "Restablecer imagen", 0));
        label_7->setText(QApplication::translate("MainWindow", "Preprocesamiento", 0));
        label_8->setText(QApplication::translate("MainWindow", "Datos paciente", 0));
        label_9->setText(QApplication::translate("MainWindow", "Nombre:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Apellido:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Edad:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Fecha analisis:", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
