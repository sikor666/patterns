/*
 * Wzorzec mostu (ang. Bridge pattern) – strukturalny wzorzec projektowy, który
 * pozwala oddzieliæ abstrakcjê obiektu od jego implementacji.
 * Zaleca siê stosowanie tego wzorca aby:
 * odseparowaæ implementacjê od interfejsu,
 * poprawiæ mo¿liwoœci rozbudowy klas, zarówno implementacji, jak i interfejsu
 * (m.in. przez dziedziczenie),
 * ukryæ implementacjê przed klientem, co umo¿liwia zmianê implementacji bez zmian
 * interfejsu.
 *
 * W abstrakcji, jak¹ s¹ figury geometryczne, mo¿na wyszczególniæ np. kwadraty,
 * czy trójk¹ty. Jednak proces rysowania poszczególnych figur mo¿e wygl¹daæ inaczej
 * dla ró¿nych bibliotek graficznych czy systemów operacyjnych. Wzorzec mostu
 * pozwala na stworzenie nowych klas, które dostarczaj¹ konkretnych implementacji
 * do rysowania. Klasa abstrakcyjna figury dostarcza informacji o figurze
 * (np. wielkoœæ), podczas gdy implementacja dostarcza interfejs do rysowania.
 */

#include "exercise.hpp"

#include <iostream>

int main()
{
    cout << Triangle(RasterRenderer{}).str() << endl; // returns "Drawing Triangle as pixels"
}
