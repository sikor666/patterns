#include <string>
#include <ostream>
#include <vector>

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
