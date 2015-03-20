from random import randrange

def case(definition):
  n = len(definition)

  def format_list(a_list):
    return '{0} '.format(len(a_list)) + ' '.join(map(str, a_list))

  return '{0}\n'.format(str(n)) + '\n'.join(map(format_list, definition))

def random_list(length):
  return [randrange(-10**6, 10**6) for n in xrange(length)]

def cases():
  return [
    case([
      [8],
      [6, 8],
      [1, 3, 9],
    ]),

    case([
      [3],
      [2],
      [1],
    ]),

    case([
      [1, 2, 3, 4, 5, 6]
    ]),

    case([
      [1, 4, 7, 10],
      [2, 5, 8, 11],
      [3, 6, 9, 12],
    ]),

    case([
      [k * 100 + n for k in xrange(100)]
      for n in xrange(100)
    ]),

    case([
      [k for k in xrange(10**5)]
    ]),

    case([
      [k] for k in xrange(10**5)
    ]),

    case([
      sorted(random_list(length=10**5))
      for n in xrange(10)
    ]),

    case([
      sorted(random_list(length=30))
      for n in xrange(3*10**4)
    ]),
  ]
