//
// Created by Мичил Егоров on 01.01.2022.
//

#ifndef SKLEARN_C___MATRIX_H
#define SKLEARN_C___MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix() = default;
    ~Matrix() = default;
    Matrix(size_t, size_t);
    Matrix(const Matrix&);
    explicit Matrix(const std::vector<std::vector<double>>&);

    double getElement(size_t, size_t) const;
    size_t rowCount() const;
    size_t colCount() const;
    Matrix T() const;

    void setElement(size_t, size_t, double);
    void swap(Matrix&);

    Matrix operator*(const Matrix&) const;
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;

    Matrix operator*(double) const;
    Matrix operator[](int) const;

    Matrix& operator=(const Matrix&);

private:
    size_t row{0};
    size_t col{0};
    std::vector<std::vector<double>>* field{nullptr};
};
#endif //SKLEARN_C___MATRIX_H
