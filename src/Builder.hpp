#include <string>
#include <ostream>
#include <vector>

/*
 * Budowniczy (ang. Builder) � kreacyjny wzorzec projektowy, kt�rego celem jest
 * rozdzielenie sposobu tworzenia obiekt�w od ich reprezentacji. Innymi s�owy
 * proces tworzenia obiektu podzielony jest na kilka mniejszych etap�w a ka�dy
 * z tych etap�w mo�e by� implementowany na wiele sposob�w. Dzi�ki takiemu
 * rozwi�zaniu mo�liwe jest tworzenie r�nych reprezentacji obiekt�w w tym
 * samym procesie konstrukcyjnym: spos�b tworzenia obiekt�w zamkni�ty jest w
 * oddzielnych obiektach zwanych Konkretnymi Budowniczymi. Zazwyczaj stosowany
 * jest do konstrukcji obiekt�w z�o�onych, kt�rych konfiguracja i inicjalizacja
 * jest procesem wieloetapowym. Budowniczy r�ni si� od wzorca fabryki
 * abstrakcyjnej oraz pozosta�ych wzorc�w kreacyjnych tym, �e skupia si� na
 * sposobie tworzenia obiekt�w reprezentuj�cych produkty. Tworzy drobn� cz��
 * skomplikowanego produktu za ka�dym swoim wywo�aniem jednocze�nie kontroluj�c
 * stan wykonanej pracy. Klient otrzymuje produkt po zako�czeniu jego pracy,
 * a nie � tak jak w przypadku Fabryki abstrakcyjnej � bezzw�ocznie. W przypadku
 * Fabryki abstrakcyjnej mo�liwe jest tak�e tworzenie kilku obiekt�w jednocze�nie.
 * Cz�sto oba wzorce s� ��czone. Nale�y do grupy wzorc�w skatalogowanych przez
 * Gang czworga.
 */

using namespace std;

namespace Builder
{

class CodeBuilder
{
public:
    CodeBuilder(const string& class_name) : className{ class_name }
    {
    }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        members.push_back(make_pair(name, type));

        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.className << "\n{\n";

        for (auto& m : obj.members)
        {
            os << "  " << m.second << " " << m.first << ";\n";
        }

        return os << "};";
    }

private:
    string className;
    vector<pair<string, string>> members;
};

} // namespace Builder
