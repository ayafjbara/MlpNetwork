// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims {
    int rows, cols;
} MatrixDims;

// Insert Matrix class here...
class Matrix {
public:
    Matrix(int rows, int cols);

    Matrix(Matrix &m);

    Matrix();

    ~Matrix();

    int getRows();

    int getCols();

    void vectorize();

    void plainPrint();

    Matrix &operator=(const Matrix &other);

    Matrix operator+(const Matrix &a);

    Matrix operator*(const Matrix &a);

    Matrix operator*(float c);

    Matrix &operator+=(const Matrix &other);

    float operator()(int i, int j);

    float operator[](int i);

    Matrix &operator>>(const Matrix &other);

    Matrix &operator<<(const Matrix &other);

private:
    struct MatrixDims matrixDims;
};

#endif //MATRIX_H
