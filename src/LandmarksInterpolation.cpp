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
        pts[idx] = spline.getPosition(float(idx)); /// for testing only
}


QVector2D LandmarksInterpolation::getPositionAtLength(NaturalSpline<QVector2D>  &spline, float length_parm) {

    float   parm_max            =   spline.getMaxT();
    float   total_length        =   spline.totalLength();
    float   parm_normalized     =   length_parm / parm_max;
    float   length_fraction     =   total_length * parm_normalized;
    float   epsilon             =   1e-2;
    float   len                 =   spline.arcLength(0.0, length_parm);
    float   segment_start       =   0;
    float   segment_end         =   1;

    /// first, find segment, at which desired point is located
    for (int idx=0; idx<1000; ++idx) {

        if (std::abs(len - length_fraction) < epsilon)
            return spline.getPosition(len);

        int signum = sgn<float>(len - length_fraction);
        length_parm += 0.1 * signum;
        len = spline.arcLength(0.0, length_parm);
    }

    /// second, iteratively (dihotomy method) find spline parameter at which length is equal to length_fraction

    return spline.getPosition(len);
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
