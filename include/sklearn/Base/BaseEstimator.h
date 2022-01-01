//
// Created by Мичил Егоров on 01.01.2022.
//

#ifndef SKLEARN_C___BASEESTIMATOR_H
#define SKLEARN_C___BASEESTIMATOR_H

#include "../../utils/Matrix.h"

class BaseEstimator {
public:
    virtual void fit(const Matrix&, const Matrix&);
    virtual Matrix predict(const Matrix&) const;
};
#endif //SKLEARN_C___BASEESTIMATOR_H
