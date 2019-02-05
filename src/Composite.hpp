#pragma once

/*
 * Kompozyt – strukturalny wzorzec projektowy, którego celem jest sk³adanie
 * obiektów w taki sposób, aby klient widzia³ wiele z nich jako pojedynczy obiekt.
 *
 * Wzorzec ten stosuje siê, gdy wygodniej jest korzystaæ z pewnych operacji dla
 * danego obiektu w ten sam sposób jak dla grupy obiektów, np. rysuj¹c na ekranie
 * prymitywy lub obiekty z³o¿one z prymitywów; zmieniaj¹c rozmiar zarówno
 * pojedynczych prymitywów jak i obiektów z³o¿onych z prymitywów (z zachowaniem
 * proporcji).
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Composite
{

struct ContainsIntegers
{
    virtual int sum() = 0;
};

struct SingleValue : ContainsIntegers
{
    int value{ 0 };

    SingleValue() = default;

    explicit SingleValue(const int value)
        : value{ value }
    {
    }

    virtual int sum() override
    {
        return value;
    }
};

struct ManyValues : ContainsIntegers, vector<int>
{
    void add(const int value)
    {
        push_back(value);
    }

    virtual int sum() override
    {
        int res = 0;

        for (auto it = begin(); it != end(); ++it)
        {
            res += *it;
        }

        return res;
    }
};

int sum(const vector<ContainsIntegers*> items)
{
    int res = 0;

    for (auto i : items)
    {
        res += i->sum();
    }

    return res;
}

} // namespace Composite
