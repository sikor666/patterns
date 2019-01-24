#include <string>
using namespace std;

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
