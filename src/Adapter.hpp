#pragma once

/*
 * Adapter (tak�e: opakowanie, ang. wrapper) � strukturalny wzorzec projektowy,
 * kt�rego celem jest umo�liwienie wsp�pracy dw�m klasom o niekompatybilnych
 * interfejsach. Adapter przekszta�ca interfejs jednej z klas na interfejs drugiej
 * klasy. Innym zadaniem omawianego wzorca jest opakowanie istniej�cego
 * interfejsu w nowy.
 *
 * Wzorzec adaptera stosowany jest najcz�ciej w przypadku, gdy wykorzystanie
 * istniej�cej klasy jest niemo�liwe ze wzgl�du na jej niekompatybilny interfejs.
 * Drugim powodem u�ycia mo�e by� ch�� stworzenia klasy, kt�ra b�dzie
 * wsp�pracowa�a z klasami o nieokre�lonych interfejsach.
 */

namespace Adapter
{

struct Square
{
    int side{ 0 };

    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square& square_) : square{ square_.side }
    {
    }

    virtual int width() const
    {
        return square.side;
    }

    virtual int height() const
    {
        return square.side;
    }

    Square square;
};

} // namespace Adapter
