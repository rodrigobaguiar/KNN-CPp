#include "test_CMAinWindow.h"

int main(int, char*[]){

    test_CMAinWindow testCMainWindow;

    QTest::qExec(&testCMainWindow);

    return 0;
}
