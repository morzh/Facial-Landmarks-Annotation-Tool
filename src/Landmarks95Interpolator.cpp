//
// Created by morzh on 17.12.2019.
//

#include "Landmarks95Interpolator.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void Landmarks95Interpolator::interpolate(const std::vector<ft::FaceFeature*>& vFeauters) {

    interpolate_ovLow(vFeauters);
    interpolate_ovUpper(vFeauters);
    interpolate_rBrow(vFeauters);
    interpolate_lBrow(vFeauters);
    interpolate_rEye(vFeauters);
    interpolate_lEye(vFeauters);
    interpolate_noseRidge(vFeauters);
    interpolate_noseShape(vFeauters);

}

void Landmarks95Interpolator::placePointsEvenly(std::vector<QVector2D> &pts) {

    UniformCRSpline<QVector2D>  spline(pts);
    int num_points = pts.size();

    for (int idx=1; idx<num_points-1; ++idx)

        pts[idx] = getPositionAtLength(spline, idx);
}


void Landmarks95Interpolator::interpolate_ovLow(const std::vector<ft::FaceFeature *>& vFeatures) {

    std::vector<QVector2D> ovalLowRight(8);
    std::vector<QVector2D> ovalLowLeft(8);

    for (int idx=0; idx<8; ++idx)
        ovalLowRight[idx] = vFeatures[idx]->toVector();
    for (int idx=8; idx<17; ++idx)
        ovalLowLeft[idx-8] = vFeatures[idx]->toVector();

    placePointsEvenly(ovalLowRight);
    placePointsEvenly(ovalLowLeft);

    for (int idx=0; idx<7; ++idx) {
        vFeatures[idx]->setX(ovalLowRight[idx].x());
        vFeatures[idx]->setY(ovalLowRight[idx].y());
    }
    for (int idx=9; idx<17; ++idx) {
        vFeatures[idx]->setX(ovalLowLeft[idx-8].x());
        vFeatures[idx]->setY(ovalLowLeft[idx-8].y());
    }

}

void Landmarks95Interpolator::interpolate_ovUpper(const std::vector<ft::FaceFeature *>& vFeatures) {

}

void Landmarks95Interpolator::interpolate_rBrow(const std::vector<ft::FaceFeature *>& vFeatures) {

}

void Landmarks95Interpolator::interpolate_lBrow(const std::vector<ft::FaceFeature *>& vFeatures) {

}

void Landmarks95Interpolator::interpolate_rEye(const std::vector<ft::FaceFeature *>& vFeatures) {

}

void Landmarks95Interpolator::interpolate_lEye(const std::vector<ft::FaceFeature *>& vFeatures) {

}

void Landmarks95Interpolator::interpolate_noseRidge(const std::vector<ft::FaceFeature *> &vector) {

}

void Landmarks95Interpolator::interpolate_noseShape(const std::vector<ft::FaceFeature *> &vector) {

}

QVector2D Landmarks95Interpolator::getPositionAtLength(UniformCRSpline<QVector2D> spline, double length_parm) {

    return QVector2D();
}
