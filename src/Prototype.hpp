#pragma once

/*
 * Prototyp � kreacyjny wzorzec projektowy, kt�rego celem jest umo�liwienie
 * tworzenia obiekt�w danej klasy b�d� klas z wykorzystaniem ju� istniej�cego
 * obiektu, zwanego prototypem. G��wnym celem tego wzorca jest uniezale�nienie
 * systemu od sposobu w jaki tworzone s� w nim produkty.
 *
 * Omawiany wzorzec stosujemy mi�dzy innymi wtedy, gdy nie chcemy tworzy� w
 * budowanej aplikacji podklas obiektu buduj�cego (jak to jest w przypadku
 * wzorca fabryki abstrakcyjnej). Wzorzec ten stosujemy podczas stosowania
 * klas specyfikowanych podczas dzia�ania aplikacji.
 *
 * Wzorzec prototypu okre�la rodzaj obiekt�w do tworzenia za pomoc� prototypowej
 * instancji. Prototypy nowych produkt�w s� cz�sto budowane przed pe�n� produkcj�,
 * ale w tym przyk�adzie, prototyp jest bierny i nie bierze udzia�u w kopiowaniu
 * siebie samego. Przyk�adem aktywnego prototypu (czyli bior�cego udzia� w
 * kopiowaniu siebie samego) jest biologiczny podzia� jednej kom�rki w dwie
 * identyczne. Wtedy mamy do czynienia z klonowaniem.
 */

namespace Prototype
{

struct Point
{
    int x{ 0 }, y{ 0 };

    Point() {}

    Point(const int x, const int y) : x{ x }, y{ y } {}
};

struct Line
{
    Point *start, *end;

    Line(Point* const start, Point* const end)
        : start(start), end(end)
    {
    }

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        return Line{ new Point{ start->x, start->y },
                     new Point{ end->x, end->y } };
    }
};

} // namespace Prototype
