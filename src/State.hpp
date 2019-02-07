#include <iostream>
#include <vector>
#include <string>

/*
 * Stan – czynnoœciowy wzorzec projektowy, który umo¿liwia zmianê zachowania
 * obiektu poprzez zmianê jego stanu wewnêtrznego. Innymi s³owy – uzale¿nia
 * sposób dzia³ania obiektu od stanu w jakim siê aktualnie znajduje.
 */

using namespace std;

namespace State
{

class CombinationLock
{
    vector<int> combination;
    string digits;

public:
    string status;

    CombinationLock(const vector<int> &combination)
        : combination(combination), status("LOCKED")
    {
        for (auto c : combination)
            digits += to_string(c);
    }

    void enter_digit(int digit)
    {
        if (status == "LOCKED" ||
            status == "OPEN" ||
            status == "ERROR")
            status.clear();

        status += to_string(digit);

        if (status == digits)
            status = "OPEN";
        else if (status.size() == digits.size())
            status = "ERROR";
    }
};

} // namespace State
