/**
 * @file   Parameters.h
 * @brief  Defines parameters of convolutional neural network layer.
 * @author Nick Drabovich <drabovich@gmail.com>
 */

#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H


#include <vector>
#include <string>

namespace cnn {
    
    const std::vector<std::string> layer_type_name = {
        "Input",
        "Convolutional",
        "Pooling",
        "Fully-connected",
        "Softmax"
    };
    
    enum layer_type
    {
        INPUT_LAYER,
        CONVOLUTIONAL_LAYER,
        POOLING_LAYER,
        FULL_LAYER,
        SOFTMAX_LAYER
    };
    
    class Parameters {
    public:
        layer_type l_type;
        std::vector<int> dims;
        Parameters(layer_type _l_type, std::vector<int> _dims): l_type(_l_type), dims(_dims){
        }
    };
    
} // namespace cnn

#endif // PARAMETERS_H