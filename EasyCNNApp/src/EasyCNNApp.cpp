/**
 * @file   EasyCNNApp.cpp
 * @brief  Application which mocks object recognition using convolutional neural network.
 * @author Nick Drabovich <drabovich@gmail.com>
 */

#include <CNN.h>


int main(int argc, char *argv[]) {

    cnn::CNN network;
    std::vector<cnn::Parameters> layer_parameters;
    
    // Define NickNet :)
    layer_parameters.push_back(cnn::Parameters(cnn::INPUT_LAYER,          std::vector<int>{256,256,1}));
    layer_parameters.push_back(cnn::Parameters(cnn::CONVOLUTIONAL_LAYER,  std::vector<int>{15,15,10}));
    layer_parameters.push_back(cnn::Parameters(cnn::POOLING_LAYER,        std::vector<int>{2,2,0}));
    layer_parameters.push_back(cnn::Parameters(cnn::CONVOLUTIONAL_LAYER,  std::vector<int>{7,7,10,20}));
    layer_parameters.push_back(cnn::Parameters(cnn::POOLING_LAYER,        std::vector<int>{2,2,0}));
    layer_parameters.push_back(cnn::Parameters(cnn::FULL_LAYER,           std::vector<int>{10000,1}));
    layer_parameters.push_back(cnn::Parameters(cnn::FULL_LAYER,           std::vector<int>{2000,1}));
    layer_parameters.push_back(cnn::Parameters(cnn::SOFTMAX_LAYER,        std::vector<int>{1000,1}));
    
    network.create(layer_parameters);
    
    /*
     Longer description of the network:
     
     input layer:          
     input:  (w0:256)x(h0:256)x(c0:1)
     functions applied: NONE
     output: (w0:256)x(h0:256)x(c0:1)
     - it is just c0 1-channel image
     
     convolutional layer 0:
     input:  (w0:256)x(h0:256)x(c0:1)
     functions applied: (w1:15)x(h1:15)x(c0:1)x(c1:10) <- store 4d matrix associated with layer
     output: (w2:(w0-(w1-1)))x(h2:(h0-(h1-1)))x(c1)
     (gets input from previous layer,
     calculates 3d convolution at each point (if stride parameter is not null, then skipping some adjustent pixels)
     produces c1 1-channel images).
     
     pooling layer 0:
     input:  (w2)x(h2)x(c1)
     functions applied: cij=max(cij), i,j=0,1 <- store (0..2) and function (max) associated with layer
     output:  (w3:(w2/2+w2%2))x(h3:(h2/2+h2%2))x(c1)
     downsamples images from the previous layer by factor of 2, (some other decimation tricks may be used).
     
     convolutional layer 1:
     input:  (w3)x(h3)x(c1)
     functions applied: (w4:7)x(h4:7)x(c1)x(c2:20) <- store 4d matrix associated with layer
     output: (w5:w3-w4+1)x(h5:h3-w4+1)x(c2)
     
     pooling layer 1:
     input:  (w5)x(h5)x(c2)
     functions applied: cij=max(cij), i,j=0,1 <- store (0..2) and function (max) associated with layer
     output:  (w6:(w5/2+w5%2))x(h6:(h5/2+h5%2))x(c2)
     
     fully connected layer 0:
     input: (w6)x(h6)x(c2) - reshaped as column vector V0
     function applied: (TANH|RELU)(F0'*V0+B0), where F0 - weight matrix of size V0xN0. <-store F0, B0
     output:  column vector R0 of size N0x1
     
     fully connected layer 1:
     input: R0
     function applied:  R1=(TANH|RELU)(F1'*R0+B1) <-store F1 (size N0xN1), B1
     output: R1 =  N1x1 values
     
     softmax layer:
     input: R1 = N1x1 values
     function applied: F2 - matrix of size R1xN2 <-store F2, B2
     R2=(F2'*R1+B2) - size N2x1
     then R2(i): given f(R2(i)) = 1/(1+e(-R2(i))), R2(i) = R2(i)/sum(R2(i))
     output:  N2x1 values, *somewhat related* to probabilities of object belonging to class i
     
     also required: contrast normalization after convolution layer, data whitening, numerical gradient checking in backprop 
     */
    
    
    
    //Finally
    network.fit();
    network.predict();

}
