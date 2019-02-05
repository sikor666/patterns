#pragma once

/*
 * Py�ek (ang. Flyweight) � strukturalny wzorzec projektowy, kt�rego celem jest
 * zmniejszenie wykorzystania pami�ci poprzez popraw� efektywno�ci obs�ugi du�ych
 * obiekt�w zbudowanych z wielu mniejszych element�w poprzez wsp�dzielenie
 * wsp�lnych ma�ych element�w[1]. Nale�y do grupy wzorc�w skatalogowanych przez
 * Gang of Four.
 *
 * Wzorzec Py�ek stosuje si� tam, gdzie jedna klasa ma wiele egzemplarzy, a ka�dy
 * z tych egzemplarzy mo�e by� sterowany w ten sam spos�b. Przyk�adowo ten�e
 * wzorzec mo�na zastosowa� w programie wspomagaj�cym modelowanie przestrzenne
 * terenu. Jednym z wielu element�w, kt�re musz� si� w nim znale�� s� obiekt
 * reprezentuj�cy drzewo. Zak�adamy, �e obiekt taki posiada informacje o wygl�dzie
 * drzewa oraz jakie� inne jego cechy, przy czym tak�e jego wysoko�ci oraz jego
 * wsp�rz�dne po�o�enia. Podczas modelowania wielkich kompleks�w zieleni
 * z�o�onych z wielu egzemplarzy drzewa program mo�e zacz�� dzia�a�
 * niezadowalaj�co wolno. Aby upora� si� z takim problemem mo�na zastosowa�
 * wzorzec Py�ek. Po zastosowaniu tego wzorca projektowego zamiast tworzy�
 * indywidualny egzemplarz klasy (obiekt) dla ka�dego drzewa mo�liwe jest
 * stworzenie kompleksowego obiektu, kt�ry b�dzie w sobie zawiera� informacje o
 * wszystkich drzewach renderowanych na modelowanym terenie. W takim obiekcie z
 * racji tego, �e wszystkie renderowane drzewa maj� pewne cechy wsp�lne, takie jak
 * np. wygl�d, informacje te b�d� zapisane tylko raz (cho� drzew mo�e by� tysi�ce),
 * a zwielokrotniane b�d� jedynie informacje r�ne dla ka�dego drzewa tak jak
 * np. wsp�rz�dne i wysoko��. Spos�b wykonania tej idei oraz jej implementacja
 * zale�y od woli programisty.
 */

#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace Flyweight
{

struct Sentence
{
    struct WordToken
    {
        bool capitalize;
    };

    Sentence(const string& text)
    {
        stringstream ss(text);
        string item;

        while (getline(ss, item, ' '))
        {
            words.push_back(make_pair(item, WordToken{ false }));
        }
    }

    WordToken& operator[](size_t index)
    {
        return words[index].second;
    }

    string str() const
    {
        stringstream ss;

        for (size_t i = 0; i < words.size(); ++i)
        {
            if (words[i].second.capitalize)
            {
                for (auto c : words[i].first)
                {
                    ss << static_cast<char>(toupper(c));
                }
            }
            else
            {
                ss << words[i].first;
            }

            if (i < words.size() - 1)
            {
                ss << ' ';
            }
        }

        return ss.str();
    }

private:
    vector<pair<string, WordToken>> words;
};

} // namespace Flyweight
