#include <bits/stdc++.h>
using namespace std;
class player {
  private:
    string name;
    int pos;
    bool won;

  public:
    player(string &name, int pos = 0) {
        this->name = name;
        this->pos = pos;
        this->won = false;
    }
    string get_name() { return this->name; }
    int get_pos() { return this->pos; }
    void set_won() { this->won = true; }
    bool get_won() { return this->won; }
    int set_pos(int &val) {
        this->pos = val;
        return this->pos;
    }
};