#ifndef KNNCUDA_H
#define KNNCUDA_H

#include <string>
//#include "CMainWindow.h"

struct KNNData;

void initCuda(KNNData *&trainningCases, KNNData *&testCase, int *nCases, int *nTests, int *K);

#endif // KNNCUDA_H
