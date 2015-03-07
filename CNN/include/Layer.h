/**
 * @file   Layer.h
 * @brief  Defines of convolutional neural network layer class.
 * @author Nick Drabovich <drabovich@gmail.com>
 */

#pragma once
#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include "Parameters.h"

namespace cnn {
    
    class Layer {
    public:
        
        Parameters parameters;
        
        Layer(Parameters _parameters):parameters(_parameters){
            std::cout<<"Constructing "<<layer_type_name[_parameters.l_type]<<" layer of size ";
            std::vector<int>::iterator it;
            for(it = _parameters.dims.begin(); it!=std::prev(_parameters.dims.end());++it){
                std::cout<<(*it)<<"x";
            }
            std::cout<<*(it)<<std::endl;
        }
        
        ~Layer(){
            std::cout<<"Destructing "<<layer_type_name[parameters.l_type]<<" layer of size ";
            std::vector<int>::iterator it;
            for(it = parameters.dims.begin(); it!=std::prev(parameters.dims.end());++it){
                std::cout<<(*it)<<"x";
            }
            std::cout<<*(it)<<std::endl;
        }
        
    };
    
} // namespace cnn

#endif // LAYER_H