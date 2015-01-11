from random import randrange
from random import choice
from collections import namedtuple
from itertools import chain

case_number = 0

def PUSH(x):
  return "PUSH {0}".format(x)

POP = "POP"
FRONT = "FRONT"

def flatten(list_of_lists):
    return list(chain.from_iterable(list_of_lists))

def test_case(k, ops):
  global case_number

  with open("testcases/" + str(case_number) + ".in", "w") as output:
    output.write("{0} {1}\n".format(k, len(ops)))
    for op in ops:
      output.write("{0}\n".format(op))

  case_number += 1

def random_push():
  return PUSH(randrange(1, 10**6))

def random_op():
  return choice([FRONT, POP, random_push()])

test_case(k = 3, ops = [FRONT, PUSH(4), PUSH(3), PUSH(9), PUSH(8), FRONT, POP, POP, FRONT, POP, POP])
test_case(k = 1, ops = [FRONT, PUSH(10**6), FRONT, PUSH(10**5), FRONT, POP, FRONT, POP, FRONT])
test_case(k = 10, ops = [PUSH(i) for i in xrange(1, 10+1)] + flatten([[PUSH(i), PUSH(i+1), FRONT, POP] for i in xrange(11, 20)]))
test_case(k = 100, ops = [PUSH(i) for i in xrange(1, 10+1)] + flatten([[FRONT, POP] for i in xrange(11, 20)]) + [FRONT])
test_case(k = 10**6, ops = [random_op() for i in xrange(0, 10**6)])
test_case(k = 10, ops = [random_op() for i in xrange(0, 10**6)])
test_case(k = 10**5, ops = [random_push() for i in xrange(0, 10**5)] + flatten([[FRONT, POP, random_push()] for i in xrange(0, 3 * 10**5)]))