Wyszukiwanie w posortowanym ciągu.
=====

Twoim zadaniem jest wyszukiwanie podanych liczb w posortowanej tablicy. Otrzymasz listę n liczb w kolejności rosnącej oraz k pytań o pozycję liczby w tablicy, która została wcześniej podana (numerujemy od 1 do n). Jeśli wyszukiwany jest element nieistniejący w tablicy, to powinniśmy zwrócić wartość -1 pozycji. Jeśli liczba występuje wielokrotnie, to należy zwrócić tę, która znajduje się najbliżej początku tablicy.

Wejście
=======

::

    n k
    a_1 a_2 a_3 ... a_n
    b_1 b_2 b_3 ... b_k

Wyjaśnienie:
  - n - ilość elementów w tablicy
  - k - ilość zapytań
  - a[] - elementy tablicy, posortowane na wejściu
  - b[] - wartości poszukiwane

Ograniczenia:
  - 0 <= n <= 1e6
  - 0 <= k <= 1e6
  - -1e9 <= a_i <= 1e9
  - -1e9 <= b_i <= 1e9
  - a_1 <= a_2 <= a_3 <= ... <= a_n

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
    1 4 9 9 10
    4 9 11 1

Wyjście::

    2 3 -1 1
