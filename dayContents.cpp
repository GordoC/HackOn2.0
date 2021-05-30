#include <iostream>
#include "mood.cpp"
#include "sleep.cpp"
#include "journalEntry.cpp"

using namespace std;

class DayContents {
  private:
    Sleep sleep;
    Mood mood;
    JournalEntry je;

  public:
    DayContents(Sleep aSleep, Mood aMood, JournalEntry aJe) {
      sleep = aSleep;
      mood = aMood;
      je = aJe;
    }

    void setSleep(Sleep aSleep) {
      sleep = aSleep;
    }

    Sleep getSleep() {
      return sleep;
    }

    void setMood(Mood aMood) {
      mood = aMood;
    }

    Mood getMood() {
      return mood;
    }

    void setJournalEntry(JournalEntry aJe) {
      je = aJe;
    }

    JournalEntry getJournalEntry() {
      return je;
    }
};