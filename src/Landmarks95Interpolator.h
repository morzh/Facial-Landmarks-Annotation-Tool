//
// Created by morzh on 17.12.2019.
//

#ifndef FLAT_LANDMARKS95INTERPOLATOR_H
#define FLAT_LANDMARKS95INTERPOLATOR_H

#include <QtGui/QVector2D>
#include "facefeature.h"



class Landmarks95Interpolator {
public:
    void interpolate(std::vector<ft::FaceFeature*>);

private:
    void interpolate_ovLow();
    void interpolate_ovUpper();
    void interpolate_rBrow();
    void interpolate_lBrow();

    std::vector<QVector2D> interpolate_points(const std::vector<QVector2D> &pts, int pts_num);
};


#endif //FLAT_LANDMARKS95INTERPOLATOR_H
