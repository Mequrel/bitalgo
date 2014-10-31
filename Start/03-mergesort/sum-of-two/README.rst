Dwie gry
========

Św. Mikołaj podarował Maćkowi kupon umożliwiający kupno gier w popularnym serwisie internetowym o maksymalnej wartości x złotych. Maciek chciałby kupić dwie gry. Nie chce by kupon się nawet częściowo zmarnował, więc ma zamiar kupić takie dwie gry, których łączna cena wynosi x złotych. 

Znając ceny wszystkich gier w sklepie, pomoż Maćkowi wybrać dla niego gry. 

Uwaga: nie korzystaj z gotowych bibliotek do sortowania i napisz własny algorytm sortowania przez scalanie (mergesort).

Wejście
=======

::

    x n 
    a_1 a_2 a_3 ... a_n
    
Wyjaśnienie:
  - x - wartość kuponu na gry
  - n - ilość gier w sklepie
  - a_i - cena poszczególnej gry
  
Ograniczenia:
  - 0 <= x <= 2e9
  - 0 <= n <= 1e6
  - 0 <= a_i <= 1e9

Wyjście
=======
::

    i j

Wyjaśnienie:
  - i, j - numery gier, które powinien kupić Maciek (pozycje w ciągu, numerujemy od 1). Jeśli nie istnieje taka para gier, to program powinien wypisać dwukrotnie -1.


Przykład
========

Wejście::

    13 10
    9 8 11 20 3 1 9 5 9 13

Wyjście::

    2 8

Inny przykład

Wejście::

    2 10
    9 8 11 20 3 1 9 5 9 13

Wyjście::

    -1 -1
