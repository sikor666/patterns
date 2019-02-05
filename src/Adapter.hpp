#pragma once

/*
 * Adapter (tak¿e: opakowanie, ang. wrapper) – strukturalny wzorzec projektowy,
 * którego celem jest umo¿liwienie wspó³pracy dwóm klasom o niekompatybilnych
 * interfejsach. Adapter przekszta³ca interfejs jednej z klas na interfejs drugiej
 * klasy. Innym zadaniem omawianego wzorca jest opakowanie istniej¹cego
 * interfejsu w nowy.
 *
 * Wzorzec adaptera stosowany jest najczêœciej w przypadku, gdy wykorzystanie
 * istniej¹cej klasy jest niemo¿liwe ze wzglêdu na jej niekompatybilny interfejs.
 * Drugim powodem u¿ycia mo¿e byæ chêæ stworzenia klasy, która bêdzie
 * wspó³pracowa³a z klasami o nieokreœlonych interfejsach.
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
