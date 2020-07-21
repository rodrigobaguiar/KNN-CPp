#include "CKNNCuda.h"
#include "knnCuda.h"


CKNNCuda::CKNNCuda()
{

}

void CKNNCuda::classify(KNNData *&trainningCases, KNNData testCase, int K, int cases, int caseIndex)
{

}

void CKNNCuda::cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K){

    initCuda(trainningCases, testCases, nCases, nTests, K);
}

