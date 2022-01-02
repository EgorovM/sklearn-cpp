//
// Created by Мичил Егоров on 02.01.2022.
//

#ifndef SKLEARN_C___LOGISTICREGRESSION_H
#define SKLEARN_C___LOGISTICREGRESSION_H

#include "../Base/BaseEstimator.h"

class LogisticRegression {
public:
    LogisticRegression() = default;
    LogisticRegression(float lr) : learning_rate(lr){};
    void fit(const Matrix&, const Matrix&, int = 1000);
    Matrix predict(const Matrix&) const;
private:
    float learning_rate{0.001};
    Matrix weight;
};

#endif //SKLEARN_C___LOGISTICREGRESSION_H
