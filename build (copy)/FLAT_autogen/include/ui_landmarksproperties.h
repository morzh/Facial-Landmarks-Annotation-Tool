/********************************************************************************
** Form generated from reading UI file 'landmarksproperties.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANDMARKSPROPERTIES_H
#define UI_LANDMARKSPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_LandmarksProperties
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *table;

    void setupUi(QDialog *LandmarksProperties)
    {
        if (LandmarksProperties->objectName().isEmpty())
            LandmarksProperties->setObjectName(QStringLiteral("LandmarksProperties"));
        LandmarksProperties->resize(638, 391);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LandmarksProperties->sizePolicy().hasHeightForWidth());
        LandmarksProperties->setSizePolicy(sizePolicy);
        LandmarksProperties->setSizeGripEnabled(true);
        buttonBox = new QDialogButtonBox(LandmarksProperties);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 350, 351, 32));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        table = new QTableWidget(LandmarksProperties);
        if (table->columnCount() < 5)
            table->setColumnCount(5);
        if (table->rowCount() < 10)
            table->setRowCount(10);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(10, 10, 621, 321));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy2);
        table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        table->setShowGrid(true);
        table->setCornerButtonEnabled(true);
        table->setRowCount(10);
        table->setColumnCount(5);
        table->horizontalHeader()->setCascadingSectionResizes(false);
        table->horizontalHeader()->setStretchLastSection(true);
        table->verticalHeader()->setStretchLastSection(false);

        retranslateUi(LandmarksProperties);
        QObject::connect(buttonBox, SIGNAL(accepted()), LandmarksProperties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LandmarksProperties, SLOT(reject()));

        QMetaObject::connectSlotsByName(LandmarksProperties);
    } // setupUi

    void retranslateUi(QDialog *LandmarksProperties)
    {
        LandmarksProperties->setWindowTitle(QApplication::translate("LandmarksProperties", "Landmarks Properties", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LandmarksProperties: public Ui_LandmarksProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANDMARKSPROPERTIES_H
