#include "board.cpp"
#include "player.cpp"
#include "roll.cpp"
#include <bits/stdc++.h>
using namespace std;

class playgame {

  private:
    bool rollTheDice(player *p, board *ludo) {

        string rollRequest = "";
        cout << "----------------" << p->get_name()
             << "'s  trun :[ press 'r' to roll the dice (max attempt 3 ) "
                "]----------------\n";
        int at = 0;

        for (int i = 0; i < 3; i++) {
            if (i)
                cout << "!! try again !!\n";
            cout << "input:";
            cin >> rollRequest;
            if (rollRequest == "r") {
                at = 1;
                break;
            }
        }
        if (!at) {
            cout << "finalPosition :" << p->get_pos() << endl;
            return false;
        }

        int move = roll::rollDice();
        cout << "Curr Position :" << p->get_pos() << endl;
        cout << "Dice :" << move << endl;
        int newPosition = move + p->get_pos();
        int finalPosition = ludo->NewPositionJumpOrDrop(newPosition);
        if (newPosition <= 100)
            p->set_pos(finalPosition);

        if (newPosition > 100)
            cout << "\n\nOUT OF BOARD TRY NEXT TIME :(\n";
        else if (newPosition > finalPosition) {
            cout << "\n\nOhh No! got a snake bite at :" << newPosition << endl;
        } else if (newPosition < finalPosition) {
            cout << "\n\nLucky you!! got a ladder at :" << newPosition << endl;
        }
        cout << "\nfinalPosition :" << p->get_pos() << endl;

        if (p->get_pos() == 100) {
            p->set_won();
            return p->get_won();
        }
        return false;
    }

  public:
    playgame() {}

    void show_winner(bool gameFinished, string s) {
        if (!gameFinished)
            return;

        cout << "\n\n\n-------------------------\n\nHURREYY !!" << s
             << " is the Winner\n\n-------------------------\n";
    }

    void startgame(string &s1, string &s2, vector<vector<int>> &s,
                   vector<vector<int>> &l) {
        int t = 0;
        bool gameFinished = false;
        board *ludo = new board();
        ludo->intialise_board(s, l);
        player *p1 = new player(s1);
        player *p2 = new player(s2);
        // playgame *ludoGame = new playgame();

        while (!gameFinished) {

            if (t % 2 == 0) {
                gameFinished = rollTheDice(p1, ludo);
                show_winner(gameFinished, p1->get_name());
            } else {
                gameFinished = rollTheDice(p2, ludo);
                show_winner(gameFinished, p2->get_name());
            }
            t++;
        }
    }
};
