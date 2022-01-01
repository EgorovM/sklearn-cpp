#include <iostream>
#include "../include/sklearn/LinearModels/LinearRegression.h"

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

    for(int i = 0; i < result.rowCount(); i++) {
        std::cout << result.getElement(i, 0) << std::endl;
    }

    return 0;
}
