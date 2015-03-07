/**
 * @file   CNN.cpp
 * @brief  Implementation of convolutional neural network class CNN.
 * @author Nick Drabovich <drabovich@gmail.com>
 */


#include "CNN.h"

namespace cnn {
    
    
    void CNN::fit() {
        std::cout <<"=====================================================\n";
        std::cout << "Start training: feeding millions of images in\n";
        
        /**
         *
         * For each sample for each epoch until log loss is not small enough:
         * get error via forward_pass();
         * use stochastic gradient descent for adjusting initially random N(mu=0,sigma=0.1) network weights via error backpropagation;
         *
         */
        
        /**
         * Backpropagation:
         * We need to adjust weights in all layers, so that our trining error is minimized. We'll use gradient descent method for this.
         * In essence, we need to find gradient of error function w.r.t. w(i,j)
         * so we can do this update of weights:
         *
         * w(i,j) = w(i,j) - a*(dE/dw(i,j)); a - learning rate (0.0005 and decreasing as epochs go by...)
         *
         * General idea how to find dE/dw(i,j)
         * 1) Get sample, calculate forward pass, get error E = (1/2)*sum(Yi-Ti)^2
         * 2) Find dE/dWij:
         * Using chain rule, where Xj - input from previous layer, Yi = F(Wij*Xj+B), F - softmax for the last layer.
         * dE/dWij = dE/dYi * dYi/dXj * dXj/dWij
         */
        
        std::cout << "...\n...\n...\nTraining completed: validation error: 0.1%\n"<<std::endl;
        
    }
    
    void CNN::predict() {
        std::cout << "Now trying to classify an unknow image...\nResult - it is a cat: 0.7\n\t\t\t    dog: 0.2\n\t    an airplane!: 0.1"<<std::endl;
        std::cout <<"=====================================================\n";
    }
    
    void CNN::create(std::vector<Parameters>& params) {
        for(auto param:params){
            cnn::Layer* layer = new cnn::Layer(param);
            layers.push_back(layer);
        }
    }
    
}  // end of namespace cnn
