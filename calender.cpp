#pragma once
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

    // returns the average minutes of sleep on past 7 days
    double avgSleep(int day) {
      int sum = 0;
      int numDC = 7;
        for (int i = day; i >= day - 7; i--) {
          DayContents dc = days.find(i)->second;
          if (dc.getNull() == false) {
            sum += dc.getSleep().getMinSleep();
          } else {
            numDC -= 1;
          }
        }
        if (numDC == 0) {
          return 0;
        } else {
          return (sum/numDC);
        }
    }

    // returns the average quality sleep on past 7 days
    int avgQuality(int day) {
      int sum = 0;
      int numDC = 7;
        for (int i = day; i >= day - 7; i--) {
          DayContents dc = days.find(i)->second;
          if (dc.getNull() == false) {
            sum += dc.getSleep().getQuality();
          } else {
            numDC -= 1;
          }
        }
        if (numDC == 0) {
          return 0;
        } else {
          return (sum/numDC);
        }

    }

    // returns the average mood on past 7 days
    string avgMood(int day) {
      string mood;
      vector<int> count; //{happy, sad, angry}
      int numDC = 7;
      // counts how much each time a specific mood occurs
        for (int i = day; i >= day - 7; i--) {
          DayContents dc = days.find(i)->second;
          if (dc.getNull() == false) {
            mood = dc.getMood().getMood();
            if (mood == "happy") {
              count[0]++;
            } else if (mood == "sad") {
              count[1]++;
            } else if (mood == "angry") {
              count[2]++;
            }
          } else {
            numDC -= 1;
          }
        }
        
        if (numDC == 0) {
          return 0;
        } else {
        // finds the max index in the count vector and returns the appropriate mood based on index
        int max = count[0];
        int index = 0;
          for (int i = 0; i < count.size(); i++) {
            if (max < count[i]) {
              max = count[i];
              index = i;
            }
          }
          if (index == 0) {
            return "happy";
          } else if (index == 1) {
            return "sad";
          } else if (index == 2) {
            return "angry";
          }
        }
    }
};