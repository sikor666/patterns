#include "exercise.h"

int sum(const vector<ContainsIntegers*> items)
{
    // TODO
    int res = 0;
    for (auto i : items)
    {
        res += i->sum();
    }
    return res;
}
