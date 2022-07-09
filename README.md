# Program for assessing the quality of impulse noise reduction in a color image

The program allows you to load a clean, noisy and filtered image (from a file) and the designate:

- the original noise map (at the level of a clean and noisy image),
- the estimated noise map (at the level of clear and filtered image). Program for determining such activities: PSNR, MAE and Accuracy The program provides such an opportunity to compare the exclusion map, a color map that has the results marked:
- correct positive (noise pixels correctly detected) - green color
- black (black) color (original panels detected) - black color
- false false (original red pixels for noise) - false
- false false white (undetected noise criteria) - The program provided the ability to derive target chart data for the MAE. The program implements a noise generator and a switching filter that allows for a smooth simulation of the implementation.

 I wrote the project during the first year of studies in Qt technology. 

##
# Program do oceny jakości redukcji szumu impulsowego w obrazie barwnym
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

Projekt napisałem na pierwszym roku studiów w technologii Qt.
