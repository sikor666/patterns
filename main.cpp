/*
 * Dekorator – wzorzec projektowy nale¿¹cy do grupy wzorców strukturalnych.
 * Pozwala na dodanie nowej funkcji do istniej¹cych klas dynamicznie podczas
 * dzia³ania programu.
 *
 * Wzorzec dekoratora polega na opakowaniu oryginalnej klasy w now¹ klasê
 * "dekoruj¹c¹". Zwykle przekazuje siê oryginalny obiekt jako parametr konstruktora
 * dekoratora, metody dekoratora wywo³uj¹ metody oryginalnego obiektu i dodatkowo
 * implementuj¹ now¹ funkcjê.
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
