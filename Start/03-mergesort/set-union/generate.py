from random import randrange
from random import shuffle

case_number = 0

def test_case(numbers1, numbers2):
  global case_number

  with open(str(case_number) + ".in", "w") as output:
    output.write("{0} {1}\n".format(len(numbers1), len(numbers2)))
    for number in numbers1:
      output.write(str(number) + " ")
    for number in numbers2:
      output.write(str(number) + " ")

  case_number += 1

def test_case_random(n, m):
  numbers1 = list(set([randrange(0, 10**9) for i in xrange(0, n)]))
  numbers2 = list(set([randrange(0, 10**9) for i in xrange(0, m)]))
  test_case(numbers1, numbers2)

test_case([9, 3, 5, 7, 1], [2, 3, 4, 9, 8, 7])
test_case([1], [1])
test_case([], [])
test_case([], [3, 2, 1])
test_case([3, 2, 1], [])
test_case_random(1, 10**6)
test_case_random(10**6, 10**6)
