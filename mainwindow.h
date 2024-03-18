/**
 * \file mainwindow.h
 * \brief Plik nagłówkowy modułu \a mainwindow.
 * Posiada wszystkie potrzebne parametry i klasy do działania programu
 * \see mainwindow.cpp
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLCDNumber>
#include "punkt.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
    *\param licznik to licznik generacji
    */
    int licznik=1;
private:
    #include "cofanie.h"
    #include "nowa_generacja.h"
    Ui::MainWindow* ui;
    QGraphicsScene* graphic;
    /**
    *\brief Timery
    *\param timer_cof to timer cofania
    *\param timer_gen to timer generowania
    */
    QTimer* timer_cof= nullptr;
    QTimer* timer_gen= nullptr;
    /**
    *\brief Tworzenie tablicy i głowy listy
    *\param glowa to głowa listy potrzebnej do cofania
    *\param tab tablica w której są tworzone nowe generacje
    */
    lista_cofanie* glowa=nullptr;
    punkt tab[Y][X];
    /**
    *\param mapa to element na którym będziemy wyświetlać potrzebne nam rzeczy
    */
    QImage* mapa;
    /**
    *\brief Tworzenie pierwszej generacji
    * Funkcja tworzy pierwszą generację programu
    */
    void pierwsza_generacja();
    /**
    *\brief Wypis
     * Funkcja maluje dane kwadraty w odpowiednie kolory
     */
    void wypis();
    /**
    *\brief Restart
     * Funkcja Restartuje program do momentu startu w innej konfiguracji niż był na początku
     */
    void *button_click_restart();
    /**
    *\brief Wyłącza timery
     * Funkcja wyłącza timery
     */
    void button_click_stop();


};
#endif // MAINWINDOW_H
