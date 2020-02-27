//
// Created by morzh on 17.12.2019.
//

#include <iostream>

#include "LandmarksInterpolation.h"
#include "spline_library/spline.h"


void LandmarksInterpolation::interpolate( std::vector<ft::FaceFeature *> &lms, const QList<QList<QList<int>>> &indices_list) {


    for(int idx=0; idx<indices_list.size(); ++idx){
        interpolateGroup(lms, indices_list[idx]);
    }
}

void LandmarksInterpolation::placePointsEvenly(std::vector<QVector2D> &pts) {

    NaturalSpline<QVector2D>  spline(pts);

    for (int idx=1; idx<pts.size()-1; ++idx)
        pts[idx] = getPositionAtSplineLength(spline, float(idx));
//        pts[idx] = spline.getPosition(float(idx)); /// for testing only
}


QVector2D LandmarksInterpolation::getPositionAtSplineLength(NaturalSpline<QVector2D>  &spline, float length_parm) {

    float   epsilon             =   1e-1;
    float   start               =   0;
    float   end                 =   spline.getMaxT();

    float   length_start        = 0;
    float   length_middle       = spline.arcLength(0, 0.5*(start+end));
    float   length_end          = spline.arcLength(0, end);

    while ( std::abs(length_start-length_end) > epsilon){

        if ( length_middle  > length_parm){
            length_end = length_middle;
            end = 0.5f*(start+end);
        }
        else {
            length_start = length_middle;
            start = 0.5f*(start+end);
        }

        length_middle  = spline.arcLength(0, 0.5*(start+end));

    }

    return spline.getPosition(0.5*(start+end));
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
