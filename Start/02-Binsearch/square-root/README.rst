Pierwiastek kwadratowy i sześcienny.
=====

Twoim zadaniem jest policzenie pierwiastków kwadratowych i sześciennych dla podanych liczb całkowitych. Wynik proszę zaokrąglić do najbliższej liczby całkowitej, zgodnie ze standardową konwencją (0.5 -> 1).

Uwaga: nie korzystaj z gotowych bibliotek matematycznych do liczenia pierwiastków.

Wejście
=======

::

    n
    a_1 a_2 a_3 ... a_n
    
Wyjaśnienie:
  - n - ilość liczb
  - a_i - ciąg liczb
  
Ograniczenia:
  - 0 <= n <= 1e5
  - 0 <= a_i <= 1e18

Wyjście
=======
::

    sq_1 cu_1
    sq_2 cu_2
    ...
    sq_n cu_n

Wyjaśnienie:
  - sq_i - pierwiastek kwadratowy liczby a_i zaokrąglony do najbliższej liczby całkowitej
  - cu_i - pierwiastek sześcienny liczby a_i zaokrąglony do najbliższej liczby całkowitej


Przykład
========

Wejście::

    5
    4 0 8 27 15

Wyjście::

    2 2
    0 0
    3 2
    5 3
    2 4

