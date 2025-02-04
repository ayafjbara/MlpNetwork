// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>


using namespace std;
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 * Matrix class
 */
class Matrix
{
public:
    /**
     * @param rows number
     * @param cols number
     */
    Matrix(int rows, int cols);

    /**
     * @param matrix1 - matrix to copy
     */
    Matrix(const Matrix &matrix1);

    /** Constructs 1×1 Matrix. */
    Matrix();

    /** Destructor */
    ~Matrix();

    /**
     * @return num of rows
     */
    int getRows() const;

    /**
     * @return num of columns
     */
    int getCols() const;

    /**
     * Transforms a matrix into a column vector.
     * @return transformed vector.
     */
    Matrix &vectorize();

    /**
     * Prints matrix elements
     */
    void plainPrint() const;

    /** a = b */
    Matrix &operator=(const Matrix &other);

    /** a + b */
    Matrix operator+(const Matrix &a) const;

    /** a * b */
    Matrix operator*(const Matrix &a) const;

    /** (Matrix * scalar) */
    Matrix operator*(float c) const;

    /** a += other */
    Matrix &operator+=(const Matrix &other);

    /** value of matrix(i, j) */
    float operator()(int i, int j) const;

    /** reference of matrix(i,j) */
    float &operator()(int i, int j);

    /** value of matrix[i] */
    float operator[](int i) const;

    /** reference of matrix[i] */
    float &operator[](int i);

    /** Fills matrix elements */
    friend ifstream &operator>>(ifstream &is, Matrix &m);

    /** output stream */
    friend ostream &operator<<(ostream &os, const Matrix &m);

    /** (scalar * Matrix) */
    friend Matrix operator*(float c, const Matrix &a);

private:
    struct MatrixDims matrixDims;
    float* matrix;

    /** print error msg and exit(1)*/
    void _printError(string errorMsg) const;
};

#endif //MATRIX_H
