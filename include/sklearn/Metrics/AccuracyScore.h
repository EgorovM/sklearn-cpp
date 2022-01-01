//
// Created by Мичил Егоров on 01.01.2022.
//

#ifndef SKLEARN_C___ACCURACY_H
#define SKLEARN_C___ACCURACY_H

#include "../../sklearn/base/BaseMetric.h"

class AccuracyScore {
    double operator()(const Matrix&, const Matrix&) const;
};

#endif //SKLEARN_C___ACCURACY_H
