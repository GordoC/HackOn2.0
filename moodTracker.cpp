#include <iostream>
#include <vector>
#include "mood.cpp"

using namespace std;

class MoodTracker {
  private:
  	string moodOfWeek;
  	vector<Mood> moodList;
  
  public:
  	void setMoodOfWeek(string mood) {
     	moodOfWeek = mood;
    }
  
  	string getMoodOfWeek() {
     	return moodOfWeek; 
    }
  
  	void addMood(Mood mood) {
     	moodList.push_back(mood);
    }
  
  	int getSize() {
      	return moodList.size();
    }
  
  	void deleteMood(Mood mood) {
     	 Mood moodit;
     	 for (auto it = moodList.begin(); it != moodList.end(); ++it) {
          moodit = *it;
          if(moodit.compare(mood)) {
            moodList.erase(it);
          }
        }
    }
  
  	Mood findMoodIndex(Mood mood) {
     	Mood moodit;
     	 for (auto it = moodList.begin(); it != moodList.end(); ++it) {
          moodit = *it;
          if(moodit.compare(mood)) {
            return moodit;
          }
        }
        Mood moodNull;
        return moodNull;
    }
};