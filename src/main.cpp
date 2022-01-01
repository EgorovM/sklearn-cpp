#include <iostream>
#include "../include/sklearn/LinearModels/LinearRegression.h"
#include "../include/sklearn/Metrics/MeanSquaredError.h"

int main() {
    Matrix X({
         {1, 0, 0},
         {0, 1, 0},
         {0, 0, 1},
    });
    Matrix y({
        {1},
        {2},
        {3},
    });

    LinearRegression lr;

    lr.fit(X, y);
    Matrix result = lr.predict(X);

    std::cout << MeanSquaredError()(y, result); // 0.001553

    return 0;
}
