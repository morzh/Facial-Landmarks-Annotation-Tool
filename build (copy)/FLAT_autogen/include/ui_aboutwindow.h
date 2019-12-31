/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *vLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *hLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->setWindowModality(Qt::ApplicationModal);
        AboutWindow->resize(425, 268);
        AboutWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        AboutWindow->setModal(true);
        gridLayout_2 = new QGridLayout(AboutWindow);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        vLayout = new QVBoxLayout();
        vLayout->setSpacing(10);
        vLayout->setObjectName(QStringLiteral("vLayout"));
        scrollArea = new QScrollArea(AboutWindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 394, 331));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label->setOpenExternalLinks(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        vLayout->addWidget(scrollArea);

        hLayout = new QHBoxLayout();
        hLayout->setSpacing(0);
        hLayout->setObjectName(QStringLiteral("hLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(AboutWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMaximumSize(QSize(80, 16777215));

        hLayout->addWidget(closeButton);


        vLayout->addLayout(hLayout);


        gridLayout_2->addLayout(vLayout, 0, 0, 1, 1);


        retranslateUi(AboutWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), AboutWindow, SLOT(accept()));

        closeButton->setDefault(true);


        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "About...", Q_NULLPTR));
        label->setText(QApplication::translate("AboutWindow", "<html><head/><body><p><span style=\" font-weight:600;\">FLAT - Facial Landmarks Annotation Tool (version %1)</span></p><p>Copyright (C) 2016 <a href=\"http://www.luiz.vieira.nom.br/\"><span style=\" text-decoration: underline; color:#0000ff;\">Luiz Carlos Vieira</span></a></p><p>This is a visual editor to help annotating face images with facial landmarks required for the implementation of deformable fit algorithms or avatar transposition. The source code is available <a href=\"https://github.com/luigivieira/Facial-Landmarks-Annotation-Tool\"><span style=\" text-decoration: underline; color:#0000ff;\">at Github</span></a>.</p><p>The application icons and images are either from or based on the Oxygen Icons Set, downloaded as <a href=\"https://github.com/pasnox/oxygen-icons-png\"><span style=\" text-decoration: underline; color:#0000ff;\">PNGs from Felipe Azevedo (pasnox)</span></a> and <a href=\"https://techbase.kde.org/Projects/Oxygen/Licensing\"><span style=\" text-decoration: underline; color:#0000ff;\">licen"
                        "sed under LGPL from KDE</span></a>, and the <a href=\"http://www.fatcow.com/free-icons\"><span style=\" text-decoration: underline; color:#0000ff;\">Farm-Fresh Web Icons Set</span></a>, licensed under <a href=\"http://creativecommons.org/licenses/by/4.0/\"><span style=\" text-decoration: underline; color:#0000ff;\">Creative Commons (CC BY 4.0)</span></a>.</p><p>LICENSE</p><p>This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.</p><p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.</p><p>You should have received a copy of the GNU General Public License along with this program. If not, see <a href=\"http://www.gnu.org/licenses/\"><span style=\" tex"
                        "t-decoration: underline; color:#0000ff;\">http://www.gnu.org/licenses/</span></a>.</p></body></html>", Q_NULLPTR));
        closeButton->setText(QApplication::translate("AboutWindow", "&Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
