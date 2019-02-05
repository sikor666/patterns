#pragma once

/*
 * Dekorator � wzorzec projektowy nale��cy do grupy wzorc�w strukturalnych.
 * Pozwala na dodanie nowej funkcji do istniej�cych klas dynamicznie podczas
 * dzia�ania programu.
 *
 * Wzorzec dekoratora polega na opakowaniu oryginalnej klasy w now� klas�
 * "dekoruj�c�". Zwykle przekazuje si� oryginalny obiekt jako parametr
 * konstruktora dekoratora, metody dekoratora wywo�uj� metody oryginalnego
 * obiektu i dodatkowo implementuj� now� funkcj�.
 *
 * Dekoratory s� alternatyw� dla dziedziczenia. Dziedziczenie rozszerza
 * zachowanie klasy w trakcie kompilacji, w przeciwie�stwie do dekorator�w,
 * kt�re rozszerzaj� klasy w czasie dzia�ania programu.
 *
 * Poniewa� w wi�kszo�ci obiektowych j�zyk�w programowania nie mo�na tworzy�
 * nowych klas podczas dzia�ania programu i zwykle nie mo�na przewidzie� z g�ry
 * wszystkich kombinacji rozszerze� klas, konieczne by by�o stworzenie nowej
 * klasy dla ka�dej kombinacji. Dekoratory s� obiektami tworzonymi w czasie
 * dzia�ania programu i mog� by� ��czone w r�ne kombinacje bezpo�rednio przy
 * u�yciu.
*/

#include <string>

using namespace std;

namespace Decorator
{

struct Flower
{
    virtual string str() = 0;

    string message;
};

struct Rose : Flower
{
    Rose()
    {
        message = "A rose";
    }

    string str() override {
        return message;
    }
};

struct RedFlower : Flower
{
    RedFlower(Flower& flower_) : flower{ flower_ }
    {
        if (flower.message == "A rose")
        {
            message = flower.message + " that is red";
        }
        else if (flower.message.find("red") == string::npos)
        {
            message = flower.message + " and red";
        }
        else
        {
            message = flower.message;
        }
    }

    string str() override {
        return message;
    }

    Flower& flower;
};

struct BlueFlower : Flower
{
    BlueFlower(Flower& flower_) : flower{ flower_ }
    {
        if (flower.message == "A rose")
        {
            message = flower.message + " that is blue";
        }
        else if (flower.message.find("blue") == string::npos)
        {
            message = flower.message + " and blue";
        }
        else
        {
            message = flower.message;
        }
    }

    string str() override {
        return message;
    }

    Flower& flower;
};

} // namespace Decorator
