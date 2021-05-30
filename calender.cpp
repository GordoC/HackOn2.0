#include <iostream>
#include <map>
#include <vector>
#include "dayContents.cpp"

using namespace std;

class Calender {
  private:
    map<int, DayContents> days; //<day, DayContents>, day in mmdd

  public:
    // adds a day + DayContents pair to days
    void addDayContents(int day, DayContents dc) {
      days.insert(pair(day, dc));
    }

    // deletes a day from days (including the DayContents that day holds)
    void deleteDay(int day) {
      days.erase(day);
    }

    // returns a DayContent from given day
    DayContents getDayContents(int day) {
      return days.find(day)->second;
    }

    // implement! if day has no DayContent, -1 divisor but dont look 1 day back to make up for it
    // returns the average minutes of sleep on past 7 days
    int avgSleep(int day) {
        for (int i = 0; i < 7; i++) {
          
        }
    }

    // implement! if day has no DayContent, -1 divisor but dont look 1 day back to make up for it
    // returns the average quality sleep on past 7 days
    int avgQuality(int day) {

    }

    // implement! if day has no DayContent, -1 divisor but dont look 1 day back to make up for it
    // returns the average mood on past 7 days
    int avgMood(int day) {

    }
};