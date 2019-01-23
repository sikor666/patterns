#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

    // TODO
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

int sum(const vector<ContainsIntegers*> items);