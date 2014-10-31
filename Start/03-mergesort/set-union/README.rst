Unia zbiorów
============

Twoim zadaniem jest wykonanie operacji unii na dwóch zbiorach.

Uwaga: wykorzystaj w tym zadaniu algorytm sortowania std::sort z biblioteki standardowej C++ (lub odpowiednik dla innego języka).

Wejście
=======

::

    n m
    a_1 a_2 a_3 ... a_n
    b_1 b_2 b_3 ... b_m
    
Wyjaśnienie:
  - n - ilość liczb w pierwszym zbiorze
  - m - ilość liczb w drugim zbiorze
  - a_i - pierwszy zbiór (brak duplikatów)
  - b_i - drugi zbiór liczb (brak duplikatów)
  
Ograniczenia:
  - 0 <= n, m <= 1e6
  - 0 <= a_i, b_i <= 1e9

Wyjście
=======
::

    c_1, c_2, c_3, ... c_q

Wyjaśnienie:
  - c_i - unia zbiorów a i b (nie zawiera duplikatów), elementy muszą być w kolejności posortowanej!
  - q - ilość liczb w zbiorze c


Przykład
========

Wejście::

    5 6
    9 3 5 7 1
    2 3 4 9 8 7

Wyjście::

    1 2 3 4 5 7 8 9

