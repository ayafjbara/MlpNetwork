//
// Created by Aya on 12/15/2019.
//

#include "Activation.h"

Activation::Activation(ActivationType actType) {

}

enum ActivationType Activation::getActivationType() {
    return Softmax;
}
