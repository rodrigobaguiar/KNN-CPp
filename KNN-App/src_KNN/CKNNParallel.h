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
#ifndef CKNNPARALLEL_H
#define CKNNPARALLEL_H
#include "CKNN.h"

/**
 *  Class CKNNParallel.
 *  Class to perform knn calculation using parallel processing (CPU).
 * @brief Knn using parallel processing.
*/
class CKNNParallel : public CKNN
{
public:
    /**
     *  Class Constructor.
     *  Constructor for KNNParallel class.
    */
    CKNNParallel();

    /**
     * Classify.
     * OVERRRIDE - Function to execute classification using KNNParallel class.
     * @param trainningCases Array with trainning data.
     * @param testCase Specific entry to analyse
     * @param K Number of neighbors to analyse
     * @param cases Number of trainned cases
    */
    void classify(KNNData *&trainningCases, KNNData testCase, int K, int cases, int caseIndex) override;

    void cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K) override;

};

#endif // CKNNPARALLEL_H
