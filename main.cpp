#include "ChainOfResponsibility.hpp"

#include <cassert>

int main(void)
{
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
