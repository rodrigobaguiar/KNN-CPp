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
#ifndef CKNN_H
#define CKNN_H

#include "CMainWindow.h"
#include <set>
#include <array>
#include <algorithm>
#include <iostream>

/**
 *  Class CKNN.
 *  Base class for knn networks.
 * @brief Knn base class.
*/
class CKNN
{
public:
    /**
     *  Class Constructor.
     *  Class constructor for CKNN class.
    */
    CKNN();

    /**
     * Class Constructor.
     * Overload constructor for class CKNN.
     * @param trainningCases Pointer to trainning data array
     * @param testCases Pointer to test case data array
     * @param nTrainingCases Number of trainning cases
     * @param nTestCases Number of test cases
     * @param k Neighbors to analyse
    */
    CKNN(KNNData* &trainningCases, KNNData* &testCases, int nTrainingCases, int nTestCases, int k);

    /**
     * Classify.
     * Virtual function to execute classification using given class.
     * @param trainningCases Array with trainning data.
     * @param testCase Specific entry to analyse
     * @param K Number of neighbors to analyse
     * @param cases Number of trainned cases
     * @param caseIndex Index of given case
    */
    virtual void classify(KNNData *&trainningCases, KNNData testCase, int K, int cases, int caseIndex) = 0;

    /**
     * Cuda Classify.
     * Virtual function to execute classification using Cuda.
     * @param trainningCases Array with trainning data.
     * @param testCases Array of test cases.
     * @param nCases Number of trainning cases
     * @param nTests Number of test cases
     * @param K Number of neighbors
    */
    virtual void cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K) = 0;

    std::vector<std::string> classFound;            /**< Vector of strings with classes found  */

protected:
    /**
     *  Euclidian Distance.
     *  Calculate the euclidian distance between two registers.
     * @param first First register
     * @param second Second register
    */
    double euclidianDistance(KNNData &first, KNNData &second);

    /**
     * Manhattan Distance.
     * Calculate the distance between two registers.
     * @param first First register
     * @param second Second register
    */
    double manhattanDistance(KNNData &first, KNNData &second);

    /**
     * Minkowski Distance.
     * Calculate the distance between two registers.
     * @param first First register
     * @param second Second register
    */
    double minkowskiDistance(KNNData &first, KNNData &second);

    /**
     * Hamming Distance.
     * Calculate the distance between two registers.
     * @param first First register
     * @param second Second register
    */
    double hammingDistance(KNNData &first, KNNData &second);

    /**
     *  Return classification.
     *  Return the class name found.
     * @param setosa Iris-setosa counter
     * @param versicolor Iris-versicolor counter
     * @param virginica Iris-virginica counter
    */
    std::string returnClassification(int setosa, int versicolor, int virginica);
};

#endif // CKNN_H
