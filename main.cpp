/**
*\mainpage
*\par Game of Life
* Automat komórkowy "Game of Life"
*\author WiktorWasaznik
*\date 17.03.2022
*\version 1.0
*\par Kontakt:
* email: 01171787@pw.edu.pl
*/
/**
* \file main.cpp
* \brief Plik z funkcją main(int argc, char* argv[])
*/
#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
