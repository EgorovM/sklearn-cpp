//
// Created by Мичил Егоров on 02.01.2022.
//

#include "../../include/sklearn/LinearModels/LogisticRegression.h"

void LogisticRegression::fit(const Matrix& X, const Matrix& y, int max_iter) {
    weight = Matrix(1, X.colCount());

    while(max_iter) {
        Matrix gradient = Matrix(1, X.colCount());

        for(int i = 0; i < X.rowCount(); i++) {
            double yTrue = y.getElement(i, 0);
            double yPred = (weight.T() * X[i]).getElement(0, 0);
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
    Matrix logits = X * weight.T();
    for(int i = 0; i < X.rowCount(); i++) {
        result.setElement(i, 0, logits.getElement(i, 0) > 0.5 ? 1 : 0);
    }
    return result;
}