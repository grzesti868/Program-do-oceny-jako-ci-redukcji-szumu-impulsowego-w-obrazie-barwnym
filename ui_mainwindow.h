/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *image;
    QPushButton *buttonLoad;
    QLabel *image2;
    QSpinBox *spinBox;
    QLabel *image3;
    QLabel *toolText;
    QPushButton *filterButton;
    QLabel *image4;
    QGroupBox *radMap;
    QRadioButton *rad1;
    QRadioButton *rad2;
    QRadioButton *rad3;
    QPushButton *btnSaveMap;
    QPushButton *btnShowMap;
    QLabel *imgMaeChart;
    QGroupBox *radFiltr;
    QRadioButton *radVMF;
    QRadioButton *radPGF;
    QRadioButton *radTEST;
    QLabel *lbPSNR;
    QLabel *descPSNR;
    QLabel *lbMSE;
    QLabel *descMSE;
    QLabel *lbMAE;
    QLabel *descMAE;
    QLabel *descTP;
    QLabel *lbTP;
    QLabel *lbTN;
    QLabel *descTN;
    QLabel *lbFP;
    QLabel *descFP;
    QLabel *lbFN;
    QLabel *descFN;
    QLabel *descACC;
    QLabel *lbACC;
    QPushButton *btnSaveCorr;
    QPushButton *btnSaveFix;
    QPushButton *loadCorr;
    QPushButton *loadFixed;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1699, 823);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"font: 87 8pt \"Arial Black\";"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget->setAutoFillBackground(false);
        image = new QLabel(centralWidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(660, 0, 511, 321));
        image->setFrameShape(QFrame::Box);
        buttonLoad = new QPushButton(centralWidget);
        buttonLoad->setObjectName(QString::fromUtf8("buttonLoad"));
        buttonLoad->setGeometry(QRect(30, 10, 141, 51));
        image2 = new QLabel(centralWidget);
        image2->setObjectName(QString::fromUtf8("image2"));
        image2->setGeometry(QRect(1180, 0, 511, 321));
        image2->setFrameShape(QFrame::Box);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setGeometry(QRect(140, 70, 51, 51));
        spinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        image3 = new QLabel(centralWidget);
        image3->setObjectName(QString::fromUtf8("image3"));
        image3->setGeometry(QRect(1180, 330, 511, 321));
        image3->setFrameShape(QFrame::Box);
        toolText = new QLabel(centralWidget);
        toolText->setObjectName(QString::fromUtf8("toolText"));
        toolText->setEnabled(true);
        toolText->setGeometry(QRect(20, 70, 111, 51));
        toolText->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolText->setFrameShape(QFrame::NoFrame);
        toolText->setFrameShadow(QFrame::Plain);
        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setGeometry(QRect(10, 490, 151, 41));
        image4 = new QLabel(centralWidget);
        image4->setObjectName(QString::fromUtf8("image4"));
        image4->setGeometry(QRect(660, 330, 511, 321));
        image4->setFrameShape(QFrame::Box);
        radMap = new QGroupBox(centralWidget);
        radMap->setObjectName(QString::fromUtf8("radMap"));
        radMap->setGeometry(QRect(0, 130, 201, 211));
        radMap->setContextMenuPolicy(Qt::DefaultContextMenu);
        radMap->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        rad1 = new QRadioButton(radMap);
        rad1->setObjectName(QString::fromUtf8("rad1"));
        rad1->setGeometry(QRect(10, 30, 181, 21));
        rad2 = new QRadioButton(radMap);
        rad2->setObjectName(QString::fromUtf8("rad2"));
        rad2->setGeometry(QRect(10, 60, 131, 22));
        rad3 = new QRadioButton(radMap);
        rad3->setObjectName(QString::fromUtf8("rad3"));
        rad3->setGeometry(QRect(10, 80, 91, 31));
        btnSaveMap = new QPushButton(radMap);
        btnSaveMap->setObjectName(QString::fromUtf8("btnSaveMap"));
        btnSaveMap->setEnabled(false);
        btnSaveMap->setGeometry(QRect(20, 160, 141, 41));
        btnShowMap = new QPushButton(radMap);
        btnShowMap->setObjectName(QString::fromUtf8("btnShowMap"));
        btnShowMap->setEnabled(false);
        btnShowMap->setGeometry(QRect(20, 110, 141, 41));
        imgMaeChart = new QLabel(centralWidget);
        imgMaeChart->setObjectName(QString::fromUtf8("imgMaeChart"));
        imgMaeChart->setGeometry(QRect(200, 0, 450, 450));
        imgMaeChart->setFrameShape(QFrame::Box);
        radFiltr = new QGroupBox(centralWidget);
        radFiltr->setObjectName(QString::fromUtf8("radFiltr"));
        radFiltr->setGeometry(QRect(10, 340, 181, 151));
        radVMF = new QRadioButton(radFiltr);
        radVMF->setObjectName(QString::fromUtf8("radVMF"));
        radVMF->setGeometry(QRect(10, 30, 81, 22));
        radPGF = new QRadioButton(radFiltr);
        radPGF->setObjectName(QString::fromUtf8("radPGF"));
        radPGF->setGeometry(QRect(10, 60, 71, 22));
        radTEST = new QRadioButton(radFiltr);
        radTEST->setObjectName(QString::fromUtf8("radTEST"));
        radTEST->setGeometry(QRect(10, 90, 171, 61));
        lbPSNR = new QLabel(centralWidget);
        lbPSNR->setObjectName(QString::fromUtf8("lbPSNR"));
        lbPSNR->setGeometry(QRect(200, 480, 81, 31));
        lbPSNR->setFrameShape(QFrame::Box);
        descPSNR = new QLabel(centralWidget);
        descPSNR->setObjectName(QString::fromUtf8("descPSNR"));
        descPSNR->setGeometry(QRect(200, 450, 81, 31));
        descPSNR->setAlignment(Qt::AlignCenter);
        lbMSE = new QLabel(centralWidget);
        lbMSE->setObjectName(QString::fromUtf8("lbMSE"));
        lbMSE->setGeometry(QRect(290, 480, 81, 31));
        lbMSE->setFrameShape(QFrame::Box);
        descMSE = new QLabel(centralWidget);
        descMSE->setObjectName(QString::fromUtf8("descMSE"));
        descMSE->setGeometry(QRect(290, 450, 81, 31));
        descMSE->setAlignment(Qt::AlignCenter);
        lbMAE = new QLabel(centralWidget);
        lbMAE->setObjectName(QString::fromUtf8("lbMAE"));
        lbMAE->setGeometry(QRect(380, 480, 81, 31));
        lbMAE->setFrameShape(QFrame::Box);
        descMAE = new QLabel(centralWidget);
        descMAE->setObjectName(QString::fromUtf8("descMAE"));
        descMAE->setGeometry(QRect(380, 450, 81, 31));
        descMAE->setAlignment(Qt::AlignCenter);
        descTP = new QLabel(centralWidget);
        descTP->setObjectName(QString::fromUtf8("descTP"));
        descTP->setGeometry(QRect(190, 520, 101, 21));
        descTP->setAlignment(Qt::AlignCenter);
        lbTP = new QLabel(centralWidget);
        lbTP->setObjectName(QString::fromUtf8("lbTP"));
        lbTP->setGeometry(QRect(200, 550, 81, 31));
        lbTP->setFrameShape(QFrame::Box);
        lbTN = new QLabel(centralWidget);
        lbTN->setObjectName(QString::fromUtf8("lbTN"));
        lbTN->setGeometry(QRect(310, 550, 81, 31));
        lbTN->setFrameShape(QFrame::Box);
        descTN = new QLabel(centralWidget);
        descTN->setObjectName(QString::fromUtf8("descTN"));
        descTN->setGeometry(QRect(300, 520, 101, 21));
        descTN->setAlignment(Qt::AlignCenter);
        lbFP = new QLabel(centralWidget);
        lbFP->setObjectName(QString::fromUtf8("lbFP"));
        lbFP->setGeometry(QRect(430, 550, 81, 31));
        lbFP->setFrameShape(QFrame::Box);
        descFP = new QLabel(centralWidget);
        descFP->setObjectName(QString::fromUtf8("descFP"));
        descFP->setGeometry(QRect(420, 520, 101, 21));
        descFP->setAlignment(Qt::AlignCenter);
        lbFN = new QLabel(centralWidget);
        lbFN->setObjectName(QString::fromUtf8("lbFN"));
        lbFN->setGeometry(QRect(550, 550, 81, 31));
        lbFN->setFrameShape(QFrame::Box);
        descFN = new QLabel(centralWidget);
        descFN->setObjectName(QString::fromUtf8("descFN"));
        descFN->setGeometry(QRect(530, 520, 121, 21));
        descFN->setAlignment(Qt::AlignCenter);
        descACC = new QLabel(centralWidget);
        descACC->setObjectName(QString::fromUtf8("descACC"));
        descACC->setGeometry(QRect(510, 450, 101, 31));
        descACC->setAlignment(Qt::AlignCenter);
        lbACC = new QLabel(centralWidget);
        lbACC->setObjectName(QString::fromUtf8("lbACC"));
        lbACC->setGeometry(QRect(520, 480, 81, 31));
        lbACC->setFrameShape(QFrame::Box);
        btnSaveCorr = new QPushButton(centralWidget);
        btnSaveCorr->setObjectName(QString::fromUtf8("btnSaveCorr"));
        btnSaveCorr->setEnabled(false);
        btnSaveCorr->setGeometry(QRect(10, 540, 151, 41));
        btnSaveCorr->setToolTipDuration(0);
        btnSaveFix = new QPushButton(centralWidget);
        btnSaveFix->setObjectName(QString::fromUtf8("btnSaveFix"));
        btnSaveFix->setEnabled(false);
        btnSaveFix->setGeometry(QRect(10, 590, 151, 41));
        btnSaveFix->setToolTipDuration(0);
        loadCorr = new QPushButton(centralWidget);
        loadCorr->setObjectName(QString::fromUtf8("loadCorr"));
        loadCorr->setGeometry(QRect(10, 640, 151, 51));
        loadFixed = new QPushButton(centralWidget);
        loadFixed->setObjectName(QString::fromUtf8("loadFixed"));
        loadFixed->setGeometry(QRect(10, 700, 151, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1699, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        image->setText(QString());
        buttonLoad->setText(QApplication::translate("MainWindow", "Za\305\202aduj zdj\304\231cie", nullptr));
        image2->setText(QString());
        image3->setText(QString());
        toolText->setText(QApplication::translate("MainWindow", "Procentowy\n"
"poziom\n"
"zaszumienia\n"
"", nullptr));
        filterButton->setText(QApplication::translate("MainWindow", "Odfiltruj zdj\304\231cie", nullptr));
        image4->setText(QString());
        radMap->setTitle(QApplication::translate("MainWindow", "Poka\305\274 map\304\231:", nullptr));
        rad1->setText(QApplication::translate("MainWindow", "Orgina\305\202 = Uszkodzony", nullptr));
        rad2->setText(QApplication::translate("MainWindow", "Estymowana", nullptr));
        rad3->setText(QApplication::translate("MainWindow", "Detekcji", nullptr));
        btnSaveMap->setText(QApplication::translate("MainWindow", "Zapisz obraz mapy", nullptr));
        btnShowMap->setText(QApplication::translate("MainWindow", "Poka\305\274 map\304\231", nullptr));
        imgMaeChart->setText(QString());
        radFiltr->setTitle(QApplication::translate("MainWindow", "Wybierz filtr", nullptr));
        radVMF->setText(QApplication::translate("MainWindow", "VMF", nullptr));
        radPGF->setText(QApplication::translate("MainWindow", "PGF", nullptr));
        radTEST->setText(QApplication::translate("MainWindow", "TEST - oblicza  z \n"
"wczytanych \n"
"obraz\303\263w", nullptr));
        lbPSNR->setText(QString());
        descPSNR->setText(QApplication::translate("MainWindow", "PSNR", nullptr));
        lbMSE->setText(QString());
        descMSE->setText(QApplication::translate("MainWindow", "MSE", nullptr));
        lbMAE->setText(QString());
        descMAE->setText(QApplication::translate("MainWindow", "MAE", nullptr));
        descTP->setText(QApplication::translate("MainWindow", "True Positive", nullptr));
        lbTP->setText(QString());
        lbTN->setText(QString());
        descTN->setText(QApplication::translate("MainWindow", "True Negative", nullptr));
        lbFP->setText(QString());
        descFP->setText(QApplication::translate("MainWindow", "False Posivite", nullptr));
        lbFN->setText(QString());
        descFN->setText(QApplication::translate("MainWindow", "False Negative", nullptr));
        descACC->setText(QApplication::translate("MainWindow", "Accuracy", nullptr));
        lbACC->setText(QString());
        btnSaveCorr->setText(QApplication::translate("MainWindow", "Zapisz zdj\304\231cie  \n"
"uszkodzone", nullptr));
        btnSaveFix->setText(QApplication::translate("MainWindow", "Zapisz  zdj\304\231cie\n"
"odfiltorwane", nullptr));
        loadCorr->setText(QApplication::translate("MainWindow", "Wczytaj zdj\304\231cie \n"
"uszkodzone", nullptr));
        loadFixed->setText(QApplication::translate("MainWindow", "Wczytaj zdj\304\231cie\n"
"odfiltrowane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
