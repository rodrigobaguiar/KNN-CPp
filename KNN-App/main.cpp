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

#include "CMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow w;
    w.show();
    return a.exec();
}

/**
 * @mainpage KNN-Cpp
 *
 * @section about Sobre
 *
 * KNN-CPp é uma interface gráfica feita em C++/Qt para visualização e comparação de desempenho de redes KNN (*k-nearest neighbors*) utilizando a base de dados de Iris.
 * A ideia é implementar as rotinas em modo serial, paralelo e utilizando CUDA. Quem sabe mais pra frente implementar outros modelos. Só uma brincadeira :)
 *
 * @subsection versions Softwares/Bibliotecas utilizadas
 * Linux Mint 20\n
 * Qt 5.15.0 Open Source \n
 * Compilador Clang x68 64bits\n
 * CUDA 11.0\n
 *
 * @section contact Contato
 * Rodrigo Bittencourt de Aguiar: \n
 * <a href="mailto:rbaguiar@id.uff.br">rbaguiar@id.uff.br</a>\n
 * <a href="mailto:rodrigo.b.aguiar@gmail.com">rodrigo.b.aguiar@gmail.com</a>\n
 */
