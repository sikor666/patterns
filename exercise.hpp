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
        // todo
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
