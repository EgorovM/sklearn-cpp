#include "../../include/sklearn/LinearModels/LinearRegression.h"


void LinearRegression::fit(const Matrix& X, const Matrix& y) {
    weight = Matrix(1, X.colCount());

    int max_iter = 2000;

    while(max_iter) {
        Matrix gradient = Matrix(1, X.colCount());

        for(int i = 0; i < X.rowCount(); i++) {
            double yTrue = y.getElement(i, 0);
            double yPred = (X[i] * weight.T()).getElement(0, 0);

            for (int j = 0; j < X.colCount(); j++) {
                gradient.setElement(0, j, gradient.getElement(0, j) - 2 * (yTrue - yPred) * X.getElement(i, j));
            }
        }

        for(int j = 0; j < X.colCount(); j++) {
            weight = weight - gradient * (learning_rate / double(X.rowCount()));
        }

        max_iter--;
    }

}

Matrix LinearRegression::predict(const Matrix& X) const {
    Matrix result = X * weight.T();

    return X * weight.T();
}