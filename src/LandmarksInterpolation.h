//
// Created by morzh on 17.12.2019.
//

#ifndef FLAT_LANDMARKSINTERPOLATION_H
#define FLAT_LANDMARKSINTERPOLATION_H

#include <QtGui/QVector2D>
#include <src/spline_library/splines/uniform_cr_spline.h>
#include "facefeature.h"



class LandmarksInterpolation {
public:
    void interpolate( std::vector<ft::FaceFeature *> &lms, const QList<QList<QList<int>>> &indices_list);

private:

    void    placePointsEvenly(std::vector<QVector2D> &pts);
    QVector2D getPositionAtLength(UniformCRSpline<QVector2D> spline, double length_parm);
    void interpolateGroup(std::vector<ft::FaceFeature *> &vFeatures, const QList<QList<int>> &list);
    void copyVector2DToFeatures(std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, const std::vector<QVector2D>& list_vec);
    void copyFeaturesToVector2D(const std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, std::vector<QVector2D> &list_vec);
};


#endif //FLAT_LANDMARKSINTERPOLATION_H
