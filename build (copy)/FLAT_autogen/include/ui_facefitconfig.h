/********************************************************************************
** Form generated from reading UI file 'facefitconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEFITCONFIG_H
#define UI_FACEFITCONFIG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FaceFitConfig
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pathEdit;
    QToolButton *pathButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FaceFitConfig)
    {
        if (FaceFitConfig->objectName().isEmpty())
            FaceFitConfig->setObjectName(QStringLiteral("FaceFitConfig"));
        FaceFitConfig->resize(391, 76);
        FaceFitConfig->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        verticalLayout = new QVBoxLayout(FaceFitConfig);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(FaceFitConfig);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        pathEdit = new QLineEdit(FaceFitConfig);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));

        horizontalLayout_2->addWidget(pathEdit);

        pathButton = new QToolButton(FaceFitConfig);
        pathButton->setObjectName(QStringLiteral("pathButton"));

        horizontalLayout_2->addWidget(pathButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(FaceFitConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FaceFitConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), FaceFitConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FaceFitConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(FaceFitConfig);
    } // setupUi

    void retranslateUi(QDialog *FaceFitConfig)
    {
        FaceFitConfig->setWindowTitle(QApplication::translate("FaceFitConfig", "Configuration of the face-fit utility", Q_NULLPTR));
        label->setText(QApplication::translate("FaceFitConfig", "Path to the face-fit utility:", Q_NULLPTR));
        pathButton->setText(QApplication::translate("FaceFitConfig", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FaceFitConfig: public Ui_FaceFitConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEFITCONFIG_H
