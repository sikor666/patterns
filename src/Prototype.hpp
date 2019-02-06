#pragma once

/*
 * Prototyp – kreacyjny wzorzec projektowy, którego celem jest umo¿liwienie
 * tworzenia obiektów danej klasy b¹dŸ klas z wykorzystaniem ju¿ istniej¹cego
 * obiektu, zwanego prototypem. G³ównym celem tego wzorca jest uniezale¿nienie
 * systemu od sposobu w jaki tworzone s¹ w nim produkty.
 *
 * Omawiany wzorzec stosujemy miêdzy innymi wtedy, gdy nie chcemy tworzyæ w
 * budowanej aplikacji podklas obiektu buduj¹cego (jak to jest w przypadku
 * wzorca fabryki abstrakcyjnej). Wzorzec ten stosujemy podczas stosowania
 * klas specyfikowanych podczas dzia³ania aplikacji.
 *
 * Wzorzec prototypu okreœla rodzaj obiektów do tworzenia za pomoc¹ prototypowej
 * instancji. Prototypy nowych produktów s¹ czêsto budowane przed pe³n¹ produkcj¹,
 * ale w tym przyk³adzie, prototyp jest bierny i nie bierze udzia³u w kopiowaniu
 * siebie samego. Przyk³adem aktywnego prototypu (czyli bior¹cego udzia³ w
 * kopiowaniu siebie samego) jest biologiczny podzia³ jednej komórki w dwie
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
