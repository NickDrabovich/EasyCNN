/**
 * @file   CNN.h
 * @brief  Defines convolutional neural network class CNN.
 * @author Nick Drabovich <drabovich@gmail.com>
 */

#pragma once
#ifndef CNN_H
#define CNN_H

#include <iostream>
#include <vector>
#include "Layer.h"

namespace cnn {
    
    class CNN {
    public:
        
        std::vector<Layer*> layers;
        void create(std::vector<Parameters>&);
        void fit();
        void predict();
        CNN(){
            std::cout<<"Constructing network..."<<std::endl;
        };
        
        ~CNN(){
            for(auto layer:layers) delete layer;
            std::cout<<"Destructing network..."<<std::endl;
        };
        
    };
    
} // end of namespace cnn
#endif // CNN_H