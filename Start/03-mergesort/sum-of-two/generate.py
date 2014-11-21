from random import randrange

case_number = 0

def test_case(numbers, s):
  global case_number

  with open(str(case_number) + ".in", "w") as output:
    output.write(str(len(numbers)))
    output.write(" ")
    output.write(str(s))
    output.write("\n")
    for number in numbers:
      output.write(str(number) + " ")

  case_number += 1

def test_case_n(n, f, s):
  numbers = [f(i) for i in xrange(0, n)]
  test_case(numbers, s)

test_case([9, 8, 11, 20, 3, 1, 9, 5, 9, 13], 10)
test_case([9, 8, 11, 20, 3, 1, 9, 5, 9, 13], 2)
test_case([], 2)
test_case([100], 100)
test_case([1, 2], 2)  # for bad bin_search
test_case([1, 2, 3], 0)
test_case_n(100, lambda i: randrange(0, 100), 201)
test_case_n(10**3, lambda i: randrange(0, 10**3), 100)
test_case_n(10**4, lambda i: randrange(0, 10**4), 2)
test_case_n(10**5, lambda i: randrange(0, 10**5), 1000)
test_case_n(10**6, lambda i: randrange(0, 10**6), 3*10**6)
test_case_n(10**6, lambda i: randrange(0, 10**9), 450)
test_case_n(10**6, lambda i: 10**6 - i, 10**6)
