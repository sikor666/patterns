#include <string>
using namespace std;

struct Flower
{
    virtual string str() = 0;
    string color;
};

struct Rose : Flower
{
    string str() override {
        return "A rose";
    }
};

struct RedFlower : Flower
{
    RedFlower(Flower& flower_) : flower{ flower_ }
    {
        color = "red";
    }

    Flower& flower;

    string str() override {
        string conjunctive;
        if (flower.color.empty() || flower.color == "red")
        {
            conjunctive = " that is";
        }
        else
        {
            conjunctive = " and";
        }
        return flower.str() + conjunctive + " red";
    }
};

struct BlueFlower : Flower
{
    BlueFlower(Flower& flower_) : flower{ flower_ }
    {
        color = "blue";
    }

    Flower& flower;

    string str() override {
        string conjunctive;
        if (flower.color.empty() || flower.color == "blue")
        {
            conjunctive = " that is";
        }
        else
        {
            conjunctive = " and";
        }
        return flower.str() + conjunctive + " blue";
    }
};
