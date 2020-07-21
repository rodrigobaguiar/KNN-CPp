#include "CMainWindow.h"
#include "ui_CMainWindow.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <chrono>
#include <QVector>
#include <thread>
#include "src_KNN/CKNN.h"
#include "src_KNN/CKNNSerial.h"
#include "src_KNN/CKNNParallel.h"
#include "src_KNN/CKNNCuda.h"

#define datasetSize 150

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    trainningCases = nullptr;
    testCases = nullptr;
    ui->GroupBoxResults->setVisible(false);
    ui->GBKNNSetup->setVisible(false);
    ui->PBRun->setEnabled(false);
    ui->PBClear->setEnabled(false);
    ui->GBProcessingType->setVisible(false);

    //barPlot = new QCPBars(ui->PlotProcessingTime->xAxis, ui->PlotProcessingTime->yAxis2);
    connect(ui->CBModel, SIGNAL(currentIndexChanged(int)),this, SLOT(modelChange(int)));
}

CMainWindow::~CMainWindow()
{
    delete ui;
    free(trainningCases);
    free(testCases);
}

void CMainWindow::modelChange(int index){

    if(index == 0){
       ui->GBKNNSetup->setVisible(false);
       ui->PBRun->setEnabled(false);
       ui->PBClear->setEnabled(false);
       ui->GBProcessingType->setVisible(false);
    }else if(index == 1){
       ui->GBKNNSetup->setVisible(true);
       ui->PBRun->setEnabled(true);
       ui->PBClear->setEnabled(true);
       ui->GBProcessingType->setVisible(true);
    }else{
        ui->GBKNNSetup->setVisible(false);
        ui->PBRun->setEnabled(false);
        ui->PBClear->setEnabled(false);
        ui->GBProcessingType->setVisible(false);
    }
}

void CMainWindow::on_PBRun_clicked()
{    
    if(verifyFields()){

        int startAt = 0;
        int match = 0;
        int numberOfThreads = 0;
        QVector<int> errorIndex;
        std::vector<std::string> classFound;
        setNumberOfTrainningCases(datasetSize - ui->LENumberOfTests->text().toInt());
        setNumberOfTestCases(datasetSize - getNumberOfTrainningCases());
        setKneighbors(ui->LENumberOfNeighbors->text().toInt());
        int endAt = getNumberOfTrainningCases()-1;

        allocData(getNumberOfTrainningCases(), getNumberOfTestCases());
        loadData(trainningCases, startAt, endAt);

        startAt = getNumberOfTrainningCases();
        endAt = datasetSize-1;
        loadData(testCases, startAt, endAt);

        auto start = std::chrono::steady_clock::now();

        if(ui->RBSerial->isChecked()){

            CKNN *knnSerial = new CKNNSerial();
            numberOfThreads = 1;
            statusBar()->showMessage("Classifying using CPU processor (Serial)...", 2000);

            for(int i = 0; i < getNumberOfTestCases(); i++){
                knnSerial->classify(trainningCases, testCases[i], getKneighbors(), getNumberOfTrainningCases(), i);
            }

            for(int i = 0; i < getNumberOfTestCases(); i++){
                if(knnSerial->classFound[i] == testCases[i].irisClass){                    
                    match++;
                }else{
                    errorIndex.push_back(i);
                }
            }

        }

        if(ui->RBParallel->isChecked()){
            CKNN *knnParallel = new CKNNParallel();
            std::vector<std::thread> threads;            
            statusBar()->showMessage("Classifying using CPU processor (Multithread). Threads on hardware: ", 2000);

            knnParallel->classFound.resize(getNumberOfTestCases());

            for(int i = 0; i < getNumberOfTestCases(); i++){

                threads.push_back(std::thread(&CKNN::classify,
                                              knnParallel,
                                              std::ref(trainningCases),
                                              std::ref(testCases[i]),
                                              getKneighbors(),
                                              getNumberOfTrainningCases(),
                                              i));
            }

            for(int i = 0; i < getNumberOfTestCases(); i++){
                threads[i].join();
            }

            for(int i = 0; i < getNumberOfTestCases(); i++){                
                if(knnParallel->classFound[i] == testCases[i].irisClass){                    
                    match++;
                }else{
                    errorIndex.push_back(i);
                }
            }            
            numberOfThreads = threads.size();
        }

        if(ui->RBCuda->isChecked()){
            CKNN *knnCuda = new CKNNCuda();
            int K = getKneighbors();
            int nCases = getNumberOfTrainningCases();
            int nTests = getNumberOfTestCases();
            knnCuda->cudaClassify(trainningCases, testCases, &nCases, &nTests, &K);

        }

        if(ui->RBAllTypes->isChecked()){


        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;        
        double seconds = std::chrono::duration<double>(elapsed_seconds).count();

        plotIrisData(errorIndex);
        plotErrorProcessingTime(seconds, match);
        showResultsGroupBox(match, seconds, numberOfThreads);        
    }else{
        QMessageBox::warning(this, "Data error", "Incorrect values entred on Number of tests or Neighbors");
    }
}

bool CMainWindow::verifyFields()
{
    bool tests = true;
    bool neighbors = true;

    ui->LENumberOfTests->text().toInt(&tests);
    ui->LENumberOfNeighbors->text().toInt(&neighbors);

    if(tests && neighbors){
        return true;
    }else{
        return false;
    }
}

void CMainWindow::allocData(int numberOfTrainingCases, int numberOfTestCases)
{
    if(trainningCases != nullptr){
        free(trainningCases);
    }
    if(testCases != nullptr){
        free(testCases);
    }

    trainningCases = (KNNData *) calloc(numberOfTrainingCases, sizeof (KNNData));
    testCases = (KNNData *) calloc(numberOfTestCases, sizeof (KNNData));
}

void CMainWindow::showResultsGroupBox(int matchs, double time, int threads)
{
    ui->GroupBoxResults->setVisible(true);
    ui->LBTreinedCases->setText(QString::number(getNumberOfTrainningCases()));
    ui->LBTestCases->setText(QString::number(getNumberOfTestCases()));
    ui->LBMatchs->setText(QString::number(matchs));

    ui->LBAccuracy->setText(QString::number(calculateAccuracy(matchs), 'f', 3));

    ui->LBProcessingTime->setText(QString::number(time, 'f', 6));
    ui->LBHardwareThreads->setText(QString::number(std::thread::hardware_concurrency()));
    ui->LBUsedThreads->setText(QString::number(threads));

    ui->LBDifference->setText(QString::number(calculateDiffTimes(), 'f', 3));
}

double CMainWindow::calculateDiffTimes()
{
    int n = processingTimes.size();

    if(processingTimes.size() > 1){
        return (double)((processingTimes[n-1] - processingTimes[n-2]) / ((double)(processingTimes[n-1] + processingTimes[n-2]) / 2)) * 100.00;

    }else{
        return 0.0;
    }
}

void CMainWindow::plotErrorProcessingTime(double time, double matchs){

    QCPScatterStyle markerStyleTime;
    markerStyleTime.setShape(QCPScatterStyle::ssDisc);
    markerStyleTime.setSize(6);
    markerStyleTime.setPen(QPen(Qt::blue));

    QCPScatterStyle markerStyleError;
    markerStyleError.setShape(QCPScatterStyle::ssDisc);
    markerStyleError.setSize(6);
    markerStyleError.setPen(QPen(Qt::red));

    QPen currentPen;
    currentPen.setStyle(Qt::DotLine);
    currentPen.setWidth(1);
    currentPen.setColor(Qt::red);

    QFont legendFont = font();
    legendFont.setPointSize(9);

    processingTimes.push_back(time);
    accuracy.push_back(calculateAccuracy(matchs));

    double minRange = *std::min_element(processingTimes.begin(),processingTimes.end());
    double maxRange = *std::max_element(processingTimes.begin(),processingTimes.end());

    QVector<double> xAxis;
    for(int i = 0; i < processingTimes.size(); i++){
        xAxis.push_back(i+1);
    }

    ui->PlotProcessingTime->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->PlotProcessingTime->clearGraphs();

    //Plot proccessing times
    ui->PlotProcessingTime->addGraph();
    ui->PlotProcessingTime->graph(0)->setData(xAxis, processingTimes);
    ui->PlotProcessingTime->graph(0)->setScatterStyle(markerStyleTime);
    ui->PlotProcessingTime->xAxis->setLabel("Calculation");
    ui->PlotProcessingTime->yAxis->setLabel("Processing time (s)");
    ui->PlotProcessingTime->xAxis->setRange(-1, processingTimes.size() + 1);
    ui->PlotProcessingTime->yAxis->setRange(minRange / 2 , maxRange * 1.2);
    ui->PlotProcessingTime->graph(0)->setName("Time (s)");

    ui->PlotProcessingTime->yAxis2->setVisible(true);
    ui->PlotProcessingTime->addGraph(ui->PlotProcessingTime->xAxis, ui->PlotProcessingTime->yAxis2);
    ui->PlotProcessingTime->graph(1)->setData(xAxis, accuracy);
    ui->PlotProcessingTime->graph(1)->setScatterStyle(markerStyleError);
    ui->PlotProcessingTime->graph(1)->setPen(currentPen);
    ui->PlotProcessingTime->yAxis2->setLabel("Accuracy (%).");
    ui->PlotProcessingTime->yAxis2->setRange(0 , 110);
    ui->PlotProcessingTime->graph(1)->setName("Accuracy (%)");

    //Plot accuracy
//    ui->PlotProcessingTime->yAxis2->setVisible(true);
//    barPlot->setData(xAxis, accuracy);
//    ui->PlotProcessingTime->yAxis2->setRange(0 , 100);
//    barPlot->setPen(Qt::NoPen);
//    barPlot->setBrush(QColor(Qt::gray));
//    ui->PlotProcessingTime->yAxis2->setLabel("Accuracy (%).");
//    barPlot->setName("Accuracy (%)");

    //Plot legend
    ui->PlotProcessingTime->legend->setVisible(true);    
    ui->PlotProcessingTime->legend->setFont(legendFont);
    ui->PlotProcessingTime->legend->setBrush(QBrush(QColor(255,255,255,230)));
    ui->PlotProcessingTime->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    ui->PlotProcessingTime->replot();
}

void CMainWindow::plotIrisData(QVector<int> errorIndexes)
{
    QCPScatterStyle markerStyle;
    markerStyle.setShape(QCPScatterStyle::ssDisc);
    markerStyle.setSize(7);
    markerStyle.setPen(QPen(Qt::blue));

    QPen currentPen;
    currentPen.setStyle(Qt::NoPen);

    QFont legendFont = font();
    legendFont.setPointSize(9);

    QVector<double> sepalWidhtSetosa;
    QVector<double> sepalLenghtSetosa;
    QVector<double> sepalWidhtVersicolor;
    QVector<double> sepalLenghtVersicolor;
    QVector<double> sepalWidhtVirginica;
    QVector<double> sepalLenghtVirginica;
    QVector<double> sepalWidhtTestCases;
    QVector<double> sepalLenghtTestCases;

    QVector<double> sepalWidhtNotClassified;
    QVector<double> sepalLenghtNotClassified;

    for(int i = 0; i < getNumberOfTestCases();i++){
        sepalWidhtTestCases.push_back(testCases[i].sepalWidth);
        sepalLenghtTestCases.push_back(testCases[i].sepalLenght);
    }

    for(int i = 0; i < getNumberOfTrainningCases();i++){
        if(trainningCases[i].irisClass == "Iris-setosa"){
            sepalWidhtSetosa.push_back(trainningCases[i].sepalWidth);
            sepalLenghtSetosa.push_back(trainningCases[i].sepalLenght);
        } else if(trainningCases[i].irisClass == "Iris-versicolor"){
            sepalWidhtVersicolor.push_back(trainningCases[i].sepalWidth);
            sepalLenghtVersicolor.push_back(trainningCases[i].sepalLenght);
        }else if(trainningCases[i].irisClass == "Iris-virginica"){
            sepalWidhtVirginica.push_back(trainningCases[i].sepalWidth);
            sepalLenghtVirginica.push_back(trainningCases[i].sepalLenght);
        }
    }

    ui->DataSetDataPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->DataSetDataPlot->clearGraphs();

    //Plot Iris-setosa data
    ui->DataSetDataPlot->addGraph();
    ui->DataSetDataPlot->graph(0)->setData(sepalLenghtSetosa, sepalWidhtSetosa);
    ui->DataSetDataPlot->graph(0)->setScatterStyle(markerStyle);
    ui->DataSetDataPlot->graph(0)->setPen(currentPen);
    ui->DataSetDataPlot->xAxis->setLabel("Seplal lenght (cm)");
    ui->DataSetDataPlot->yAxis->setLabel("Sepal width (cm)");
    ui->DataSetDataPlot->graph(0)->setName("Iris-setosa");

    //Plot Iris-versicolor data
    markerStyle.setShape(QCPScatterStyle::ssDisc);
    markerStyle.setPen(QPen(Qt::red));
    ui->DataSetDataPlot->addGraph();
    ui->DataSetDataPlot->graph(1)->setData(sepalLenghtVersicolor, sepalWidhtVersicolor);
    ui->DataSetDataPlot->graph(1)->setScatterStyle(markerStyle);
    ui->DataSetDataPlot->graph(1)->setPen(currentPen);
    ui->DataSetDataPlot->graph(1)->setName("Iris-versicolor");

    //Plot Iris-virginica data
    markerStyle.setShape(QCPScatterStyle::ssDisc);
    markerStyle.setPen(QPen(Qt::darkCyan));
    ui->DataSetDataPlot->addGraph();
    ui->DataSetDataPlot->graph(2)->setData(sepalLenghtVirginica, sepalWidhtVirginica);
    ui->DataSetDataPlot->graph(2)->setScatterStyle(markerStyle);
    ui->DataSetDataPlot->graph(2)->setPen(currentPen);
    ui->DataSetDataPlot->graph(2)->setName("Iris-virginica");

    //Plot data to classification
    markerStyle.setShape(QCPScatterStyle::ssDisc);
    markerStyle.setPen(QPen(Qt::green));    
    ui->DataSetDataPlot->addGraph();
    ui->DataSetDataPlot->graph(3)->setData(sepalLenghtTestCases, sepalWidhtTestCases);
    ui->DataSetDataPlot->graph(3)->setScatterStyle(markerStyle);
    ui->DataSetDataPlot->graph(3)->setPen(currentPen);
    ui->DataSetDataPlot->graph(3)->setName("Data to classification");

    //Plot classification errors if exists
    if(errorIndexes.size()){
            for(int i = 0; i < errorIndexes.size(); i++){
                sepalWidhtNotClassified.push_back(testCases[errorIndexes[i]].sepalWidth);
                sepalLenghtNotClassified.push_back(testCases[errorIndexes[i]].sepalLenght);
             }

            markerStyle.setShape(QCPScatterStyle::ssCrossCircle);
            markerStyle.setPen(QPen(Qt::black));
            markerStyle.setSize(30);
            ui->DataSetDataPlot->addGraph();
            ui->DataSetDataPlot->graph(4)->setData(sepalLenghtNotClassified, sepalWidhtNotClassified);
            ui->DataSetDataPlot->graph(4)->setScatterStyle(markerStyle);
            ui->DataSetDataPlot->graph(4)->setPen(currentPen);
            ui->DataSetDataPlot->graph(4)->setName("Incorrect match");
    }

    //Define axis ranges
    ui->DataSetDataPlot->xAxis->setRange(4, 8);
    ui->DataSetDataPlot->yAxis->setRange(1 , 5);

    //Define axis legend
    ui->DataSetDataPlot->legend->setVisible(true);    
    ui->DataSetDataPlot->legend->setFont(legendFont);
    ui->DataSetDataPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    ui->DataSetDataPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    ui->DataSetDataPlot->replot();
}

void CMainWindow::loadData(KNNData* &dataset, int startAt, int endAt){

    KNNData obj;
    std::vector<std::string> values;
    std::string delimiter = ",";
    std::ifstream file("Iris_Dataset/iris.data");

    if(file.is_open()) {
        std::string line;
        int counter = 0;
        int i = 0;

        while(std::getline(file, line)){

            if(counter >= startAt & counter <= endAt){
                QString aux = QString::fromUtf8(line.c_str());;
                QStringList list = aux.split(QRegExp(","));

                obj.sepalLenght = list[0].toDouble();
                obj.sepalWidth = list[1].toDouble();
                obj.petalLenght = list[2].toDouble();
                obj.petalWidht = list[3].toDouble();
                obj.irisClass = list[4].toStdString();
                obj.id = i;
                dataset[i] = obj;
                i++;
            }
            counter++;
        }
        file.close();

    }else{
        std::cout << "Error open file.";
    }
}

void CMainWindow::on_PBClear_clicked()
{
    ui->DataSetDataPlot->clearGraphs();
    ui->PlotProcessingTime->clearGraphs();

    processingTimes.clear();
    accuracy.clear();

    ui->PlotProcessingTime->replot();
    ui->DataSetDataPlot->replot();
}
