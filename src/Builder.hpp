#include <string>
#include <ostream>
#include <vector>

/*
 * Budowniczy (ang. Builder) – kreacyjny wzorzec projektowy, którego celem jest
 * rozdzielenie sposobu tworzenia obiektów od ich reprezentacji. Innymi s³owy
 * proces tworzenia obiektu podzielony jest na kilka mniejszych etapów a ka¿dy
 * z tych etapów mo¿e byæ implementowany na wiele sposobów. Dziêki takiemu
 * rozwi¹zaniu mo¿liwe jest tworzenie ró¿nych reprezentacji obiektów w tym
 * samym procesie konstrukcyjnym: sposób tworzenia obiektów zamkniêty jest w
 * oddzielnych obiektach zwanych Konkretnymi Budowniczymi. Zazwyczaj stosowany
 * jest do konstrukcji obiektów z³o¿onych, których konfiguracja i inicjalizacja
 * jest procesem wieloetapowym. Budowniczy ró¿ni siê od wzorca fabryki
 * abstrakcyjnej oraz pozosta³ych wzorców kreacyjnych tym, ¿e skupia siê na
 * sposobie tworzenia obiektów reprezentuj¹cych produkty. Tworzy drobn¹ czêœæ
 * skomplikowanego produktu za ka¿dym swoim wywo³aniem jednoczeœnie kontroluj¹c
 * stan wykonanej pracy. Klient otrzymuje produkt po zakoñczeniu jego pracy,
 * a nie – tak jak w przypadku Fabryki abstrakcyjnej – bezzw³ocznie. W przypadku
 * Fabryki abstrakcyjnej mo¿liwe jest tak¿e tworzenie kilku obiektów jednoczeœnie.
 * Czêsto oba wzorce s¹ ³¹czone. Nale¿y do grupy wzorców skatalogowanych przez
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
