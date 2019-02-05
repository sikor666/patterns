#pragma once

#include <vector>

using namespace std;

struct Game;

struct Creature
{
protected:
    Game& game;
    int base_attack, base_defense;

public:
    Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
        base_defense(base_defense) {}
    virtual int get_attack() = 0;
    virtual int get_defense() = 0;

    virtual int attack_modifier() = 0;
    virtual int defense_modifier() = 0;
};

struct Game
{
    vector<Creature*> creatures;

    int attackModifier(Creature* creature)
    {
        int result = 0;
        for (auto c : creatures)
        {
            result += c->attack_modifier();
        }

        return result - creature->attack_modifier();
    }

    int defenseModifier(Creature* creature)
    {
        int result = 0;
        for (auto c : creatures)
        {
            result += c->defense_modifier();
        }

        return result - creature->defense_modifier();
    }
};

struct StatQuery
{
    enum Statistic { attack, defense } statistic;
    int result;
};

class Goblin : public Creature
{
public:
    Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

    Goblin(Game &game) : Creature(game, 1, 1) {}

    int attack_modifier() override
    {
        return 0;
    }

    int defense_modifier() override
    {
        return 1;
    }

    int get_attack() override {
        // todo
        return base_attack + game.attackModifier(this);
    }

    int get_defense() override {
        // todo
        return base_defense + game.defenseModifier(this);
    }
};

class GoblinKing : public Goblin
{
public:
    GoblinKing(Game &game) : Goblin(game, 3, 3) {}

    // todo
    int attack_modifier() override
    {
        return 1;
    }

    int defense_modifier() override
    {
        return 1;
    }
};
