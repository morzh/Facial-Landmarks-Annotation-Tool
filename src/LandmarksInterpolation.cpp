//
// Created by morzh on 17.12.2019.
//

#include <iostream>
#include "LandmarksInterpolation.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void LandmarksInterpolation::interpolate( std::vector<ft::FaceFeature *> &lms, const QList<QList<QList<int>>> &indices_list) {


    for(int idx=0; idx<indices_list.size(); ++idx){
        interpolateGroup(lms, indices_list[idx]);
    }
}

void LandmarksInterpolation::placePointsEvenly(std::vector<QVector2D> &pts) {

    UniformCRSpline<QVector2D>  spline(pts);
    int num_points = pts.size();

    for (int idx=1; idx<pts.size()-1; ++idx) {
        pts[idx] = spline.getPosition(float(idx)) ; /// for testing only
    }
//    for (auto pt:pts){ std::cout << pt.x() << " " << pt.y() <<"  ;;;;;" ;} std::cout << std::endl;
}


QVector2D LandmarksInterpolation::getPositionAtLength(UniformCRSpline<QVector2D> spline, double length_parm) {

    return QVector2D();
}

void LandmarksInterpolation::interpolateGroup(std::vector<ft::FaceFeature *> &vFeatures, const QList<QList<int>> &list) {



    for (int idx=0; idx<list.size(); ++idx){
        std::vector<QVector2D> lms_subgrp(list[idx].size());
        copyFeaturesToVector2D(vFeatures, list[idx], lms_subgrp);
        placePointsEvenly(lms_subgrp);
        copyVector2DToFeatures(vFeatures, list[idx], lms_subgrp);
    }
}

void LandmarksInterpolation::copyVector2DToFeatures(std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, const std::vector<QVector2D>& lms_subgrp) {

    for (int idx=0; idx<indices.size(); ++idx) {
        vFeatures[indices[idx]]->setX(lms_subgrp[idx].x());
        vFeatures[indices[idx]]->setY(lms_subgrp[idx].y());
    }
}


void LandmarksInterpolation::copyFeaturesToVector2D(const std::vector<ft::FaceFeature *> &vFeatures, const QList<int> &indices, std::vector<QVector2D> &list_vec) {

    for (int idx=0; idx<indices.size(); ++idx) {
        list_vec[idx]  =  vFeatures[indices[idx]]->toVector() ;
    }
}
