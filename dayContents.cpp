#pragma once
#include <iostream>
#include "mood.cpp"
#include "sleep.cpp"
#include "journalEntry.cpp"

using namespace std;

class DayContents {
  private:
    Sleep sleepObj;
    Mood moodObj;
    JournalEntry jeObj;
    bool null;

  public:
    DayContents(Sleep aSleep, Mood aMood, JournalEntry aJe) {
      sleepObj = aSleep;
      moodObj = aMood;
      jeObj = aJe;
      null = false;
    }

    DayContents() {
      null = true;
    }

    void setSleep(Sleep aSleep) {
      sleepObj = aSleep;
    }

    Sleep getSleep() {
      return sleepObj;
    }

    void setMood(Mood aMood) {
      moodObj = aMood;
    }

    Mood getMood() {
      return moodObj;
    }

    void setJournalEntry(JournalEntry aJe) {
      jeObj = aJe;
    }

    JournalEntry getJournalEntry() {
      return jeObj;
    }

    bool getNull() {
      return null;
    }
};