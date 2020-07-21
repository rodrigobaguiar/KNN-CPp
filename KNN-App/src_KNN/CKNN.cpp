#include "CKNN.h"
#include <cmath>

CKNN::CKNN(){

}

CKNN::CKNN(KNNData *&trainningCases, KNNData *&testCases, int nTrainingCases, int nTestCases, int k)
{

}

double CKNN::euclidianDistance(KNNData &first, KNNData &second)
{
//    std::vector<double> results;
//    for(int i = 0; i < 1000000; i++){
//        results.push_back(i*i/2);
//    }
    return sqrt(pow((first.sepalLenght - second.sepalLenght), 2) + pow((first.sepalWidth - second.sepalWidth), 2) +
                pow((first.petalLenght - second.petalLenght), 2) + pow((first.petalWidht - second.petalWidht), 2));
}

double CKNN::manhattanDistance(KNNData &first, KNNData &second)
{
    return  abs(first.sepalLenght - second.sepalLenght) + abs(first.sepalWidth - second.sepalWidth) +
            abs(first.petalLenght - second.petalLenght) + abs(first.petalWidht - second.petalWidht);
}

double CKNN::minkowskiDistance(KNNData &first, KNNData &second)
{
    int p = 2; // p = 2 is the same of euclidian distance

    return  pow(pow((first.sepalLenght - second.sepalLenght), p) + pow((first.sepalWidth - second.sepalWidth), p) +
                pow((first.petalLenght - second.petalLenght), p) + pow((first.petalWidht - second.petalWidht), p), 1.0/p);
}

double CKNN::hammingDistance(KNNData &first, KNNData &second)
{
    //SEARCH----------------------- Error
    return (first.sepalLenght - second.sepalLenght) + (first.sepalWidth - second.sepalWidth) +
           (first.petalLenght - second.petalLenght) + (first.petalWidht - second.petalWidht);
}

std::string CKNN::returnClassification(int setosa, int versicolor, int virginica)
{
    int ret = std::max(setosa, versicolor);
    ret = std::max(ret, virginica);

    if(setosa >= versicolor && setosa >= virginica)
        return "Iris-setosa";
    else if(versicolor >= setosa && versicolor >= virginica)
        return "Iris-versicolor";
    else
        return "Iris-virginica";
}


