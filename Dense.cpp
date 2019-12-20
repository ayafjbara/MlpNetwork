//
// Created by Aya on 12/15/2019.
//

#include "Dense.h"

Dense::Dense(Matrix &w, Matrix &bias, ActivationType activationType)
{
    this->activationType = activationType;
    this->bias = bias;
    this->weight = w;
}

Matrix Dense::getWeights() const
{
    return weight;
}

Matrix Dense::getBias() const
{
    return bias;
}

ActivationType Dense::getActivation() const
{
    return activationType;
}

Matrix Dense::operator()(const Matrix &input)
{
    Matrix dense = weight * input + bias;
    return dense;
}


