//
// Created by morzh on 17.12.2019.
//

#include "Landmarks95Interpolator.h"
#include "spline_library/spline.h"
#include "spline_library/splines/uniform_cr_spline.h"

void Landmarks95Interpolator::interpolate(std::vector<ft::FaceFeature*>) {

}

void Landmarks95Interpolator::interpolate_points(std::vector<QVector2D> splinePoints) {

    UniformCRSpline<QVector2D> mySpline(splinePoints);
    QVector2D interpolatedPosition = mySpline.getPosition(0.5f);


}
