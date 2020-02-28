//
// Created by morzh on 17.12.2019.
//

#ifndef FLAT_LANDMARKSINTERPOLATION_H
#define FLAT_LANDMARKSINTERPOLATION_H

#include <QtGui/QVector2D>
#include <src/spline_library/splines/natural_spline.h>
#include "facefeature.h"



class LandmarksInterpolation {
public:
    void interpolate( std::vector<ft::FaceFeature *> &lms, const QList<QList<QList<int>>> &indices_list);

private:

    void        placePointsEvenly           (std::vector<QVector2D> &pts);
    QVector2D   getPositionAtSplineLength         (NaturalSpline<QVector2D>  &spline, float length_normalized);
    void        interpolateGroup            (std::vector<ft::FaceFeature *> &vFeatures, const QList<QList<int>> &list);
    void        copyVector2DToFeatures      (std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, const std::vector<QVector2D>& lms_subgrp);
    void        copyFeaturesToVector2D      (const std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, std::vector<QVector2D> &list_vec);

    template <typename T>
    int         sgn                         (T val) {
        return (T(0) < val) - (val < T(0));
    }
};


#endif //FLAT_LANDMARKSINTERPOLATION_H
