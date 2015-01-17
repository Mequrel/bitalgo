from random import randrange
from random import choice
from collections import namedtuple
from itertools import chain

case_number = 1

def RESIZE(n, val):
  return "RESIZE {0} {1}".format(n, val)

def GET(i):
  return "GET {0}".format(i)

def SET(i, val):
  return "SET {0} {1}".format(i, val)

def PUSH(val):
  return "PUSH_BACK {0}".format(val)

def POP():
  return "POP_BACK"

def flatten(list_of_lists):
    return list(chain.from_iterable(list_of_lists))

def test_case(ops):
  global case_number

  with open("testcases/" + str(case_number) + ".in", "w") as output:
    output.write("{0}\n".format(len(ops)))
    for op in ops:
      output.write("{0}\n".format(op))

  case_number += 1

def random_value():
  return randrange(1, 10**6)



test_case([
  PUSH(2),
  GET(0),
  GET(1),
  RESIZE(n=5, val=1),
  GET(4),
  SET(i=4, val=8),
  GET(4),
  POP(),
  GET(4)
])

test_case([
  GET(0),
  GET(5),
  RESIZE(n=5, val=7),
  GET(0),
  GET(5),
  RESIZE(n=7, val=9),
  GET(0),
  GET(5)
])

test_case([
  GET(0),
  PUSH(8),
  GET(0),
  POP(),
  GET(0)
])

test_case(
  [RESIZE(n=10, val=100)] +
  [SET(i=0, val=i) for i in xrange(10)] +
  [GET(i) for i in xrange(10)]
)

test_case(
  [RESIZE(n=10**6, val=0)] +
  [SET(i, val=i) for i in xrange(4 * 10**5)] +
  [GET(i) for i in xrange(4 * 10**5)]
)

test_case(
  [PUSH(i) for i in xrange(5 * 10**5)] +
  [GET(i) for i in xrange(5 * 10**5)]
)

test_case(
  [RESIZE(n=3*10**5, val=0)] + 
  flatten([[GET(i), SET(i, random_value()), GET(i)] for i in xrange(3 * 10**5)]) + 
  [GET(3*10**5)]
)

test_case(
  [PUSH(i) for i in xrange(1024)] +
  flatten([[GET(1023), POP(), POP(), PUSH(random_value()), PUSH(random_value())] for i in xrange(2*10**5 - 2000)])
)