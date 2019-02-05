#pragma once

/*
 * Dekorator – wzorzec projektowy nale¿¹cy do grupy wzorców strukturalnych.
 * Pozwala na dodanie nowej funkcji do istniej¹cych klas dynamicznie podczas
 * dzia³ania programu.
 *
 * Wzorzec dekoratora polega na opakowaniu oryginalnej klasy w now¹ klasê
 * "dekoruj¹c¹". Zwykle przekazuje siê oryginalny obiekt jako parametr
 * konstruktora dekoratora, metody dekoratora wywo³uj¹ metody oryginalnego
 * obiektu i dodatkowo implementuj¹ now¹ funkcjê.
 *
 * Dekoratory s¹ alternatyw¹ dla dziedziczenia. Dziedziczenie rozszerza
 * zachowanie klasy w trakcie kompilacji, w przeciwieñstwie do dekoratorów,
 * które rozszerzaj¹ klasy w czasie dzia³ania programu.
 *
 * Poniewa¿ w wiêkszoœci obiektowych jêzyków programowania nie mo¿na tworzyæ
 * nowych klas podczas dzia³ania programu i zwykle nie mo¿na przewidzieæ z góry
 * wszystkich kombinacji rozszerzeñ klas, konieczne by by³o stworzenie nowej
 * klasy dla ka¿dej kombinacji. Dekoratory s¹ obiektami tworzonymi w czasie
 * dzia³ania programu i mog¹ byæ ³¹czone w ró¿ne kombinacje bezpoœrednio przy
 * u¿yciu.
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
