//
// Created by Aya on 12/15/2019.
//

#include <cmath>
#include "Activation.h"

Activation::Activation(ActivationType actType)
{
    activationType = actType;
}

enum ActivationType Activation::getActivationType()
{
    return activationType;
}

Matrix Activation::operator()(const Matrix &input)
{
    switch (activationType)
    {
        case Relu:
            return relu(input);
        case Softmax:
            return softmax(input);
    }
}

Matrix Activation::relu(const Matrix &input)
{
    Matrix reluMat = Matrix(input);

    for (int i = 0; i < reluMat.getRows(); ++i)
    {
        for (int j = 0; j < reluMat.getCols(); ++j)
        {
            if (reluMat(i, j) < 0)
            {
                reluMat(i, j) = 0;
            }

        }
    }
    return reluMat;
}

Matrix Activation::softmax(const Matrix &input)
{
    Matrix softmaxMat = Matrix(input);

    float divisor = 0;

    for (int i = 0; i < softmaxMat.getRows(); ++i)
    {
        for (int j = 0; j < softmaxMat.getCols(); ++j)
        {
            divisor += exp(softmaxMat(i, j));
        }
    }

    return softmaxMat * (1 / divisor);
}


