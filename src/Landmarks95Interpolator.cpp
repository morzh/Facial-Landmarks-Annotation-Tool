//
// Created by morzh on 17.12.2019.
//

#include "Landmarks95Interpolator.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void Landmarks95Interpolator::interpolate(std::vector<ft::FaceFeature*> vFeauters) {

    interpolate_ovLow(vFeauters);
    interpolate_ovUpper(vFeauters);
    interpolate_rBrow(vFeauters);
    interpolate_lBrow(vFeauters);
    interpolate_rEye(vFeauters);
    interpolate_lEye(vFeauters);

}

std::vector<QVector2D> Landmarks95Interpolator::placePointsEvenly(const std::vector<QVector2D> &pts) {

    UniformCRSpline<QVector2D> mySpline(pts);
    QVector2D interpolatedPosition = mySpline.getPosition(0.5f);


}


void Landmarks95Interpolator::interpolate_ovLow(std::vector<ft::FaceFeature *> vFeauters) {

    std::vector<QVector2D> ovalLow(16);

    for (int idx=0; idx<17; ++idx){
        ovalLow[idx] = vFeauters[idx]->toVector();
    }

    ovalLow = placePointsEvenly(ovalLow);

}

void Landmarks95Interpolator::interpolate_ovUpper(std::vector<ft::FaceFeature *> vFeauters) {

}

void Landmarks95Interpolator::interpolate_rBrow(std::vector<ft::FaceFeature *> vFeauters) {

}

void Landmarks95Interpolator::interpolate_lBrow(std::vector<ft::FaceFeature *> vFeauters) {

}

void Landmarks95Interpolator::interpolate_rEye(std::vector<ft::FaceFeature *> vFeatures) {

}

void Landmarks95Interpolator::interpolate_lEye(std::vector<ft::FaceFeature *> vFeatures) {

}
