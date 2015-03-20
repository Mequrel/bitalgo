import random

def case(matrix):
  n = len(matrix)

  def format_list(matrix_row):
    return ' '.join(map(str, matrix_row))

  return '{0} {1}\n'.format(len(matrix), len(matrix[0])) + '\n'.join(map(format_list, matrix))

def to_matrix(flat, size):
  return [flat[i:i+size] for i in range(0, len(flat), size)]

def shuffle(a_list):
  random.shuffle(a_list)
  return a_list

def max_list():
  return [k for k in xrange(1, 3*10**5+1)]

def cases():
  return [
    case([
      [1, 9, 2],
      [8, 4, 7],
      [3, 5, 6],
    ]),

    case([
      [2],
      [3],
      [1],
    ]),

    case([
      [1, 2, 3, 4, 5, 6]
    ]),

    case([
      [1,  7,  2,  8],
      [9,  3, 10,  4],
      [5, 11,  6, 12],
    ]),

    case([
      [k * 300 + n + 1 for k in xrange(1000)]
      for n in xrange(300)
    ]),

    case([
      shuffle(max_list())
    ]),

    case(
      shuffle([
        [k] for k in xrange(1, 3*10**5+1)
      ])
    ),

    case(      
      to_matrix(
        shuffle(max_list()),
        100
      )
    ),

    case(      
      to_matrix(
        shuffle(max_list()),
        1000
      )
    ),
  ]

