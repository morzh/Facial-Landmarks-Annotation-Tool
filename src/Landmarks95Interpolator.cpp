//
// Created by morzh on 17.12.2019.
//

#include "Landmarks95Interpolator.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void Landmarks95Interpolator::interpolate(std::vector<ft::FaceFeature*>) {

}

std::vector<QVector2D> Landmarks95Interpolator::interpolate_points(const std::vector<QVector2D> &pts, int pts_num) {

    UniformCRSpline<QVector2D> mySpline(pts);
    QVector2D interpolatedPosition = mySpline.getPosition(0.5f);


}
