/**

  Zadanie Q: Sudoku.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe z wykorzystaniem jedynie sprawdzania poprawności rozwiązania po każdym uzupełnieniu pola.
  Złożoność rozwiązania: O(9^F * N), gdzie F to liczba wolnych pól na planszy.

**/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Position {
  int row, column;
  Position(int x, int y) : row(x), column(y) {}
};

bool operator==(const Position& first, const Position& second) {
  return (first.row == second.row) && (first.column == second.column);
}

struct Field {
  int value;
  set<int> possibilites;
};

class Board {
  int kEmptyField;

  Position SectorFirstPoint(Position position) {
    return Position(position.row - position.row % _sector_size, position.column - position.column % _sector_size);
  }

  vector< vector<Position> > _affected_position_cache;

  vector<Position> ComputeAffectedPositions(Position position) {
    vector<Position> result;

    for(int i=0; i<_board_size; ++i) {
      if(i != position.row) result.push_back(Position(position.row, i));
      if(i != position.column) result.push_back(Position(i, position.column));
    }

    Position first_point = SectorFirstPoint(position);
    for(int i=0; i<_sector_size; ++i) {
      for(int j=0; j<_sector_size; ++j) {
        if(i != position.row % _sector_size && j != position.column % _sector_size) {
          result.push_back(Position(first_point.row + i, first_point.column + j));
        }
      }
    }

    return result;
  }

  inline vector<Position> GetAffectedPositions(Position position) {
    return _affected_position_cache[position.row * _board_size + position.column];
  }

  void RemoveFree(Position position, int value) {
    _free.erase(find(_free.begin(), _free.end(), position));

    vector<Position> affected = GetAffectedPositions(position);
    for(int i=0; i<affected.size(); ++i) {
      _board[affected[i].row][affected[i].column].possibilites.erase(value);
    }
  }

  void MakeFree(Position position) {
    _free.push_back(position);

    int old_value = At(position);
    vector<Position> affected = GetAffectedPositions(position);
    for(int i=0; i<affected.size(); ++i) {
      _board[affected[i].row][affected[i].column].possibilites.insert(old_value);
    }
  }

  bool IsTheOnlyOptionToChoose(int value, const set<int>& possible_moves) {
    return false;
    return possible_moves.size() == 1 && *possible_moves.begin() == value;
  }

public:
  Board(int board_size, int sector_size) : _board_size(board_size), _sector_size(sector_size) {
    kEmptyField = 0;
    _board.resize(_board_size);  
  
    for(int i=0; i<_board_size; ++i) {
      _board[i].resize(_board_size);
    }

    for(int i = _board_size * _board_size - 1; i >= 0; --i) {
      _free.push_back(PositionInOrder(i));
    }

    _affected_position_cache.resize(_board_size * _board_size);
    for(int i=0; i<_board_size; ++i) {
      for(int j=0; j<_board_size; ++j) {
        for(int value = 1; value <= _board_size; ++value) {
          _board[i][j].possibilites.insert(value);
        }

        _affected_position_cache[i * board_size + j] = ComputeAffectedPositions(Position(i, j));
      }
    }
  }

  Position PositionInOrder(int rank) {
    int row = rank / _board_size;
    int column = rank % _board_size;
    return Position(row, column);
  }

  int RowSize() {
    return _board_size;
  }

  int AllFieldsNumber() {
    return _board_size * _board_size;
  }

  int At(Position position) {
    return _board[position.row][position.column].value;
  }

  bool IsEmpty(Position position) {
    return _board[position.row][position.column].value == kEmptyField;
  }

  void Place(int value, Position position) {
    if(value == kEmptyField && !IsEmpty(position)) {
      MakeFree(position);
    }
    else if(value != kEmptyField && IsEmpty(position)) {
      RemoveFree(position, value);
    }

    _board[position.row][position.column].value = value; 
  }

  void PlaceEmpty(Position position) {
    Place(kEmptyField, position);
  }

  bool IsValidToPlace(int possible_value, Position position) {
    vector<Position> affected = GetAffectedPositions(position);
    for(int i=0; i<affected.size(); ++i) {
      const Field& field = _board[affected[i].row][affected[i].column];

      if(field.value == possible_value) { 
        return false;
      }

      if(field.value == kEmptyField && IsTheOnlyOptionToChoose(possible_value, field.possibilites)) {
        return false;
      }
    }

    return true;
  }

  Position GetFirstEmpty() {
    Position best = _free[0];
    int min_number_of_possibilities = _board[best.row][best.column].possibilites.size();

    for(int i=1; i<_free.size(); ++i) {
      int current_number_of_possibilities = _board[_free[i].row][_free[i].column].possibilites.size();
      if(current_number_of_possibilities < min_number_of_possibilities) {
        min_number_of_possibilities = current_number_of_possibilities;
        best = _free[i];
      }
    }

    return best;
  }

  bool HasNoEmptyFieldsLeft() {
    return _free.empty();
  }

private:
  vector<vector<Field> > _board;
  vector<Position> _free;
  int _board_size;
  int _sector_size;
};

bool solve_sudoku(Board* board) {
  if(board->HasNoEmptyFieldsLeft()) {
    return true;
  }

  Position position = board->GetFirstEmpty();

  for(int possible_value = 1; possible_value <= board->RowSize(); ++possible_value) {
    if(!board->IsValidToPlace(possible_value, position)) {
      continue;
    }

    board->Place(possible_value, position);
    bool successful = solve_sudoku(board);
    if(successful) {
      return true;
    }
    else {
      board->PlaceEmpty(position);
    }
  }

  return false;
}

int main() {
  const int kBoardSize = 9;
  const int kSectorSize = 3;

  Board* board = new Board(kBoardSize, kSectorSize);
  
  for(int i = 0; i < board->AllFieldsNumber(); ++i) {
    int value;
    scanf("%d", &value);

    Position position = board->PositionInOrder(i);
    if(value == 0) {
      board->PlaceEmpty(position);
    }
    else {
      board->Place(value, position);
    }
  }

  solve_sudoku(board);

  for(int i = 0; i < board->AllFieldsNumber(); ++i) {
    if(i > 0 && i % board->RowSize() == 0) {
      printf("\n");
    }

    printf("%d ", board->At(board->PositionInOrder(i)));
  }

  delete board;
  
  return 0;
}