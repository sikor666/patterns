#pragma once

class Singleton
{
public:
    static Singleton* createInstance()
    {
        static Singleton singleton;
        return &singleton;
    }

    int a;
};
