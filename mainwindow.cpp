#include <QPixmap>
#include <QTimer>
#include <stdlib.h>
#include <time.h>
#include "mainwindow.h"
#include "cofanie.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ///podlaczenie ui
    ui->setupUi(this);
    ///podlaczenie przycisków
    connect(ui->pushButton_1, &QPushButton::pressed, this, &MainWindow::button_click_generacja);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &MainWindow::button_click_auto);
    connect(ui->pushButton_3, &QPushButton::pressed, this, &MainWindow::button_click_stop);
    connect(ui->pushButton_4, &QPushButton::pressed, this, &MainWindow::button_click_restart);
    connect(ui->pushButton_5, &QPushButton::pressed, this, &MainWindow::button_click_cofanie);
    connect(ui->pushButton_6, &QPushButton::pressed, this, &MainWindow::button_click_cofanie_auto);
    ///ustawienie pola na ktorym bedziemy wyswitelać
    mapa = new QImage(size_x, size_y, QImage::Format_RGB32);
    graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(*mapa));
    ui->graphicsView->setScene(graphic);
        ///cześć główna wykonywana raz
        srand(time(0));
        pierwsza_generacja();
        wypis();
        ///czyści obecny stan grafiki
        graphic->clear();
        ///aktualizuje grafikę
        graphic->addPixmap(QPixmap::fromImage(*mapa));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pierwsza_generacja(){
    for(int x=0; x<Y; x++){
        for(int y=0; y<X; y++){
                tab[x][y].przyszly_stan=false;
                tab[x][y].wiek=false;
            if(x==0||x==Y-1||y==0||y==X-1){
                tab[x][y].obecny_stan=false;
            }
            else{
                tab[x][y].obecny_stan=rand()%2;
            }
        }
    }
}
void MainWindow::button_click_stop(){
    if (timer_cof!=nullptr)
        timer_cof->stop();
    if (timer_gen!=nullptr)
        timer_gen->stop();
}
void *MainWindow::button_click_restart(){
    pierwsza_generacja();
    licznik=1;
    ui->lcdNumber->display(licznik);
    wypis();
    graphic->clear();
    graphic->addPixmap(QPixmap::fromImage(*mapa));
    while(glowa){
        lista_cofanie *p=glowa;
        glowa=glowa->nast;
        delete p;
    }
    lista_cofanie *glowa=nullptr;
    return glowa;
}
void MainWindow::wypis(){
    int pixel_size_x = size_x / X;
    int pixel_size_y = size_y / Y;
    int kolor=qRgb(255 ,255 ,255);
    for(int y=0; y<Y; ++y) {
        for(int x=0; x<X; ++x){    
            if(tab[y][x].obecny_stan == true){
                for(int i=0; i<pixel_size_y; ++i) {
                    for(int j=0; j<pixel_size_x; ++j) {

                        if (tab[y][x].wiek == true)
                            mapa->setPixel(pixel_size_x*x+i, pixel_size_y*y+j, kolor);
                        else
                            mapa->setPixel(pixel_size_x*x+i, pixel_size_y*y+j, kolor);

                    }
                }
            }
            else {
                for(int i=0; i<pixel_size_y; ++i) {
                    for(int j=0; j<pixel_size_x; ++j) {
                        mapa->setPixel(pixel_size_x*x+i, pixel_size_y*y+j, qRgb(0,0,0));
                    }
                }
            }
        }
    }
}

