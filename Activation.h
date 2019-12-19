//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

// Insert Activation class here...
class Activation
{
public:
    Activation(ActivationType actType);

    enum ActivationType getActivationType();

    Matrix operator()(const Matrix &input);

    Matrix relu(const Matrix &input);

    Matrix softmax(const Matrix &input);

private:
    enum ActivationType activationType;
};

#endif //ACTIVATION_H
