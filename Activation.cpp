#include "Activation.h"

/**
 * @param actType Relu/Softmax
 */
Activation::Activation(ActivationType actType)
{
    activationType = actType;
}

/**
 * @return activation type.
 */
enum ActivationType Activation::getActivationType() const
{
    return activationType;
}

/**  Applies activation function on input.*/
Matrix Activation::operator()(const Matrix &input) const
{
    switch (activationType)
    {
        case Relu:
            return _relu(input);
        case Softmax:
            return _softmax(input);
    }
    cerr << "ERROR: Activation::operator(); wrong activation type." << endl;
    exit(1);
}

/** Applies Relu activation function on input.*/
Matrix Activation::_relu(const Matrix &input) const
{
    Matrix reluMat(input);

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

/** Applies Softmax activation function on input.*/
Matrix Activation::_softmax(const Matrix &input) const
{
    Matrix softmaxMat(input);
    float divisor = 0;

    for (int i = 0; i < softmaxMat.getRows(); ++i)
    {
        for (int j = 0; j < softmaxMat.getCols(); ++j)
        {
            float expCoor = exp(softmaxMat(i, j));
            softmaxMat(i, j) = expCoor;
            divisor += expCoor;
        }
    }

    return ((float) (1 / divisor) * softmaxMat);
}


