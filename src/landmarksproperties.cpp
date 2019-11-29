//
// Created by morzh on 29.11.2019.
//

#include <QtGui>
#include "landmarksproperties.h"
#include "version.h"


// +-----------------------------------------------------------
ft::LandmarksProperties::LandmarksProperties(QWidget *pParent) :
        QDialog(pParent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
        ui(new Ui::LandmarksProperties)
{
    ui->setupUi(this);
    ui->table->setHorizontalHeaderLabels(  QStringList() << "start idx" << "end idx" << "size" << "color" << "color selected");
    ui->table->setVerticalHeaderLabels(  QStringList() << "oval lower" << "oval upper" << "brow left" << "brow right" << "eye left" << "eye right" <<
                                                        "nose ridge" << "nose shape" << "mouth outer" << "mouth inner");

//    ui->table->resizeColumnsToContents();
//    ui->table->resizeRowsToContents();
}

// +-----------------------------------------------------------
ft::LandmarksProperties::~LandmarksProperties()
{
    delete ui;
}
