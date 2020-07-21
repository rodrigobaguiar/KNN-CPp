QT += testlib \
    widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../KNN-App/
DEPENDPATH += ../KNN-App/



SOURCES +=  \
    main.cpp \
    test_CMAinWindow.cpp

HEADERS += \
    test_CMAinWindow.h
