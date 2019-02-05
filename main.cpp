#include "Adapter.hpp"
#include "Decorator.hpp"
#include "Bridge.hpp"
#include "Composite.hpp"
#include "ChainOfResponsibility.hpp"

#include <cassert>

int main(void)
{
    // Adapter
    using namespace Adapter;
    Square sq{ 11 };
    SquareToRectangleAdapter adapter{ sq };
    assert(121 == adapter.area());

    // Decorator
    using namespace Decorator;
    Rose rose;
    RedFlower red_rose{ rose };
    RedFlower red_red_rose{ red_rose };
    BlueFlower blue_red_rose{ red_rose };
    RedFlower red_blue_red_rose{ blue_red_rose };
    assert("A rose" == rose.str());
    assert("A rose that is red" == red_rose.str());
    assert("A rose that is red" == red_red_rose.str());
    assert("A rose that is red and blue" == blue_red_rose.str());
    assert("A rose that is red and blue" == red_blue_red_rose.str());

    // Bridge
    using namespace Bridge;
    assert("Drawing Triangle as pixels" == Triangle(RasterRenderer{}).str());

    // Composite
    using namespace Composite;
    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    auto value = sum({ &single_value, &other_values });
    assert(6 == value);

    // Chain of Responsibility
    using namespace ChainOfResponsibility;
    Game game;
    Goblin goblin1(game);
    Goblin goblin2(game);
    Goblin goblin3(game);
    GoblinKing goblinKing(game);
    game.creatures.push_back(&goblin1);
    game.creatures.push_back(&goblin2);
    game.creatures.push_back(&goblin3);
    game.creatures.push_back(&goblinKing);
    assert(2 == goblin1.get_attack());
    assert(4 == goblin1.get_defense());
    assert(3 == goblinKing.get_attack());
    assert(6 == goblinKing.get_defense());
}
