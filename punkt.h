/**
 * \file punkt.h
 * \brief Plik nagłówkowy struktur.
 * Moduł zawiera potrzebne struktury
 */
#ifndef PUNKT_H
#define PUNKT_H
/**
 * \brief Wielkosc na której bedzie wyświetlany program
 * \param size_x to szerokosc w pixelach
 * \param size_y to długość
 */
static const int size_x = 800, size_y = 800;
/**
 * \brief Wielkosc tablicy na której bedzie wyliczany program
 * \param X to szerokosc
 * \param Y to długość
 */
static const int X=800, Y=800;
/**
 * \brief Struktura z której robimy tablice
 * \param obecny_stan to obecny stan komórki w tablicy
 * \param przyszly_stan to przyszły stan komórki w tablicy
 * \param wiek przyjmuję wartość "true" kiedy komórka w dwóch iteracjach jest "żywa"
 */
struct punkt{
    bool obecny_stan;
    bool przyszly_stan;
    bool wiek;
};
/**
 * \brief Struktura z której robimy liste
 * \param punkt
 * \see struct punkt
 * \param lista_cofanie to adres starej komórki
 */
struct lista_cofanie{
    punkt dane[Y][X];
    lista_cofanie *nast;
};
#endif // PUNKT_H
