//
// Created by Мичил Егоров on 01.01.2022.
//

#include "../../include/sklearn/Metrics/MeanSquaredError.h"

double MeanSquaredError::operator()(const Matrix& targets, const Matrix& outputs) const {
    assert(targets.rowCount() == outputs.rowCount());

    double mse = 0;

    for(int i = 0; i < targets.rowCount(); i++) {
        mse += pow(targets.getElement(i, 0) - outputs.getElement(i, 0), 2);
    }

    return mse / targets.rowCount();
}