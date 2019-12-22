//
// Created by Aya on 12/15/2019.
//

#ifndef C___DENSE_H
#define C___DENSE_H


#include "Activation.h"

/**
 * Dense class
 */
class Dense
{
public:
    /**
     * Inits layer.
     * @param w weight
     * @param bias
     * @param activationType
     */
    Dense(Matrix &w, Matrix &bias, ActivationType activationType);

    /**
     * @return weights of this layer.
     */
    Matrix getWeights() const;

    /**
     * @return bias of this layer.
     */
    Matrix getBias() const;

    /**
     * @return activation of this layer.
     */
    ActivationType getActivation() const;

    /**
     * Applies the layer on input.
     */
    Matrix operator()(const Matrix &input) const;

private:

    ActivationType activationType;
    Matrix weight;
    Matrix bias;
};


#endif //C___DENSE_H
