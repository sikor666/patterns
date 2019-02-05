#pragma once

/*
 * Kompozyt � strukturalny wzorzec projektowy, kt�rego celem jest sk�adanie
 * obiekt�w w taki spos�b, aby klient widzia� wiele z nich jako pojedynczy obiekt.
 *
 * Wzorzec ten stosuje si�, gdy wygodniej jest korzysta� z pewnych operacji dla
 * danego obiektu w ten sam spos�b jak dla grupy obiekt�w, np. rysuj�c na ekranie
 * prymitywy lub obiekty z�o�one z prymityw�w; zmieniaj�c rozmiar zar�wno
 * pojedynczych prymityw�w jak i obiekt�w z�o�onych z prymityw�w (z zachowaniem
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
