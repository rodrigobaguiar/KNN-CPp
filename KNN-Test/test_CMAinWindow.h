#ifndef TEST_CMAINWINDOW_H
#define TEST_CMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtTest>
#include <QCoreApplication>
#include <QtGui>

#include "CMainWindow.h"

class test_CMAinWindow : public QObject
{
    Q_OBJECT

public:
    test_CMAinWindow();
    ~test_CMAinWindow();

    void initTestCase();

    void test_functionXXX();

    void cleanupTestCase();

};

#endif // TEST_CMAINWINDOW_H
