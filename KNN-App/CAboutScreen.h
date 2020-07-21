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
#ifndef CABOUTSCREEN_H
#define CABOUTSCREEN_H
#include <QDialog>

namespace Ui {
class CAboutScreen;
}

/**
 * Class CAboutScreen.
 * About screen class.
 * @brief Just the definition of about screen.
*/
class CAboutScreen : public QDialog
{
    Q_OBJECT                    /**< Alow Qt to use signal and slots system. */

public:
    /**
     * Class Constructor.
     * A default constructor for CAboutScreen Class created by Qt.
     * @param parent Parent to QWidget base class.
    */
    explicit CAboutScreen(QWidget *parent = nullptr);
    /**
     * Class Destructor.
     * A destructor for CAboutScreen Class created by Qt.
     * @param parent Parent to QWidget base class.
    */
    ~CAboutScreen();

private:
    Ui::CAboutScreen *ui;       /**< Pointer to user interface. */
};

#endif // CABOUTSCREEN_H
