#pragma once

/*
 * Py³ek (ang. Flyweight) – strukturalny wzorzec projektowy, którego celem jest
 * zmniejszenie wykorzystania pamiêci poprzez poprawê efektywnoœci obs³ugi du¿ych
 * obiektów zbudowanych z wielu mniejszych elementów poprzez wspó³dzielenie
 * wspólnych ma³ych elementów[1]. Nale¿y do grupy wzorców skatalogowanych przez
 * Gang of Four.
 *
 * Wzorzec Py³ek stosuje siê tam, gdzie jedna klasa ma wiele egzemplarzy, a ka¿dy
 * z tych egzemplarzy mo¿e byæ sterowany w ten sam sposób. Przyk³adowo ten¿e
 * wzorzec mo¿na zastosowaæ w programie wspomagaj¹cym modelowanie przestrzenne
 * terenu. Jednym z wielu elementów, które musz¹ siê w nim znaleŸæ s¹ obiekt
 * reprezentuj¹cy drzewo. Zak³adamy, ¿e obiekt taki posiada informacje o wygl¹dzie
 * drzewa oraz jakieœ inne jego cechy, przy czym tak¿e jego wysokoœci oraz jego
 * wspó³rzêdne po³o¿enia. Podczas modelowania wielkich kompleksów zieleni
 * z³o¿onych z wielu egzemplarzy drzewa program mo¿e zacz¹æ dzia³aæ
 * niezadowalaj¹co wolno. Aby uporaæ siê z takim problemem mo¿na zastosowaæ
 * wzorzec Py³ek. Po zastosowaniu tego wzorca projektowego zamiast tworzyæ
 * indywidualny egzemplarz klasy (obiekt) dla ka¿dego drzewa mo¿liwe jest
 * stworzenie kompleksowego obiektu, który bêdzie w sobie zawiera³ informacje o
 * wszystkich drzewach renderowanych na modelowanym terenie. W takim obiekcie z
 * racji tego, ¿e wszystkie renderowane drzewa maj¹ pewne cechy wspólne, takie jak
 * np. wygl¹d, informacje te bêd¹ zapisane tylko raz (choæ drzew mo¿e byæ tysi¹ce),
 * a zwielokrotniane bêd¹ jedynie informacje ró¿ne dla ka¿dego drzewa tak jak
 * np. wspó³rzêdne i wysokoœæ. Sposób wykonania tej idei oraz jej implementacja
 * zale¿y od woli programisty.
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
