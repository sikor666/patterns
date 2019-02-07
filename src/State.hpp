#include <iostream>
#include <vector>
#include <string>

/*
 * Stan � czynno�ciowy wzorzec projektowy, kt�ry umo�liwia zmian� zachowania
 * obiektu poprzez zmian� jego stanu wewn�trznego. Innymi s�owy � uzale�nia
 * spos�b dzia�ania obiektu od stanu w jakim si� aktualnie znajduje.
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
