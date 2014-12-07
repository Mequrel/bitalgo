Minimum lokalne funkcji
=======================

Twoim zadaniem jest policzenie minimum funkcji na określonym przedziale. Możesz założyć, że istnieje tylko jedno minimum lokalne w tym przedziale. Funkcja zdefiniowana jest wzorem::

    f(x) = Asin(Bx + C) + De^(Ex + F) + Gln(Hx + I) + J|Kx + L| + M


Wejście
=======

::

    p q
    A B C D E F G H

Wyjaśnienie:
  - p, q - początek i koniec przedziału, na którym szukamy minimum
  - A, B, C, E, F, G, H - współczynniki funkcji
  
Ograniczenia:
  - p <= q
  - p, q, A, B, C, D, E, F, G, H - rzeczywiste, mieszczą się w double
  - Można założyć, że wartości A-H są tak dobrane, aby funkcja była obliczalna dla każdej wartości w zakresie [p; q].

Wyjście
=======
::

    x y

Wyjaśnienie:
  - x - wartość odciętej dla której funkcja przyjmuje minimum w przedziale, zaokrąglona do 3 miejsc po przecinku
  - y = f(x) - wartość funkcji w minimum, zaokrąglona do 3 miejsc po przecinku


Przykład
========

Wejście::

    -10 10
    0 0 0 0 0 0 0 0 0 1 1 1.8 1.4

Wyjście::

    -1.800 1.400

