/***************************************************************************
 *                             KNN-Cpp                                     *
 *                                                                         *
 * Software to analyze processing times to Knn networks using Iris dataset *
 *                                                                         *
 *             Serial processing: using CPU and one thread;                *
 *         Parallel processing: using CPU and multiple threads;            *
 *           Cuda processing: using GPU and multiple threads.              *
 *                                                                         *
 *    User can select the number of tests, K and select desire type of     *
 *          calculation. Results are shown as text and graphics.           *
 *                                                                         *
 * ======================================================================= *
 *                      Autor: Rodrigo Aguiar                              *
 *           rodrigo.b.aguiar@gmail.com / rbaguiar@id.uff.br               *
 ***************************************************************************/
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <device_launch_parameters.h>

#include <thrust/device_vector.h>

#include <stdio.h>
#include "knnCuda.h"
#include <string>


//struct KNNData;
struct KNNData{
    double sepalLenght = 0.0;
    double sepalWidth = 0.0;
    double petalLenght = 0.0;
    double petalWidht = 0.0;
    std::string irisClass = "";
    int id = 0;
};

__global__ void classify(KNNData *trainningCases, KNNData *testCase, int *K){


    printf("Hello from GPU! \n");



//    auto setosa = 0;
//    auto versicolor = 0;
//    auto virginica = 0;
//    int neighborCounter = 0;
//    std::set<std::pair<double, int> >::iterator it;
//    std::set<std::pair<double, int> > distances;

//    std::cout << std::this_thread::get_id() << "\n";

//    for(int i = 0; i < cases; i++){
//        distances.insert(std::make_pair(euclidianDistance(trainningCases[i], testCase), i));
//    }

//    for (auto it = distances.begin(); it != distances.end(); it++){
//        if(neighborCounter == K)
//            break;

//        std::string classe = trainningCases[it->second].irisClass;

//        if(classe == "Iris-setosa")
//            setosa++;
//        else if(classe == "Iris-versicolor")
//            versicolor++;
//        else if(classe == "Iris-virginica")
//            virginica++;

//        neighborCounter++;
//    }

//    std::mutex mtx;
//    mtx.lock();
//    classFound[caseIndex] = returnClassification(setosa, versicolor, virginica);
//    mtx.unlock();

}

/**
 * Init CUDA.
 * Receive required data, sende data to device and acces functions.
 * @param trainningCases Array with trainning data.
 * @param testCase Specific entry to analyse
 * @param nCases Number of trainned cases
 * @param nTests Number of test cases
 * @param K Number of neighbors to analyse
*/
void initCuda(KNNData *&trainningCases, KNNData *&testCase, int *nCases, int *nTests, int* K){

    //receive data
    KNNData *deviceTrainningCases;
    KNNData *deviceTestCases;
    int *deviceK;

    int sizeTrainning = (sizeof(KNNData)**nCases);
    int sizeTest = (sizeof(KNNData)**nTests);

    if(cudaSuccess != cudaMalloc((void **)&deviceTrainningCases, sizeTrainning)) printf("Error allocating trainning cases. \n");
    if(cudaSuccess != cudaMalloc((void **)&deviceTestCases, sizeTest)) printf("Error allocating test cases. \n");
    if(cudaSuccess != cudaMalloc((void **)&deviceK, sizeof(int))) printf("Error allocating K. \n");

    if(cudaSuccess != cudaMemcpy(deviceTrainningCases, trainningCases, sizeTrainning, cudaMemcpyHostToDevice)) printf("Error copying trainning cases. \n");
    if(cudaSuccess != cudaMemcpy(deviceTestCases, testCase, sizeTest, cudaMemcpyHostToDevice)) printf("Error copying test cases. \n");
    if(cudaSuccess != cudaMemcpy(deviceK, K, sizeof(int), cudaMemcpyHostToDevice)) printf("Error copying K. \n");


    printf("Sepal Widht: %4.2f \n", deviceTrainningCases[0].sepalWidth);
    printf("Petal Widht: %4.2f \n", deviceTestCases[0].petalWidht);
    printf("K: %d \n", deviceK);


    classify<<<1,1>>>(deviceTrainningCases, deviceTestCases, deviceK);


    //copiar resultados de volta para o host



    cudaFree(deviceTrainningCases);
    cudaFree(deviceTestCases);
    cudaFree(deviceK);
    //clean

}


//int h_arr[N] = {1,2,3,4,5,6,7,8,9,10};
//StructA h_a;
//int *d_arr;

// 1. Allocate device array.
//cudaMalloc((void**) &(d_arr), sizeof(int)*N);

// 2. Copy array contents from host to device.
//cudaMemcpy(d_arr, h_arr, sizeof(int)*N, cudaMemcpyHostToDevice);

// 3. Point to device pointer in host struct.
//h_a.arr = d_arr;

// 4. Call kernel with host struct as argument
//kernel2<<<N,1>>>(h_a);

// 5. Copy pointer from device to host.
//cudaMemcpy(h_arr, d_arr, sizeof(int)*N, cudaMemcpyDeviceToHost);

// 6. Point to host pointer in host struct
//    (or do something else with it if this is not needed)
//h_a.arr = h_arr;


