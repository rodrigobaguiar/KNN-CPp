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
#ifndef KNNCUDA_H
#define KNNCUDA_H

#include <string>

/**
 *  Cuda access interface.
 *  Interface to acces CUDA functionalities.
 * @brief CUDA interface.
*/
struct KNNData;             /**< Forwarding declaration of Struct KNNData */

/**
 * Init CUDA.
 * Access the .cu file passing required arguments.
 * @param trainningCases Array with trainning data.
 * @param testCase Specific entry to analyse
 * @param nCases Number of trainned cases
 * @param nTests Number of test cases
 * @param K Number of neighbors to analyse
*/
void initCuda(KNNData *&trainningCases, KNNData *&testCase, int *nCases, int *nTests, int *K);

#endif // KNNCUDA_H
