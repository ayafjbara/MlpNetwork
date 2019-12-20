//
// Created by Aya on 12/15/2019.
//

#include "Dense.h"

/**
 * Inits layer.
 * @param w weight
 * @param bias
 * @param activationType
 */
Dense::Dense(Matrix &w, Matrix &bias, ActivationType activationType)
{
    this->activationType = activationType;
    this->bias = bias;
    this->weight = w;
}

/**
 * @return weights of this layer.
 */
Matrix Dense::getWeights() const
{
    return weight;
}

/**
 * @return bias of this layer.
 */
Matrix Dense::getBias() const
{
    return bias;
}

/**
 * @return activation of this layer.
 */
ActivationType Dense::getActivation() const
{
    return activationType;
}

/**
 * Applies the layer on input.
 */
Matrix Dense::operator()(const Matrix &input)
{
    Matrix dense = weight * input + bias;
    return dense;
}


