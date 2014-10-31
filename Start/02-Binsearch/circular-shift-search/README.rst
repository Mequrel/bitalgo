Wyszukiwanie w posortowanym, przesuniętym cyklicznie ciągu.
=====

Twoim zadaniem jest wyszukiwanie podanych liczb w posortowanej tablicy, która została przesunięta cyklicznie. To znaczy, że oryginalny ciąg liczb został odcięty w pewnym momencie i powstałe dwie części zostały zamienione miejscami. W szczególności oryginalny ciąg jest również swoim przesunięciem cyklicznym. Przykładowo przesunięciem cyklicznym ciągu 1 2 3 4 5 jest 2 3 4 5 1, 5 4 3 2 1 lub 1 2 3 4 5.

Otrzymasz listę n list w kolejności rosnącej oraz k pytań o pozycję liczby w tablicy, która została wcześniej podana (numerujemy od 1 do n). Jeśli wyszukiwany jest element nieistniejący w tablicy, to powinniśmy zwrócić wartość -1 pozycji. Jeśli liczba występuje wielokrotnie, to należy zwrócić tę, która znajduje się najbliżej początku oryginalnej tablicy bez przesunięcia cyklicznego.

Uwaga: pomijając wczytanie ciągu, program powinien mieć złożoność k * lg n.

Wejście
=======

::

    n k
    a_1 a_2 a_3 ... a_n
    b_1 b_2 b_3 ... b_k

Wyjaśnienie:
  - n - ilość elementów w tablicy
  - k - ilość zapytań
  - a[] - elementy tablicy, posortowane na wejściu i następnie przesunięte cyklicznie
  - b[] - wartości poszukiwane

Ograniczenia:
  - 0 <= n <= 1e6
  - 0 <= k <= 1e6
  - -1e9 <= a_i <= 1e9
  - -1e9 <= b_i <= 1e9

Wyjście
=======
::

    x_1 x_2 x_3 ... x_k

Wyjaśnienie:
  - x_i - pozycja b_i w tablicy a[] lub -1 gdy nie można zlokalizować takiej wartości

Przykład
========

Wejście::

    6 4
    9 10 1 4 9
    4 9 11 1

Wyjście::

    4 5 -1 3
