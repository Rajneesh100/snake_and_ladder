#include <bits/stdc++.h>
using namespace std;

class roll {
  public:
    static int rollDice() {
        // Set up random number generator
        random_device rd;                         // Seed
        mt19937 gen(rd());                        // Random number generator
        uniform_int_distribution<> distrib(1, 6); // Range: 1 to 6
        return distrib(gen);
    }
};