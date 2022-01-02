//
// Created by Мичил Егоров on 02.01.2022.
//

#include <iostream>
#include "../../include/sklearn/LinearModels/LogisticRegression.h"

void LogisticRegression::fit(const Matrix& X, const Matrix& y, int max_iter) {
    weight = Matrix(1, X.colCount());

    while(max_iter) {
        Matrix gradient = Matrix(1, X.colCount());

        for(int q = 0; q < 10; q++) {
            int i = rand() % X.rowCount();

            double yTrue = y.getElement(i, 0);
            double yPred = (X[i] * weight.T()).getElement(0, 0);
            double logit = 1 / (1 + exp(-yPred));

            for (int j = 0; j < X.colCount(); j++) {
                gradient.setElement(0, j, gradient.getElement(0, j) - (yTrue - logit) * X.getElement(i, j));
            }
        }

        for(int j = 0; j < X.colCount(); j++) {
            weight = weight - gradient * (learning_rate / double(X.rowCount()));
        }

        max_iter--;
    }
}

Matrix LogisticRegression::predict(const Matrix& X) const {
    Matrix result(X.rowCount(), 1);
    Matrix regressors = X * weight.T();
    for(int i = 0; i < X.rowCount(); i++) {
        double logit = 1 / (1 + exp(-regressors.getElement(i, 0)));
        result.setElement(i, 0, logit > 0.5 ? 1 : 0);
    }
    return result;
}