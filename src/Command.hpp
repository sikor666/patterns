/*
 * Polecenie (ang. Command, komenda) – czynnoœciowy wzorzec projektowy, traktuj¹cy
 * ¿¹danie wykonania okreœlonej czynnoœci jako obiekt, dziêki czemu mog¹ byæ one
 * parametryzowane w zale¿noœci od rodzaju odbiorcy, a tak¿e umieszczane w
 * kolejkach i dziennikach.
 *
 * Rozpatrzmy typow¹ aplikacjê okienkow¹ realizuj¹c¹ jakieœ zadanie. U¿ytkownik
 * mo¿e wykonaæ w niej ró¿ne czynnoœci. Chcemy umo¿liwiæ mu cofanie zmian oraz
 * przegl¹danie ich historii, dlatego niezbêdny jest nam mechanizm, który oprócz
 * obs³ugi ¿¹dañ, bêdzie je tak¿e zapamiêtywa³ na stosie.
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
