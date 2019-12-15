//
// Created by Aya on 12/15/2019.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {

}

Matrix::Matrix(Matrix &m) {

}

Matrix::Matrix() {

}

int Matrix::getRows() {
    return 0;
}

int Matrix::getCols() {
    return 0;
}

void Matrix::vectorize() {

}

void Matrix::plainPrint() {

}

Matrix &Matrix::operator=(const Matrix &other) {
    return <#initializer#>;
}

Matrix Matrix::operator+(const Matrix &a) {
    return Matrix();
}

Matrix &Matrix::operator+=(const Matrix &other) {
    return <#initializer#>;
}

float Matrix::operator()(int i, int j) {
    return 0;
}

float Matrix::operator[](int i) {
    return 0;
}

Matrix &Matrix::operator>>(const Matrix &other) {
    return <#initializer#>;
}

Matrix &Matrix::operator<<(const Matrix &other) {
    return <#initializer#>;
}

Matrix Matrix::operator*(const Matrix &a) {
    return Matrix();
}

Matrix Matrix::operator*(float c) {
    return Matrix();
}

