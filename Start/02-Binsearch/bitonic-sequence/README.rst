Ciąg bitoniczny
=====

Twoim zadaniem jest wyszukiwanie maksymalnej wartości w ciągu bitonicznym. Ciąg bitoniczny, to taki ciąg, który najpierw jest niemalejący, a następnie nierosnący, z tym, że może być przesunięty cyklicznie. Przykładowo ciąg 1 2 2 5 3 2 jest bitoniczny, podobnie jak jego przesunięcia cykliczne 2 5 3 2 1 2 czy 5 3 2 1 2 2. Ciąg 1 2 5 3 2 1 już bitoniczny nie jest.

Uwaga: pomijając wczytanie ciągu, program powinien mieć logarytmiczną złożoność obliczeniową.

Wejście
=======

::

    n
    a_1 a_2 a_3 ... a_n

Wyjaśnienie:
  - n - ilość elementów ciągu
  - a[] - elementy ciągu bitonicznego

Ograniczenia:
  - 0 <= n <= 1e6
  - -1e9 <= a_i <= 1e9

Wyjście
=======
::

    m

Wyjaśnienie:
  - m - maksymalna wartość w ciągu

Przykład
========

Wejście::

    6
    5 3 2 1 2 2

Wyjście::

    5
