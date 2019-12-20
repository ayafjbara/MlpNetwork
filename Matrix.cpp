//
// Created by Aya on 12/15/2019.
//

#include "Matrix.h"

/**
 * @param rows number
 * @param cols number
 */
Matrix::Matrix(int rows, int cols)
{
    matrixDims.cols = cols;
    matrixDims.rows = rows;
    matrix = new float[rows * cols];
}

/**
 * @param matrix1 - matrix to copy
 */
Matrix::Matrix(const Matrix &matrix1)
{
    matrixDims.rows = matrix1.getRows();
    matrixDims.cols = matrix1.getCols();
    matrix = new float[matrixDims.rows * matrixDims.cols];
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            matrix[i * matrixDims.cols + j] = matrix1(i, j);
        }
    }
}

/** Constructs 1×1 Matrix. */
Matrix::Matrix()
{
    matrixDims.cols = 1;
    matrixDims.rows = 1;
    matrix = new float[1];
}

/**
 * @return num of rows
 */
int Matrix::getRows() const
{
    return this->matrixDims.rows;
}

/**
 * @return num of columns
 */
int Matrix::getCols() const
{
    return this->matrixDims.cols;
}

/**
 * Transforms a matrix into a column vector.
 * @return transformed vector.
 */
Matrix &Matrix::vectorize()
{
    matrixDims.rows *= matrixDims.cols;
    matrixDims.cols = 1;
    return *this;
}

/**
 * Prints matrix elements
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            cout << _getValue(i, j);
            if (j != matrixDims.cols - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
}

/** a = b */
Matrix &Matrix::operator=(const Matrix &other)
{
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

/** a + b */
Matrix Matrix::operator+(const Matrix &a) const
{
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    Matrix addMatrix(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            addMatrix(i, j) = _getValue(i, j) + a(i, j);
        }
    }
    return addMatrix;
}

/** a += other */
Matrix &Matrix::operator+=(const Matrix &other)
{
    for (int i = 0; i < matrixDims.rows; ++i)
    {
        for (int j = 0; j < matrixDims.cols; ++j)
        {
            matrix[i * matrixDims.cols + j] += other(i, j);
        }
    }
    return *this;
}

/** value of a(i, j) */
float Matrix::operator()(int i, int j) const
{
    return _getValue(i, j);
}

/** value of a[i] */
float Matrix::operator[](int i) const
{
    return matrix[i];
}

/** Fills matrix elements */
ifstream &operator>>(ifstream &is, Matrix &m)
{

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

/** output stream */
ostream &operator<<(ostream &os, const Matrix &m)
{
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

/** a * b */
Matrix Matrix::operator*(const Matrix &a) const
{
    int rows = matrixDims.rows;
    int cols = a.getCols();
    Matrix multiMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < matrixDims.cols; k++)
            {
                multiMatrix(i, j) += _getValue(i, k) * a(k, j);
            }
        }
    }
    return multiMatrix;
}

/**
 * (Matrix * scalar)
 */
Matrix Matrix::operator*(float c) const
{
    int rows = matrixDims.rows;
    int cols = matrixDims.cols;
    Matrix multiMatrix(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            multiMatrix(i, j) = c * _getValue(i, j);
        }
    }
    return multiMatrix;
}

/**
 * (scalar * Matrix)
 */
Matrix operator*(float c, const Matrix &a)
{
    return a * c;
}

/** reference of a(i,j) */
float &Matrix::operator()(int i, int j)
{
    return matrix[i * matrixDims.cols + j];
}

/** value of matrix(i,j)*/
float Matrix::_getValue(int i, int j) const
{
    return matrix[i * matrixDims.cols + j];
}
