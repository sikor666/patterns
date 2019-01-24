/*
 * Dekorator � wzorzec projektowy nale��cy do grupy wzorc�w strukturalnych.
 * Pozwala na dodanie nowej funkcji do istniej�cych klas dynamicznie podczas
 * dzia�ania programu.
 *
 * Wzorzec dekoratora polega na opakowaniu oryginalnej klasy w now� klas�
 * "dekoruj�c�". Zwykle przekazuje si� oryginalny obiekt jako parametr konstruktora
 * dekoratora, metody dekoratora wywo�uj� metody oryginalnego obiektu i dodatkowo
 * implementuj� now� funkcj�.
 */

#include "exercise.hpp"

#include <iostream>

int main()
{
    Rose rose;
    RedFlower red_rose{ rose };
    RedFlower red_red_rose{ red_rose };
    BlueFlower blue_red_rose{ red_rose };
    RedFlower red_blue_red_rose{ blue_red_rose };
    cout << rose.str() << endl; // "A rose"
    cout << red_rose.str() << endl; // "A rose that is red"
    cout << red_red_rose.str() << endl; // "A rose that is red"
    cout << blue_red_rose.str() << endl; // "A rose that is red and blue"
    cout << red_blue_red_rose.str() << endl;
}
