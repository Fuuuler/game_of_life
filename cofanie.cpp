#include <QPixmap>
#include <QTimer>
#include "mainwindow.h"
#include "cofanie.h"
#include "ui_mainwindow.h"
void *MainWindow::cofanie(){
    if(licznik!=1){
        for(int x=0; x<Y; ++x){
            for(int y=0; y<X; ++y){
                tab[x][y].obecny_stan=glowa->dane[x][y].obecny_stan;
                tab[x][y].przyszly_stan=glowa->dane[x][y].przyszly_stan;
                tab[x][y].wiek=glowa->dane[x][y].wiek;
            }
        }
        --licznik;
        ui->lcdNumber->display(licznik);
        lista_cofanie *zmienna=glowa->nast;
        delete glowa;
        glowa=zmienna;
        wypis();
        graphic->clear();
        graphic->addPixmap(QPixmap::fromImage(*mapa));
    }
    return glowa;
}
void *MainWindow::button_click_cofanie(){
    cofanie();
    return glowa;
}
void *MainWindow::button_click_cofanie_auto(){
    if (timer_gen!=nullptr)
        timer_gen->stop();
    if(licznik!=1){
        cofanie();
        if (timer_cof==nullptr){
            timer_cof= new QTimer(this);
            connect(timer_cof, &QTimer::timeout, this, &MainWindow::cofanie);
        }
        timer_cof->start(10);
    }
    return glowa;
}
