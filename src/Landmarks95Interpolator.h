//
// Created by morzh on 17.12.2019.
//

#ifndef FLAT_LANDMARKS95INTERPOLATOR_H
#define FLAT_LANDMARKS95INTERPOLATOR_H

#include <QtGui/QVector2D>
#include <src/spline_library/splines/uniform_cr_spline.h>
#include "facefeature.h"



class Landmarks95Interpolator {
public:
    void    interpolate(const std::vector<ft::FaceFeature*>&);

private:
    void    interpolate_ovLow(const std::vector<ft::FaceFeature*>& vFeatures);
    void    interpolate_ovUpper(const std::vector<ft::FaceFeature*>& vFeatures);

    void    interpolate_rBrow(const std::vector<ft::FaceFeature*>& vFeatures);
    void    interpolate_lBrow(const std::vector<ft::FaceFeature*>& vFeatures);

    void    interpolate_rEye(const std::vector<ft::FaceFeature *>& vFeatures);
    void    interpolate_lEye(const std::vector<ft::FaceFeature *>& vFeatures );

    void    placePointsEvenly(std::vector<QVector2D> &pts);

    void interpolate_noseRidge(const std::vector<ft::FaceFeature *> &vector);

    void interpolate_noseShape(const std::vector<ft::FaceFeature *> &vector);

    QVector2D getPositionAtLength(UniformCRSpline<QVector2D> spline, double length_parm);
};


#endif //FLAT_LANDMARKS95INTERPOLATOR_H
