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
#ifndef CKNNCUDA_H
#define CKNNCUDA_H
#include "CKNN.h"

/**
 *  Class CKNNCuda.
 *  Class to perform knn calculation using CUDA.
 * @brief Knn using CUDA.
*/
class CKNNCuda : public CKNN
{
public:
    /**
     *  Class Constructor.
     *  Constructor for KNNCuda class.
    */
    CKNNCuda();

    /**
     *  Classify.
     *  OVERRRIDE - Function to execute classification using KNNCuda class.
     * @param trainningCases Array with trainning data.
     * @param testCase Specific entry to analyse
     * @param K Number of neighbors to analyse
     * @param cases Number of trainned cases
     * @param caseIndex Index of given case
    */
    void classify(KNNData *&trainningCases, KNNData testCase, int K, int cases, int caseIndex) override;

    /**
     * Cuda Classify.
     * Virtual function to execute classification using Cuda.
     * @param trainningCases Array with trainning data.
     * @param testCases Array of test cases.
     * @param nCases Number of trainning cases
     * @param nTests Number of test cases
     * @param K Number of neighbors
    */
    virtual void cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K) override;
};

#endif // CKNNCUDA_H
