from random import randrange
from collections import namedtuple

case_number = 1

case = namedtuple('case', ['n', 'k', 'i'])

def choose(n, k):
  result = 1
  for i in xrange(0, k):
    result *= (n - i)
    result /= (i + 1)
  return result

def test_case(cases):
  global case_number

  with open(str(case_number) + ".in", "w") as output:
    output.write(str(len(cases)))
    output.write("\n")
    for c in cases:
      output.write("{0} {1} {2}\n".format(c.n, c.k, c.i))

  case_number += 1

test_case([case(n=1, k=1, i=1),
           case(n=3, k=2, i=2),
           case(n=5, k=2, i=6)])

test_case([case(n=50, k=1, i=1),
           case(n=50, k=50, i=1)])

test_case([case(n=5, k=3, i=i+1) for i in xrange(0, 10)])
test_case([case(n=50, k=25, i=i) for i in [1, choose(50, 25), choose(50, 25) / 2]])
test_case([case(n=48, k=11, i=randrange(1, choose(48, 11))) for i in xrange(0, 10)])
test_case([case(n=20, k=12, i=randrange(1, choose(20, 12))) for i in xrange(0, 10)])
