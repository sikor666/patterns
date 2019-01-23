/*
 * Kompozyt � strukturalny wzorzec projektowy, kt�rego celem jest sk�adanie obiekt�w w taki spos�b, aby klient widzia� wiele z nich jako pojedynczy obiekt.
 *
 * Wzorzec ten stosuje si�, gdy wygodniej jest korzysta� z pewnych operacji dla danego obiektu w ten sam spos�b jak dla grupy obiekt�w, np. rysuj�c na ekranie prymitywy lub obiekty z�o�one z prymityw�w; zmieniaj�c rozmiar zar�wno pojedynczych prymityw�w jak i obiekt�w z�o�onych z prymityw�w (z zachowaniem proporcji).
 */

#include "exercise.h"

int main()
{
    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    sum({ &single_value, &other_values }); // returns 6
}
