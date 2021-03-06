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
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "src_QCustomPlot/qcustomplot.h"

/**
 *  Struct KNNData.
 *  Struct used to define each entrie of Iris dataset.
 * @brief Representation of Iris data.
*/
struct KNNData{
    double sepalLenght = 0.0;       /**< Sepal Lenght. */
    double sepalWidth = 0.0;        /**< Sepal Widht. */
    double petalLenght = 0.0;       /**< Petal Lenght. */
    double petalWidht = 0.0;        /**< Petal Widht. */
    std::string irisClass = "";     /**< Iris class. */
    int id = 0;                     /**< Id of sample. */
};

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

/**
 *  Class CMainWindow.
 *  Class used to manage the graphical user interface.
 * @brief Manage the GUI.
*/
class CMainWindow : public QMainWindow
{
    Q_OBJECT                        /**< Alow Qt to use signal and slots system. */

public:

    /**
     * Class Constructor.
     * A default class constructor for CMainWindow Class created by Qt.
     * @param parent Parent to QWidget base class.
    */
    CMainWindow(QWidget *parent = nullptr);

    /**
     * Class Destructor.
     * A default class destructor for CMainWindow Class.
    */
    ~CMainWindow();

    //=========================================================
    //=================== Getters and Setters =================
    //=========================================================
    /**
     * Get Trainning Cases.
     * Return an array with trainned cases.
     * @return Array with trainning cases.
    */
    inline KNNData *getTrainningCases() const { return trainningCases;}

    /**
     * Set Trainning Cases.
     * Set an array with trainned cases.
     * @param value Array with trainning cases.
    */
    inline void setTrainningCases(KNNData *value) { trainningCases = value;}

    /**
     * Get Test Cases.
     * Return an array with test cases.
     * @return Array with test cases.
    */
    inline KNNData *getTestCases() const { return testCases;}

    /**
     * Set Test Cases.
     * Set an array with test cases.
     * @param value Array with test cases.
    */
    inline void setTestCases(KNNData *value) { testCases = value;}

    /**
     * Get N Trainning Cases.
     * Return number of trainning cases.
     * @return Number of trainning cases.
    */
    inline int getNumberOfTrainningCases() const { return numberOfTrainningCases;}

    /**
     * Set N Trainning Cases.
     * Set number of trainning cases.
     * @param value Number of trainning cases.
    */
    inline void setNumberOfTrainningCases(int value) { numberOfTrainningCases = value;}

    /**
     * Get N Test Cases.
     * Return number of test cases.
     * @return Number of test cases.
    */
    inline int getNumberOfTestCases() const { return numberOfTestCases;}

    /**
     * Set N Test Cases.
     * Set number of test cases.
     * @param value Number of test cases.
    */
    inline void setNumberOfTestCases(int value) { numberOfTestCases = value;}

    /**
     * Get K.
     * Return number of K neighbors to use.
     * @return Number K neighbours.
    */
    inline int getKneighbors() const { return Kneighbors;}

    /**
     * Set K.
     * Set number of K neighbors to use.
     * @param value Number K neighbours.
    */
    inline void setKneighbors(int value) { Kneighbors = value;}

private slots:

    void modelChange(int index);

    /**
     *  Run Clicked.
     *  Slot activated when user clicks on Run button.
    */
    void on_PBRun_clicked();

    /**
     *  Clear Clicked.
     *  Slot activated when user clicks on clear button.
    */
    void on_PBClear_clicked();

private:
    Ui::CMainWindow *ui;                    /**< Pointer to user interface. */
    KNNData *trainningCases;                /**< Pointer to array with trainning cases. */
    KNNData *testCases;                     /**< Pointer to array with test cases. */
    int Kneighbors;                         /**< Number of neighbors to analyse. */
    int numberOfTrainningCases;             /**< Number of trainning cases. */
    int numberOfTestCases;                  /**< Number of test cases. */
    QVector<double> processingTimes;        /**< Processing times used by graphs. */
    QVector<double> accuracy;               /**< Error percentage used by graphs. */
    QCPBars *barPlot;                       /**< Pointer to bar plot. */

    /**
     *  Verify fields.
     *  Verify data entred by user.
     * @return Fields ok or not.
    */
    bool verifyFields();

    /**
     *  Allocate Data.
     *  Allocate memory to arrays of data.
     * @param numberOfTrainningCases Number of Trainning Cases
     * @param numberOfTestCases Number of Test Cases
    */
    void allocData(int numberOfTrainingCases, int numberOfTestCases);

    /**
     *  Load Data.
     *  Load data from dataset file on arrays.
     * @param dataset Pointer to allocate array
     * @param startAt Where start to load files
     * @param endAt Where stop when load files
    */
    void loadData(KNNData *&dataset, int startAt, int endAt);    

    /**
     *  Plot Error and Time.
     *  Plot the error found and the processing time.
    */
    void plotErrorProcessingTime(double time, double matchs);

    /**
     *  Plot Iris Data.
     *  Plot the trainning cases and test cases.
    */
    void plotIrisData(QVector<int> errorIndexes);

    /**
     * Show Results GB.
     * Show the results found on results group box.
     * @param matchs Number of matchs found
     * @param time Processing time.
    */
    void showResultsGroupBox(int matchs, double time, int threads);

    /**
     * Calculate Accuracy.
     * Calculate the accuracy % using match/nTestCases * 100.
     * @param matchs Number of correct results
     * @return Accuracy (%)
    */
    inline double calculateAccuracy(int matchs) { return (double)((double)matchs/getNumberOfTestCases())*100.0; }

    double calculateDiffTimes();



};
#endif // CMAINWINDOW_H
