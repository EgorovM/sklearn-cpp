//
// Created by Мичил Егоров on 01.01.2022.
//

#include "../../include/sklearn/Metrics/AccuracyScore.h"

double AccuracyScore::operator()(const Matrix& targets, const Matrix& outputs) const {
    assert(targets.rowCount() == outputs.rowCount());

    int equalCount = 0;

    for(int i = 0; i < targets.rowCount(); i++) {
        equalCount += targets.getElement(i, 0) == outputs.getElement(i, 0);
    }

    return equalCount / double(targets.rowCount());
}