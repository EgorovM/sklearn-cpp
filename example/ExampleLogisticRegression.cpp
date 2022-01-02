#include <iostream>
#include "../include/sklearn/LinearModels/LogisticRegression.h"
#include "../include/sklearn/Metrics/AccuracyScore.h"
#include "../include/utils/CsvReader.h"

int main() {
    CsvReader csv("../data/breast.csv");
    Matrix result = csv.read();
    Matrix X(result.rowCount(), result.colCount() - 1);
    Matrix y(result.rowCount(), 1);

    for(int i = 0; i < result.rowCount(); i++) {
        for(int j = 0; j < result.colCount(); j++) {
            if(j == result.colCount() - 1) {
                y.setElement(i, 0, result.getElement(i, j));
            }else{
                X.setElement(i, j, result.getElement(i, j));
            }
        }
    }

    LogisticRegression lr;

    lr.fit(X, y);

    std::cout << AccuracyScore()(lr.predict(X), y);  // 0.917399

    return 0;
}
