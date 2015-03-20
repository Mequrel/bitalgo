# -*- coding: utf-8 -*-

difficulty = 'Moderate'
problem_name = 'Scalanie zbiorów'

description = '''
Zadanie pozwalajce zobaczyć praktyczne zastosowanie struktury find-union.
'''

problem_statement = '''
Dana jest prostokątna plansza (siatka), na której kolejno ustawiane są kwadratowe, jednostkowe płytki. Twoim zadaniem jest wypisanie ile wysp, tzn. połączonych ze sobą obszarów płytek aktualnie znajduje się na planszy po każdym ustawieniu nowej płytki. Płytek połączonych jedynie rogami nie uznajemy za połączone.

W celu efektywnej implementacji wykorzystaj strukturę union find do reprezentacji zbiorów rozłącznych. Nie używaj gotowych strutur dostarczanych przez biblioteki.
'''

input_format = '''
Pierwsza linia wejścia zawiera dwie liczby całkowite dodatnie $n$ oraz $m$ oznaczające rozmiary planszy. Możesz założyć, że $1 \leq nm \leq 10^6$. W kolejnych $n$ wierszach znajduje się $m$ liczb definiujących kolejność stawiania płytek na planszy. Liczby są z zakresu $[1; nm]$ i każda z nich występuje dokładnie raz.
'''

output_format = '''
Na wyjściu powinno zostać wypisanych $nm$ liczb oznaczających ilość wysp po ułożeniu kolejnych płytek.
'''

sample_input = '''
3 3  
1 9 2
8 4 7
3 5 6
'''

sample_output = '''
1 2 3 4 3 3 2 1 1 
'''

sample_explanation = '''
Po pierwszych czterech ruchach żadne płytki nie stykają się jeszcze bokami. Piąta płytka łączy płytkę trzecią i czwartą w jedną wyspę. Płytka siódma łączy największą wyspę z płytką drugą, a ósma z pierwszą.
'''

### editorial

required_knowledge = 'Zbiory rozłączne, struktura find-union'

time_complexity = 'O(nm lg* nm)'

editorial_author = 'Bartłomiej Szczepanik'

approach = '''

'''

problem_setter = 'Bartłomiej Szczepanik'