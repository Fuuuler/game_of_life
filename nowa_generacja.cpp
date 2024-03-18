#include <QPixmap>
#include <QTimer>
#include "mainwindow.h"
#include "nowa_generacja.h"
#include "ui_mainwindow.h"
void MainWindow::generacja(){
    for(int x=1; x<Y-1; ++x){
        for(int y=1; y<X-1; ++y){
            int suma_kumpli=0;
            if(tab[x-1][y-1].obecny_stan==1)
                suma_kumpli++;
            if(tab[x-1][y].obecny_stan==1)
                suma_kumpli++;
            if(tab[x-1][y+1].obecny_stan==1)
                suma_kumpli++;
            if(tab[x][y-1].obecny_stan==1)
                suma_kumpli++;
            if(tab[x][y+1].obecny_stan==1)
                suma_kumpli++;
            if(tab[x+1][y-1].obecny_stan==1)
                suma_kumpli++;
            if(tab[x+1][y].obecny_stan==1)
                suma_kumpli++;
            if(tab[x+1][y+1].obecny_stan==1)
                suma_kumpli++;
            if (tab[x][y].obecny_stan==true)
                tab[x][y].wiek=true;
            if (suma_kumpli==3&&tab[x][y].obecny_stan==0)
                tab[x][y].przyszly_stan=true;
            if (suma_kumpli<2||suma_kumpli>3)
                tab[x][y].przyszly_stan=false;
        }
    }
    for(int x=1; x<Y-1; ++x){
        for(int y=1; y<X-1; ++y){
            if (tab[x][y].przyszly_stan==true){
                tab[x][y].obecny_stan=true;
            }
            if (tab[x][y].przyszly_stan==false){
                tab[x][y].wiek=false;
                tab[x][y].obecny_stan=false;
            }
        }
    }
}
void MainWindow::nowa_generacja(){
    lista_cofanie *nast=new lista_cofanie;
    for(int x=0; x<Y; ++x){
        for(int y=0; y<X; ++y){
            nast->dane[x][y].obecny_stan=tab[x][y].obecny_stan;
            nast->dane[x][y].przyszly_stan=tab[x][y].przyszly_stan;
            nast->dane[x][y].wiek=tab[x][y].wiek;
        }
    }
    nast->nast=glowa;
    glowa=nast;
    generacja();
    ++licznik;
    ui->lcdNumber->display(licznik);
    wypis();
    graphic->clear();
    graphic->addPixmap(QPixmap::fromImage(*mapa));
}
void MainWindow::button_click_generacja(){
    nowa_generacja();
}
void MainWindow::button_click_auto(){
    if (timer_cof!=nullptr)
        timer_cof->stop();
    if (timer_gen==nullptr){
        timer_gen= new QTimer(this);
        connect(timer_gen, &QTimer::timeout, this, &MainWindow::nowa_generacja);
    }
    timer_gen->start(10);
    nowa_generacja();
}
