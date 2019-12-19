//
// Created by Aya on 12/15/2019.
//

#ifndef C___DENSE_H
#define C___DENSE_H


#include "Activation.h"

class Dense
{
public:
    Dense(Matrix &w, Matrix &bias, ActivationType activationType);

    Matrix getWeights() const;

    Matrix getBias() const;

    ActivationType getActivation() const;

    Matrix operator()(const Matrix &input);
private:

    ActivationType activationType;
    Matrix weights;
    Matrix bias;
};


#endif //C___DENSE_H
