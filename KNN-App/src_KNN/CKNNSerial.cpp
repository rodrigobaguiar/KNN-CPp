#include "CKNNSerial.h"


CKNNSerial::CKNNSerial() {

}

void CKNNSerial::classify(KNNData* &trainningCases, KNNData testCase, int K, int cases, int caseIndex)
{
    auto setosa = 0;
    auto versicolor = 0;
    auto virginica = 0;
    int neighborCounter = 0;
    std::set<std::pair<double, int> >::iterator it;
    std::set<std::pair<double, int> > distances;

    for(int i = 0; i < cases; i++){
        distances.insert(std::make_pair(euclidianDistance(trainningCases[i], testCase), i));
        //distances.insert(std::make_pair(manhattanDistance(trainningCases[i], testCase), i));
        //distances.insert(std::make_pair(minkowskiDistance(trainningCases[i], testCase), i));
        //distances.insert(std::make_pair(hammingDistance(trainningCases[i], testCase), i));
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

    classFound.push_back(returnClassification(setosa, versicolor, virginica));
}

void CKNNSerial::cudaClassify(KNNData *&trainningCases, KNNData *&testCases, int *nCases, int *nTests, int *K)
{

}
