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
    enum ActivationType getActivationType() const;

    /**  Applies activation function on input.*/
    Matrix operator()(const Matrix &input) const;

private:
    enum ActivationType activationType;

    /** Applies Relu activation function on input.*/
    Matrix _relu(const Matrix &input) const;

    /** Applies Softmax activation function on input.*/
    Matrix _softmax(const Matrix &input) const;
};

#endif //ACTIVATION_H
