/**

  Zadanie: Scalanie zbiorów.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie pokazowe z użyciem biblioteki Boost.

  Złożoność rozwiązania: O(mn lg* mn)

**/

#include <boost/pending/disjoint_sets.hpp>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> load_board() {
  vector<vector<int>> board;

  int height, width;
  scanf("%d %d", &height, &width);


  board.resize(height);
  for(int i=0; i<height; ++i) {
    board[i].resize(width);
    for(int j=0; j<width; ++j) {
      scanf("%d", &board[i][j]);
      board[i][j]--;
    }
  }

  return board;
}

vector<pair<int, int>> get_moves(const vector<vector<int>>& board) {
  vector<pair<int, int>> moves;
  moves.resize(board.size() * board[0].size());

  for(int i=0; i<board.size(); ++i) {
    for(int j=0; j<board[i].size(); ++j) {
      int ordinal = board[i][j];
      moves[ordinal] = {i, j};
    }
  }

  return moves;
}

int to_ordinal(const pair<int, int>& board_place, const vector<vector<int>>& board) {
  int width = board[0].size();
  return get<0>(board_place) * width + get<1>(board_place);
}

vector<int> all_connected_tiles(const pair<int, int>& board_place, 
                                const vector<vector<int>>& board,
                                int current_move) {
  int height = board.size();
  int width = board[0].size();

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  vector<int> connected_tiles;

  for(int i=0; i<4; ++i) {
    int x = get<0>(board_place) + dx[i];
    int y = get<1>(board_place) + dy[i];

    if(x >= 0 && y >= 0 && x < height && y < width
       && board[x][y] < current_move) {
      connected_tiles.push_back(to_ordinal({x, y}, board));
    }
  }

  return connected_tiles;
}


int main() {
  vector<vector<int>> board = load_board();
  vector<pair<int, int>> moves = get_moves(board);

  int all_elements = moves.size();
  
  vector<int> ranks(all_elements);
  vector<int> parents(all_elements);

  boost::disjoint_sets<int*, int*> sets(&ranks[0], &parents[0]);

  int islands = 0;
  for(int i=0; i<all_elements; ++i) {
    const auto& move = moves[i];
    int current_ordinal = to_ordinal(move, board);

    sets.make_set(current_ordinal);

    set<int> different_islands;
    auto connected_tiles = all_connected_tiles(move, board, i+1);

    for(int tile_ordinal : connected_tiles) {
      int island_ordinal = sets.find_set(tile_ordinal);
      different_islands.insert(island_ordinal);
    }

    // it's important to union sets in a separate loops
    // union_set operation may change the set representative!

    for(int tile_ordinal : connected_tiles) {
      sets.union_set(tile_ordinal, current_ordinal);
    }
    
    islands++;
    islands -= different_islands.size();

    printf("%d ", islands);
  }

  return 0;
}