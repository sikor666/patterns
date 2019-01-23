#include <string>
using namespace std;

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
