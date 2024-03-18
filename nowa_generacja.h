/**
 * \file nowa_generacja.h
 * \brief Plik nagłówkowy modułu \a nowa_generacja.
 * Moduł \a nowa_generacja zawiera funkcje które tworzą nowe generacje
 * \see nowa_generacja.cpp
 */
#ifndef NOWA_GENERACJA_H
#define NOWA_GENERACJA_H
    /**
     * \brief Nowa generacja
     * Funkcja Wczytuje nową generację na ekran i zapisuje ją do listy
     */
    void nowa_generacja();
    /**
     * \brief Przycisk nowa_generacja
     * Funkcja pojedyńczo wyświetla nową generację
     */
    void button_click_generacja();
    /**
     * \brief Przycisk nowa_generacja_auto
     * Funkcja nieskończenie wyświetla nową generację. Częstotliwość ograniczona timerem
     */
    void button_click_auto();
    /**
     * \brief Przeliczanie obecnej generacji
     * Funkcja sprawdza sąsiadów jednej komórki i oblicza czy powinna być żywa czy martwwa
     * w drugiej części zmienia stan zgodnie z wyliczeniami
     */
    void generacja();
#endif // NOWA_GENERACJA_H
