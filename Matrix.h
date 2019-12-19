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

    Matrix(Matrix &m);

    Matrix();

    ~Matrix()
    {}

    int getRows() const;

    int getCols() const;

    Matrix &vectorize();

    void plainPrint() const;

    Matrix &operator=(const Matrix &other);

    Matrix operator+(const Matrix &a) const;

    Matrix operator*(const Matrix &a) const;

    Matrix operator*(float c) const;

    Matrix &operator+=(const Matrix &other);

    void setValue(int i, int j, float val);

    float operator()(int i, int j) const;

    float operator[](int i) const;

    friend ifstream &operator>>(ifstream &is, Matrix &m);

    friend ostream &operator<<(ostream &os, const Matrix &m);

    friend Matrix operator*(float c, const Matrix &a);

    vector<vector<float>> getMatrix() const;

private:
    struct MatrixDims matrixDims;
    vector<vector<float >> matrix;

    Matrix(vector<vector<float>> &matrix, int rows, int cols);

    void setMatrix(vector<vector<float>> matrix);
};

#endif //MATRIX_H
