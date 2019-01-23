/*
 * Kompozyt – strukturalny wzorzec projektowy, którego celem jest sk³adanie obiektów w taki sposób, aby klient widzia³ wiele z nich jako pojedynczy obiekt.
 *
 * Wzorzec ten stosuje siê, gdy wygodniej jest korzystaæ z pewnych operacji dla danego obiektu w ten sam sposób jak dla grupy obiektów, np. rysuj¹c na ekranie prymitywy lub obiekty z³o¿one z prymitywów; zmieniaj¹c rozmiar zarówno pojedynczych prymitywów jak i obiektów z³o¿onych z prymitywów (z zachowaniem proporcji).
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
