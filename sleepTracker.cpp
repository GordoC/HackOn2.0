#include <iostream>
#include <vector>
#include "sleep.cpp"

using namespace std;

class SleepTracker {
  private:
  	int qualityAvg;
  	double weekAvg;
  	vector<Sleep> sleepList;
  
  public:
  	void setQualityAvg(int x) {
     	qualityAvg = x; 
    }
  
  	int getQualityAvg() {
     	return qualityAvg; 
    }
  
  	void setWeekAvg(double y) {
     	weekAvg = y; 
    }
  
  	int getWeekAvg() {
     	return weekAvg; 
    }
  
  	void addSleep(Sleep sleep) {
     	sleepList.push_back(sleep);
    }
  
  	int getSize() {
      	return sleepList.size();
    }
  
  	void deleteSleep(Sleep sleep) {
      Sleep sleepit;
     	 for (auto it = sleepList.begin(); it != sleepList.end(); ++it) {
          sleepit = *it;
          if(sleepit.compare(sleep)) {
            sleepList.erase(it);
          }
        }
    }
  
    Sleep findSleepIndex(Sleep sleep) {
      Sleep sleepit;
     	 for (auto it = sleepList.begin(); it != sleepList.end(); ++it) {
          sleepit = *it;
          if(sleepit.compare(sleep)) {
            return sleepit;
          }
        }
        Sleep sleepNull;
        return sleepNull;
    }
};