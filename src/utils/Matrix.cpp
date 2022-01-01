//
// Created by Мичил Егоров on 01.01.2022.
//

#include "../../include/utils/Matrix.h"
#include <iostream>

Matrix::Matrix(size_t row, size_t col): row(row), col(col) {
    field = new std::vector(row, std::vector(col, .0));
}

Matrix::Matrix(const Matrix& other) {
    col = other.col;
    row = other.row;
    field = new std::vector(row, std::vector(col, .0));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            (*field)[i][j] = other.getElement(i, j);
        }
    }
}

Matrix::Matrix(const std::vector<std::vector<double>>& field) {
    col = field.empty() ? 0 : field[0].size();
    row = field.size();
    this->field = new std::vector(field);
}

size_t Matrix::rowCount() const {
    return row;
};

size_t Matrix::colCount() const {
    return col;
}

Matrix Matrix::T() const {
    Matrix transponsedMatrix(col, row);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            transponsedMatrix.setElement(j, i, getElement(i, j));
        }
    }
    return transponsedMatrix;
}

double Matrix::getElement(size_t y, size_t x) const {
    assert(y >= 0 && y < row);
    assert(x >= 0 && x < col);

    return (*field)[y][x];
}

void Matrix::setElement(size_t y, size_t x, double val) {
    assert(y >= 0 && y < row);
    assert(x >= 0 && x < col);

    (*field)[y][x] = val;
}

void Matrix::swap(Matrix& other) {
    std::swap(other.col, col);
    std::swap(other.row, row);
    std::swap(other.field, field);
}

Matrix& Matrix::operator=(const Matrix& other) {
    Matrix tmp(other);
    tmp.swap(*this);
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    assert(row == other.row);
    assert(col == other.col);

    Matrix resultMatrix(row, col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < row; j++) {
            (*resultMatrix.field)[i][j] = getElement(i, j) + other.getElement(i, j);
        }
    }
    return resultMatrix;
}

Matrix Matrix::operator-(const Matrix& other) const {
    assert(row == other.row);
    assert(col == other.col);

    Matrix resultMatrix(row, col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            (*resultMatrix.field)[i][j] = getElement(i, j) - other.getElement(i, j);
        }
    }
    return resultMatrix;
}

Matrix Matrix::operator*(const Matrix& other) const {
    assert(col == other.row);

    Matrix resultMatrix(row, other.col);

    for(int i = 0; i < row; i++) {
        for (int j = 0; j < other.col; j++) {
            // TODO: save the row and col sums
            for (int k = 0; k < col; k++) {
                resultMatrix.setElement(i, j, resultMatrix.getElement(i, j) + getElement(i, k) * other.getElement(k, j));
            }
        }
    }

    return resultMatrix;
}

Matrix Matrix::operator*(double val) const {
    Matrix resultMatrix(row, col);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            resultMatrix.setElement(i, j, val * getElement(i, j));
        }
    }
    return resultMatrix;
}

Matrix Matrix::operator[](int y) const {
    assert(y >= 0 && y < row);
    auto rowField = std::vector(1, std::vector((*field)[y]));
    Matrix rowMatrix(rowField);
    return rowMatrix;
}