/*
 * Wzorzec mostu (ang. Bridge pattern) � strukturalny wzorzec projektowy, kt�ry
 * pozwala oddzieli� abstrakcj� obiektu od jego implementacji.
 * Zaleca si� stosowanie tego wzorca aby:
 * odseparowa� implementacj� od interfejsu,
 * poprawi� mo�liwo�ci rozbudowy klas, zar�wno implementacji, jak i interfejsu
 * (m.in. przez dziedziczenie),
 * ukry� implementacj� przed klientem, co umo�liwia zmian� implementacji bez zmian
 * interfejsu.
 *
 * W abstrakcji, jak� s� figury geometryczne, mo�na wyszczeg�lni� np. kwadraty,
 * czy tr�jk�ty. Jednak proces rysowania poszczeg�lnych figur mo�e wygl�da� inaczej
 * dla r�nych bibliotek graficznych czy system�w operacyjnych. Wzorzec mostu
 * pozwala na stworzenie nowych klas, kt�re dostarczaj� konkretnych implementacji
 * do rysowania. Klasa abstrakcyjna figury dostarcza informacji o figurze
 * (np. wielko��), podczas gdy implementacja dostarcza interfejs do rysowania.
 */

#include "exercise.hpp"

#include <iostream>

int main()
{
    cout << Triangle(RasterRenderer{}).str() << endl; // returns "Drawing Triangle as pixels"
}
