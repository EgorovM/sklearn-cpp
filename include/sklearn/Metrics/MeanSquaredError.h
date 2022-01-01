//
// Created by Мичил Егоров on 01.01.2022.
//

#ifndef SKLEARN_C___MEANSQUAREDERROR_H
#define SKLEARN_C___MEANSQUAREDERROR_H

#include "../../sklearn/base/BaseMetric.h"

class MeanSquaredError {
public:
    double operator()(const Matrix&, const Matrix&) const;
};

#endif //SKLEARN_C___MEANSQUAREDERROR_H
