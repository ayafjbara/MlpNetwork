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

/**
 * Activation class
 */
class Activation
{
public:
    /**
     * @param actType Relu/Softmax
     */
    Activation(ActivationType actType);

    /**
     * @return activation type.
     */
    enum ActivationType getActivationType();

    /**  Applies activation function on input.*/
    Matrix operator()(const Matrix &input);

private:
    enum ActivationType activationType;

    /** Applies Relu activation function on input.*/
    Matrix _relu(const Matrix &input);

    /** Applies Softmax activation function on input.*/
    Matrix _softmax(const Matrix &input);
};

#endif //ACTIVATION_H
