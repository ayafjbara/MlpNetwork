//
// Created by Aya on 12/15/2019.
//

#include <iostream>
#include <math.h>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    matrixDims.cols = cols;
    matrixDims.rows = rows;
    for (int i = 0; i < rows; ++i)
    {
        vector<float> row(cols, 0);
        matrix.push_back(row);
    }
}

Matrix::Matrix(Matrix &m) {
    int rows = m.getRows();
    int cols = m.getCols();
    Matrix(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = m(i, j);
}

Matrix::Matrix(vector<vector<float>> &matrix, int rows, int cols) {
    this->matrix = matrix;
    matrixDims.cols = cols;
    matrixDims.rows = rows;
}

Matrix::Matrix() {
    Matrix(1, 1);
}

int Matrix::getRows() const {
    return this->matrixDims.rows;
}

int Matrix::getCols() const {
    return this->matrixDims.cols;
}

vector<vector<float> > Matrix::getMatrix() const {
    return matrix;
}

void Matrix::setMatrix(vector<vector<float>> matrix) {
    this->matrix = matrix;
}

Matrix& Matrix::vectorize() {
    int curRows = matrixDims.rows;
    int curCols = matrixDims.cols;
    vector<vector<float >> matVector(curCols * curRows, vector<float>(1, 0));
    int idx = 0;
    for (int i = 0; i < curRows; ++i)
        for (int j = 0; j < curCols; ++j)
        {
            matVector[idx][0] = matrix[i][j];
            idx++;
        }

    matrixDims.rows *= curCols;
    matrixDims.cols = 1;
    matrix = matVector;
}

void Matrix::plainPrint() const {
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            cout << matrix[i][j];
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
        vector<vector<float >> copiedMatrix(other.getMatrix());
        matrix = copiedMatrix;
    }
    return *this;
}


Matrix Matrix::operator+(const Matrix &a) const {
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    vector<vector<float >> addMatrix(rows, vector<float>(cols, 0));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            addMatrix[i][j] = matrix[i][j] + a(i, j);

    return *new Matrix(addMatrix, rows, cols);
}

Matrix &Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < matrixDims.rows; ++i)
        for (int j = 0; j < matrixDims.cols; ++j)
            matrix[i][j] += other(i, j);
    return *this;
}

float Matrix::operator()(int i, int j) const {
    return matrix[i][j];
}

float Matrix::operator[](int i) const {
    for (int j = 0; j < matrixDims.rows; ++j)
    {
        float idx = (i - j) / matrixDims.rows;
        if (roundf(idx) == idx)
            return matrix[idx][j];
    }
}


void operator>>(ifstream &in, const Matrix &m) {
    if (in.good())
    {
        int length = m.getRows()*m.getCols();
        char *s =new char [length];
        in.read(s, length);
        cout<<s<<"\n";
    }
//    for (int i = 0; i < m.getRows(); ++i)
//    {
//        for (int j = 0; j < m.getCols(); ++j)
//            if (!(in >> m.p[i][j])) return in;
//    }
//    return in;
}

void operator<<(ostream &os, const Matrix &m) {
    cout << "Image processed :"<< "\n";
    for (int i = 0; i < m.getRows() ; ++i)
    {
        for (int j = 0; j <m.getCols() ; ++j)
        {
            if( m(i,j) <= 0.1)
            {
                cout<<"  ";
            } else{
                cout<<"**";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Mlp result: <res > at probability: <prob>";//todo res and prob
    cout<<"\n";
}

Matrix Matrix::operator*(const Matrix &a) const {
    int newMatRows = matrixDims.rows;
    int newMatCols = a.getCols();
    vector<vector<float >> multiMatrix(newMatRows, vector<float>(newMatCols, 0));
    vector<vector<float >> aMartrix = a.getMatrix();
    for (int i = 0; i < newMatRows; i++)
        for (int j = 0; j < newMatCols; j++)
            for (int k = 0; k < matrixDims.cols; k++)
                multiMatrix[i][j] += matrix[i][k] * aMartrix[k][j];

    return *new Matrix(aMartrix, newMatRows, newMatCols);
}

/**
 * (Matrix * scalar)
 */
Matrix Matrix::operator*(float c) const {
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    vector<vector<float >> multiMatrix(rows, vector<float>(cols, 0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            multiMatrix[i][j] = c * matrix[i][j];
        }
    }
    return *new Matrix(multiMatrix, rows, cols);
}

/**
 * (scalar * Matrix)
 */
Matrix operator*(float c, const Matrix &a) {
    return a * c;
}

