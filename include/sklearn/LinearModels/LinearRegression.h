//
// Created by Мичил Егоров on 01.01.2022.
//

#ifndef SKLEARN_C___LINEARREGRESSION_H
#define SKLEARN_C___LINEARREGRESSION_H

#include "../Base/BaseEstimator.h"

class LinearRegression {
public:
    LinearRegression() = default;
    LinearRegression(float lr) : learning_rate(lr){};
    void fit(const Matrix&, const Matrix&);
    Matrix predict(const Matrix&) const;
private:
    float learning_rate{0.001};
    Matrix weight;
};
#endif //SKLEARN_C___LINEARREGRESSION_H
