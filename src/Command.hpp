/*
 * Polecenie (ang. Command, komenda) � czynno�ciowy wzorzec projektowy, traktuj�cy
 * ��danie wykonania okre�lonej czynno�ci jako obiekt, dzi�ki czemu mog� by� one
 * parametryzowane w zale�no�ci od rodzaju odbiorcy, a tak�e umieszczane w
 * kolejkach i dziennikach.
 *
 * Rozpatrzmy typow� aplikacj� okienkow� realizuj�c� jakie� zadanie. U�ytkownik
 * mo�e wykona� w niej r�ne czynno�ci. Chcemy umo�liwi� mu cofanie zmian oraz
 * przegl�danie ich historii, dlatego niezb�dny jest nam mechanizm, kt�ry opr�cz
 * obs�ugi ��da�, b�dzie je tak�e zapami�tywa� na stosie.
 */

namespace Cmd
{

struct Command
{
    enum Action { deposit, withdraw } action;
    int amount{ 0 };
    bool success{ false };
};

struct Account
{
    int balance{ 0 };

    void process(Command& cmd)
    {
        switch (cmd.action)
        {
        case Command::Action::deposit:
            balance += cmd.amount;
            cmd.success = true;
            break;
        case Command::Action::withdraw:
            if (balance >= cmd.amount)
            {
                balance -= cmd.amount;
                cmd.success = true;
            }
            else
            {
                cmd.success = false;
            }
            break;
        }
    }
};

} // namespace Cmd
