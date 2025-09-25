/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QListWidget *musicList;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *prebtn;
    QPushButton *playbtn;
    QPushButton *nextbtn;
    QPushButton *modebtn;
    QPushButton *listbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(484, 464);
        MainWindow->setStyleSheet(QString::fromUtf8("QpushButton{\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:blue;\n"
"}"));
        MainWindow->setDocumentMode(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalSpacer = new QSpacerItem(330, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);

        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");

        horizontalLayout_2->addWidget(musicList);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        prebtn = new QPushButton(centralwidget);
        prebtn->setObjectName("prebtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/music_icons/last.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prebtn->setIcon(icon);

        horizontalLayout->addWidget(prebtn);

        playbtn = new QPushButton(centralwidget);
        playbtn->setObjectName("playbtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/music_icons/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playbtn->setIcon(icon1);

        horizontalLayout->addWidget(playbtn);

        nextbtn = new QPushButton(centralwidget);
        nextbtn->setObjectName("nextbtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/music_icons/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextbtn->setIcon(icon2);

        horizontalLayout->addWidget(nextbtn);

        modebtn = new QPushButton(centralwidget);
        modebtn->setObjectName("modebtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/music_icons/random.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modebtn->setIcon(icon3);

        horizontalLayout->addWidget(modebtn);

        listbtn = new QPushButton(centralwidget);
        listbtn->setObjectName("listbtn");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/music_icons/playlist.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        listbtn->setIcon(icon4);

        horizontalLayout->addWidget(listbtn);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 484, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        prebtn->setText(QString());
        playbtn->setText(QString());
        nextbtn->setText(QString());
        modebtn->setText(QString());
        listbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
