// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
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

// Insert Matrix class here...
class Matrix
{
public:
    Matrix(int rows, int cols);

    Matrix(const Matrix &m);

    Matrix();

    ~Matrix() {};//todo

    int getRows() const;

    int getCols() const;

    Matrix &vectorize();

    void plainPrint() const;

    Matrix &operator=(const Matrix &other);

    Matrix operator+(const Matrix &a) const;

    Matrix operator*(const Matrix &a) const;

    Matrix operator*(float c) const;

    Matrix &operator+=(const Matrix &other);

    float operator()(int i, int j) const;

    float &operator()(int i, int j) ;

    float operator[](int i) const;

    friend ifstream &operator>>(ifstream &is, Matrix &m);

    friend ostream &operator<<(ostream &os, const Matrix &m);

    friend Matrix operator*(float c, const Matrix &a);

private:
    struct MatrixDims matrixDims;
    float *matrix;

    float getValue(int i, int j) const;
};

#endif //MATRIX_H
