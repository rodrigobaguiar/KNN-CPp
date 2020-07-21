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
#ifndef CKNNSERIAL_H
#define CKNNSERIAL_H
#include "CKNN.h"

/**
 *  Class CKNNSerial.
 *  Class to perform knn calculation using serial processing.
 * @brief Knn serial computation.
*/
class CKNNSerial : public CKNN
{
public:
    /**
     *  Class Constructor.
     *  Constructor for KNNSerial class.
    */
    CKNNSerial();

    /**
     * Classify.
     * OVERRRIDE - Function to execute classification using KNNSerial class.
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
    void cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K) override;
};

#endif // CKNNSERIAL_H
