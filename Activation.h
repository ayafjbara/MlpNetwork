//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

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
class Activation{
public:
    Activation(ActivationType actType);
    enum ActivationType getActivationType();
    float operator()(int input); //todo change input type
private:
    enum ActivationType activationType;
};
#endif //ACTIVATION_H
