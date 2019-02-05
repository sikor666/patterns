#pragma once

/*
 * Wzorzec mostu (ang. Bridge pattern) � strukturalny wzorzec projektowy, kt�ry
 * pozwala oddzieli� abstrakcj� obiektu od jego implementacji.

 * Zaleca si� stosowanie tego wzorca aby odseparowa� implementacj� od interfejsu,
 * poprawi� mo�liwo�ci rozbudowy klas, zar�wno implementacji, jak i interfejsu
 * (m.in. przez dziedziczenie), ukry� implementacj� przed klientem, co umo�liwia
 * zmian� implementacji bez zmian interfejsu.
 *
 * W abstrakcji, jak� s� figury geometryczne, mo�na wyszczeg�lni� np. kwadraty,
 * czy tr�jk�ty. Jednak proces rysowania poszczeg�lnych figur mo�e wygl�da�
 * inaczej dla r�nych bibliotek graficznych czy system�w operacyjnych. Wzorzec
 * mostu pozwala na stworzenie nowych klas, kt�re dostarczaj� konkretnych
 * implementacji do rysowania. Klasa abstrakcyjna figury dostarcza informacji o
 * figurze (np. wielko��), podczas gdy implementacja dostarcza interfejs do
 * rysowania.
*/

#include <string>

using namespace std;

namespace Bridge
{

struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct Shape
{
    Shape(const Renderer& renderer_) : renderer{ renderer_ }
    {
    }

    string str() const
    {
        return "Drawing " + name + " as " + renderer.what_to_render_as();
    }

    string name;

protected:
    const Renderer& renderer;
};

struct Triangle : Shape
{
    Triangle(const Renderer& renderer_) : Shape{ renderer_ }
    {
        name = "Triangle";
    }
};

struct Square : Shape
{
    Square(const Renderer& renderer_) : Shape{ renderer_ }
    {
        name = "Square";
    }
};

struct RasterRenderer : Renderer
{
    virtual string what_to_render_as() const override
    {
        return "pixels";
    }
};

struct VectorRenderer : Renderer
{
    virtual string what_to_render_as() const override
    {
        return "lines";
    }
};

} // namespace Bridge
