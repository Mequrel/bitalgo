from random import randrange

case_number = 0

def test_case(numbers):
  global case_number

  with open(str(case_number) + ".in", "w") as output:
    output.write(str(len(numbers)))
    output.write("\n")
    for number in numbers:
      output.write(str(number) + " ")

  case_number += 1

def test_case_n(n, f):
  numbers = [f(i) for i in xrange(0, n)]
  test_case(numbers)

test_case([9, 8, 11, 20, 3, 1, 9, 5, 9, 10])
test_case([])
test_case([100])
test_case_n(100, f=lambda i: randrange(0, 100))
test_case_n(10**3, f=lambda i: randrange(0, 10**3))
test_case_n(10**4, f=lambda i: randrange(0, 10**4))
test_case_n(10**5, f=lambda i: randrange(0, 10**5))
test_case_n(10**6, f=lambda i: randrange(0, 10**6))
test_case_n(10**6, f=lambda i: randrange(0, 10**9))
test_case_n(10**6, f=lambda i: i)
test_case_n(10**6, f=lambda i: 10**6 - i)
