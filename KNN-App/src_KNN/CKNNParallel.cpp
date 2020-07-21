#include "CKNNParallel.h"

CKNNParallel::CKNNParallel()
{

}

void CKNNParallel::classify(KNNData *&trainningCases, KNNData testCase, int K, int cases, int caseIndex)
{
    auto setosa = 0;
    auto versicolor = 0;
    auto virginica = 0;
    int neighborCounter = 0;
    std::set<std::pair<double, int> >::iterator it;
    std::set<std::pair<double, int> > distances;    

    for(int i = 0; i < cases; i++){
        distances.insert(std::make_pair(euclidianDistance(trainningCases[i], testCase), i));
    }

    for (auto it = distances.begin(); it != distances.end(); it++){
        if(neighborCounter == K)
            break;

        std::string classe = trainningCases[it->second].irisClass;

        if(classe == "Iris-setosa")
            setosa++;
        else if(classe == "Iris-versicolor")
            versicolor++;
        else if(classe == "Iris-virginica")
            virginica++;

        neighborCounter++;
    }

//    std::mutex mtx;
//    mtx.lock();
    classFound[caseIndex] = returnClassification(setosa, versicolor, virginica);
    //    mtx.unlock();
}

void CKNNParallel::cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K)
{

}




