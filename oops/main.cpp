#include "start_game.cpp"
using namespace std;

int main() {
    string p1 = "ram";
    string p2 = "shyam";
    vector<vector<int>> s = {{34, 12}, {45, 4}, {67, 13}, {89, 56}, {99, 5}};
    vector<vector<int>> l = {{2, 7},  {78, 92}, {11, 93},
                             {3, 16}, {29, 87}, {43, 79}};

    playgame *ludoGame = new playgame();

    ludoGame->startgame(p1, p2, s, l);
}