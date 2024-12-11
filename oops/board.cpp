#include <bits/stdc++.h>
using namespace std;
class board {
  private:
    int st;
    int end;
    map<int, int> m;

  public:
    board() {
        st = 1;
        end = 100;
        m.clear();
    }
    void intialise_board(vector<vector<int>> &s, vector<vector<int>> &l) {
        for (auto i : s)
            m[i[0]] = i[1];
        for (auto i : l)
            m[i[0]] = i[1];
        return;
    }
    int NewPositionJumpOrDrop(int val) {
        if (m.find(val) != m.end()) {
            return m[val];
        }
        return val;
    }
};