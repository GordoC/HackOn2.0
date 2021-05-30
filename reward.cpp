#include <iostream>

using namespace std;

class Reward {
  private:
    int points;

  public:
    Reward(int x) {
      points = x;
    }

    Reward() {
      points = 0;
    
    }
    int getPoints() {
      return points;
    }

    void setPoints(int x) {
      points = x;
    }

    // adds points
    void addPoints(int x) {
      points += x;
    }

    // "uses" points (mainly to purchase smt) but if not enough points will tell user and not deduct points
    void delPoints(int x) {
      if (points - x < 0) {
        cout << "Cannot purchase, insufficient points" << endl;
      } else {
        points -= x;
      }
    }
};