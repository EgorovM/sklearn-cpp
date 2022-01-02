//
// Created by Мичил Егоров on 02.01.2022.
//

#include <iostream>
#include "../include/sklearn/LinearModels/LogisticRegression.h"
#include "../include/sklearn/Metrics/AccuracyScore.h"

int main() {
    Matrix X({
                     {1, 0, 1, 0, 0},
                     {0, 1, 1, 1, 0},
                     {0, 0, 1, 0, 0},
             });
    Matrix y({
                     {1},
                     {1},
                     {0},
             });

    LogisticRegression lr;

    lr.fit(X, y);
    Matrix result = lr.predict(X);

    std::cout << AccuracyScore()(y, result); // 0.666667

    return 0;
}
