//
// Created by morzh on 29.11.2019.
//

#ifndef FLAT_LANDMARKSPROPERTIES_H
#define FLAT_LANDMARKSPROPERTIES_H

#include "ui_landmarksproperties.h"

#include <QDialog>

namespace Ui {

    class LandmarksProperties;

}

namespace ft
{
    /**
     * Form class used to display the about dialog box.
     */
    class LandmarksProperties : public QDialog
    {
    Q_OBJECT

    public:
        /**
         * Class constructor.
         * @param pParent QWidget with the window parent.
         */
        explicit LandmarksProperties(QWidget *pParent = 0);

        /**
         * Class destructor
         */
        virtual ~LandmarksProperties();

    private:
        /** Instance of the ui for GUI element access. */
        Ui::LandmarksProperties *ui;
    };
}
#endif //FLAT_LANDMARKSPROPERTIES_H
