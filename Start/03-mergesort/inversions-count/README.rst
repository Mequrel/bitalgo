Inwersje
========

Twoim zadaniem jest zliczenie wszystkich inwersji w danym ciągu a_i. Inwersję definiujemy jako parę (a_j, a_k) taką, że  j < k i a_j > a_k.

Uwaga: wykorzystaj sortowanie przez scalanie.

Wejście
=======

::

    n
    a_1 a_2 a_3 ... a_n
    
Wyjaśnienie:
  - n - ilość liczb
  - a_i - ciąg liczb
  
Ograniczenia:
  - 0 <= n <= 1e6
  - 0 <= a_i <= 1e9

Wyjście
=======
::

    x

Wyjaśnienie:
  - x - ilość inwersji w ciągu


Przykład
========

Wejście::

    5
    4 3 1 5 3

Wyjście::

    5

Wyjaśnienie: inwersje w tym ciągu to: (4,3), (4,1), (4,3), (3,1), (5,3)

