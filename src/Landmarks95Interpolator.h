//
// Created by morzh on 17.12.2019.
//

#ifndef FLAT_LANDMARKS95INTERPOLATOR_H
#define FLAT_LANDMARKS95INTERPOLATOR_H

#include <QtGui/QVector2D>
#include "facefeature.h"



class Landmarks95Interpolator {
public:
    void interpolate(std::vector<ft::FaceFeature*>);

private:
    void                    interpolate_ovLow(std::vector<ft::FaceFeature*> vFeauters);
    void                    interpolate_ovUpper(std::vector<ft::FaceFeature*> vFeauters);

    void                    interpolate_rBrow(std::vector<ft::FaceFeature*> vFeauters);
    void                    interpolate_lBrow(std::vector<ft::FaceFeature*> vFeauters);

    void                    interpolate_rEye(std::vector<ft::FaceFeature *> vFeatures);
    void                    interpolate_lEye(std::vector<ft::FaceFeature *> vFeatures );

    std::vector<QVector2D>  placePointsEvenly(const std::vector<QVector2D> &pts);
};


#endif //FLAT_LANDMARKS95INTERPOLATOR_H
