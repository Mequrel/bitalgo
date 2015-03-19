# -*- coding: utf-8 -*-

difficulty = 'Moderate'
problem_name = 'Scalanie wielu list'

description = '''
Zadanie pozwalajce zobaczy praktyczne zastosowanie kolejki priorytetowej.
'''

problem_statement = '''
Twoim zadaniem jest złączenie wielu uporządkowanych niemalejąco list w jedną, również uporządkowaną niemalejąco.

W celu efektywnej implementacji wykorzystaj strukturę kolejki priorytetowej (kopca). Nie używaj gotowych kolejek dostarczanych przez bibliotekę standardową języka. Nie używaj również żadnego algorytmu sortowania.
'''

input_format = '''
Pierwsza linia wejścia zawiera jedną liczbę całkowitą $1 \leq n \leq 10^5$. W kolejnych $n$ wierszach znajduje się opis każdego ciągu. Składa się on z liczby $1 \leq k \leq 10^5$, po której następuje $k$ elementów ciągu. Każdy ciąg jest uporządkowany niemalejąco. Można założyć, że łączna liczba elementów we wszystkich ciągach nie przekroczy $10^7$.
'''

output_format = '''
Na wyjściu powinny zostać wypisane wszystkie elementy podanych na wejściu ciągów w porządku niemalejącym.
'''

sample_input = '''
3  
1 8  
2 6 8  
3 1 3 9
'''

sample_output = '''
1 3 6 8 8 9
'''

sample_explanation = '''
Poprawną kolejnością scalania jest np. branie elementów kolejno z III, III, II, I, II, III ciągu.
'''

### editorial

required_knowledge = 'Kopiec, kolejka priorytetowa, sortowanie przez scalanie'

time_complexity = 'O(m lg n), m - liczba elementow we wszystkich ciagach'

editorial_author = 'Bartłomiej Szczepanik'

approach = '''

'''

problem_setter = 'Bartłomiej Szczepanik'