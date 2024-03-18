/**
 * \file cofanie.h
 * \brief Plik nagłówkowy modułu \a cofanie.
 * Moduł \a cofanie zawiera funkcje które cofają generację
 * \see cofanie.cpp
 */
#ifndef COFANIE_H
#define COFANIE_H
    /**
     * \brief Cofanie generacji
     * Funkcja cofa generację jeśli może, przy pomocy wypełnionej listy
     */
    void *cofanie();
    /**
     * \brief Przycisk stara_generacja
     * Funkcja pojedyńczo wyświetla starą generację
     */
    void *button_click_cofanie();
    /**
     * \brief Przycisk cofa_generacja_auto
     * Funkcja nieskończenie wyświetla starą generację. Częstotliwość ograniczona timerem
     */
    void *button_click_cofanie_auto();
#endif // COFANIE_H
