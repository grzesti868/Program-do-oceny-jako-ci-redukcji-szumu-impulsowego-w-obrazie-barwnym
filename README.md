# Program-do-oceny-jako-ci-redukcji-szumu-impulsowego-w-obrazie-barwnym
Projekt napisałem na pierwszym roku studiów w technologii Qt.
Program umożliwia wczytanie obrazu czystego, zaszumionego i odfiltrowanego (z pliku)
i wyznaczyć:
- oryginalną mapę szumu (na bazie obrazu czystego i zaszumionego),
- estymowaną mapę szumu (na bazie obrazu czystego i odfiltrowanego).
Następnie program wyznacza miary: PSNR, MAE i Accuracy 
Program dostarcza możliwość porównania obu map szumu i wyznaczenia kolorowej mapy
detekcji, w której zaznaczone są wyniki:
- prawdziwie dodatnie (poprawnie wykryte piksele szumu) – kolor zielony
- prawdziwe ujemne (popranie wykryte piksele oryginalne) – kolor czarny
- fałszywie dodatnie (piksele oryginalne uznane za szum) – kolor czerwony
- fałszywie ujemne (niewykryte piksele szumu) – kolor biały
Program dostarcza możliwość rysowania wykresów tarczowych dla wskaźnika MAE.
Program ma zaimplementowany generator szumu i filtr przełączeniowy, który pozwala na
płynną symulację detekcji.
