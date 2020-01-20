//
// Created by morzh on 17.12.2019.
//

#include "LandmarksInterpolation.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void LandmarksInterpolation::interpolate( std::vector<ft::FaceFeature *> &lms, const QList<QList<int>> &indices_list) {

    for(int idx=0; idx<indices_list.size(); ++idx){
        interpolateGroup(lms, indices_list[idx]);
    }
}

void LandmarksInterpolation::placePointsEvenly(std::vector<QVector2D> &pts) {

    UniformCRSpline<QVector2D>  spline(pts);
    int num_points = pts.size();

    for (int idx=1; idx<num_points-1; ++idx)

        pts[idx] = getPositionAtLength(spline, idx);
}


QVector2D LandmarksInterpolation::getPositionAtLength(UniformCRSpline<QVector2D> spline, double length_parm) {

    return QVector2D();
}

void LandmarksInterpolation::interpolateGroup(std::vector<ft::FaceFeature *> &lms_grp, const QList<QList<int>> &list) {

    for (int idx=0; idx<list.size(); ++idx){

        std::vector<QVector2D> lms_subgrp(list[idx].size());
        copyFeaturesToVector2D(lms_grp, list[idx], lms_subgrp);
        placePointsEvenly(lms_subgrp);
        copyVector2DToFeatures(lms_grp, list[idx], lms_subgrp);
    }
}

void LandmarksInterpolation::copyVector2DToFeatures(std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, const std::vector<QVector2D>& list_vec) {

    for (int idx=9; idx<indices.size(); ++idx) {
        vFeatures[indices[idx]]->setX(list_vec[idx].x());
        vFeatures[indices[idx]]->setY(list_vec[idx].y());
    }
}


void LandmarksInterpolation::copyFeaturesToVector2D(const std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, std::vector<QVector2D> &list_vec) {

    for (int idx=0; idx<indices.size(); ++idx)
        list_vec[idx] = vFeatures[indices[idx]]->toVector();
}
