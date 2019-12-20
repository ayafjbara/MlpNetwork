//
// Created by Aya on 12/15/2019.
//

#include <iostream>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    matrixDims.cols = cols;
    matrixDims.rows = rows;
    matrix = new float[rows * cols];
}

Matrix::Matrix(const Matrix &m) {
    matrixDims.rows = m.getRows();
    matrixDims.cols = m.getCols();
    matrix = new float[matrixDims.rows * matrixDims.cols];
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            matrix[i * matrixDims.cols + j] = m(i, j);
        }
    }
}

Matrix::Matrix() {
    matrixDims.cols = 1;
    matrixDims.rows = 1;
    matrix = new float[1];
}

int Matrix::getRows() const {
    return this->matrixDims.rows;
}

int Matrix::getCols() const {
    return this->matrixDims.cols;
}

Matrix &Matrix::vectorize() {
    matrixDims.rows *= matrixDims.cols;
    matrixDims.cols = 1;
    return *this;
}

void Matrix::plainPrint() const {
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            cout << getValue(i, j);
            if (j != matrixDims.cols - 1)
                cout << " ";
            else
                cout << "\n";
        }
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other)
    {

        matrixDims.rows = other.getRows();
        matrixDims.cols = other.getCols();
        delete[] matrix; //todo
        matrix = new float[matrixDims.rows * matrixDims.cols];
        for (int i = 0; i < matrixDims.rows; ++i)
        {
            for (int j = 0; j < matrixDims.cols; ++j)
            {
                matrix[i * matrixDims.cols + j] = other(i, j);
            }
        }
    }
    return *this;
}


Matrix Matrix::operator+(const Matrix &a) const {
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    Matrix addMatrix = *new Matrix(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            addMatrix(i, j) = getValue(i, j) + a(i, j);

    return addMatrix;
}

Matrix &Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < matrixDims.rows; ++i)
        for (int j = 0; j < matrixDims.cols; ++j)
            matrix[i * matrixDims.cols + j] += other(i, j);

    return *this;
}

float Matrix::operator()(int i, int j) const {
    return getValue(i, j);
}

float Matrix::operator[](int i) const {
    return matrix[i];
}


ifstream &operator>>(ifstream &is, Matrix &m) {

    for (int i = 0; i < m.getRows(); ++i)
    {
        for (int j = 0; j < m.getCols(); ++j)
        {
            if (is.good())
            {
                float f;
                is.read(reinterpret_cast<char *>(&f), sizeof(float));
                m(i, j) = f;
            } else
            {
                cerr << "ERROR: " << endl;
                exit(1);
            }
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &m) {
    for (int i = 0; i < m.getRows(); ++i)
    {
        for (int j = 0; j < m.getCols(); ++j)
        {
            if (m(i, j) <= 0.1)
            {
                os << "  ";
            } else
            {
                os << "**";
            }
        }
        os << "\n";
    }
    os << "\n";
    return os;
}

Matrix Matrix::operator*(const Matrix &a) const {
    int rows = matrixDims.rows;
    int cols = a.getCols();
    Matrix multiMatrix = *new Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < matrixDims.cols; k++)
                multiMatrix(i, j) += getValue(i, k) * a(k, j);

    return multiMatrix;
}

/**
 * (Matrix * scalar)
 */
Matrix Matrix::operator*(float c) const {
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    Matrix multiMatrix = *new Matrix(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            multiMatrix(i, j) = c * getValue(i, j);
        }
    }
    return multiMatrix;
}

/**
 * (scalar * Matrix)
 */
Matrix operator*(float c, const Matrix &a) {
    return a * c;
}


float &Matrix::operator()(int i, int j) {
    return matrix[i * matrixDims.cols + j];
}

float Matrix::getValue(int i, int j) const {
    return matrix[i * matrixDims.cols + j];
}
