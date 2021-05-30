#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "messageManager.cpp"
#include "calender.cpp"
//#include "sleepTracker.cpp"
//#include "moodTracker.cpp"
#include "reward.cpp"
#include "dayContents.cpp"
#include "journalEntry.cpp"

using namespace std;

MessageManager mm;
Calender calender;
int day;
Sleep sleep;
Mood mood;
JournalEntry je;

// checks if given mood is a mood we can deal with currently
bool moodValid(string mood) {
  return mood == "happy" || mood == "sad" || mood == "angry";
}

// displays what they can do if they input a certain char
void displayMenu() {
  cout << "a - add another day" << endl;
  cout << "d - delete a day" << endl;
  cout << "e - edit a day" << endl;
  cout << "s - check average amount of sleep for the past 7 days" << endl;
  cout << "c - check average quality of sleep for the past 7 days" << endl;
  cout << "m - checks the average mood you were feeling for the past 7 days" << endl;
  cout << "q - quit" << endl;
}

// asks for what mood they feel today, reply based on said mood, and creates mood object
void whatMoodQuestion(string text) {
    string feeling;
    cout << "How did you feel" << text << " Happy, sad, or angry?" << endl;
    cin >> feeling;
    transform(feeling.begin(), feeling.end(), feeling.begin(),
      [](unsigned char c){ return tolower(c); });
    if (moodValid(feeling)) {
      mood = Mood(feeling);
      mm.getMessage(feeling);
    } else {
       cout << "Sorry, you inputted a mood we cannot accept, try again please." << endl;
       whatMoodQuestion(text);
    }
}

// implement cout << "" << endl;
// reply based on how long sleep inputed
void minSleepReply(int minSleep) {
  if (minSleep < 120) {
    // very bad
  } else if (minSleep < 300) {
    // too less
  } else if (minSleep < 480) {
    // avg
  } else if (minSleep > 720) {
    // too much
  }
}


// implement cout << "" << endl;
// reply based on quality inputed
void qualitySleepReply(int quality) {
  if (quality > 7) {
    // good
  } else {
    // try to have btter sleep enviroment
  }
}

// asks for how much sleep today and creates Sleep object
void howMuchSleep(string text) {
  int minSleep;
  int quality;
  cout << "How many minutes did you sleep" << text << endl;
  cin >> minSleep;
  minSleepReply(minSleep);
  cout << "On a scale of 1 to 10, 1 being really bad, how was the quality of your sleep?" << endl;
  cin >> quality;
  qualitySleepReply(quality);
  sleep = Sleep(minSleep, quality);
}

// asks for a description of today and creates JournalEntry object
void howDayWent(string text) {
  string entry;
  cout << "What did you do" << text << " This journal entry will be kept for future you! So please try your best. You got this!" << endl;
  getline(cin, entry);
  je = JournalEntry(entry);
  cout << "That seems like an intresting day!" << endl;
}

// asks what day is it today
void whatDayIsIt(string text) {
  cout << "What day is it" << text << " Please input in the format mmdd" << endl;
  cin >> day;
}

// implement! try to find if there is JSON equivalent in C++
// loads calender from saved data
void loadCalender() {

}

void addDay(string text) {
  whatDayIsIt(text); 
  whatMoodQuestion(text); 
  howDayWent(text);
  howMuchSleep(text);
}

// initializes all the objects by invoking the methods
void init() {
  loadCalender();
  addDay(" today?");
  DayContents dc = DayContents(sleep, mood, je);
  calender.addDayContents(day, dc);
  mm.checkUpQuestions(mood.getMood());
}

// delete a day in calender
void delDay(int aDay) {
  char ans;
  cout << "Are you sure you want to delete what is on " << aDay << "(mmdd)? This cannot be undone" << endl;
  cout << "y - yes" << endl;
  cout << "n - no" << endl;
  cin >> ans;
  if (ans == 'y') {
    calender.deleteDay(aDay);
  } 
}

// edit a day in calender, stays on editing that day until user input 'b'
void editDay(int aDay) {
  char command;
  DayContents dc = calender.getDayContents(aDay);
  cout << "What would you like to edit about that day?" << endl;
  cout << "s - sleep" << endl;
  cout << "m - mood" << endl;
  cout << "j - journal entry" << endl;
  cout << "b - go back" << endl;
  cin >> command;
  if (command == 's') {
    howMuchSleep("?");
    dc.setSleep(sleep);
  } else if (command == 'm') {
    whatMoodQuestion("?");
    dc.setMood(mood);
  } else if (command == 'j') {
    howDayWent("?");
    dc.setJournalEntry(je);
  } else if (command == 'b') {
    // do nothing so goes back to run()
  } else {
    editDay(aDay);
  }
}

// returns the correct method for given command
void processCommand(char c) {
  int dayChosen;
  if (c == 'a') {
    addDay("?");
  } else if (c == 'd') {
    cout << "What day would you like to delete?" << endl;
    cin >> dayChosen;
    delDay(dayChosen);
  } else if (c == 'e') {
    cout << "What day would you like to edit?" << endl;
    cin >> dayChosen;
    editDay(dayChosen);
  } else if (c == 's') {
    calender.avgSleep(day);
  } else if (c == 'c') {
    calender.avgQuality(day);
  } else if (c == 'm') {
    calender.avgMood(day);
  }
}

// implement save stuff, try to find equivalent to JSON!
// asks user if they would like to save everything in the calender before exiting
bool saveOrNot() {
  char command;
  cout << "Would you like to save everything in your calender?" << endl;
  cout << "y - yes" << endl;
  cout << "n - no" << endl;
  cin >> command;
  command = tolower(command);
  if (command == 'y') {
    // save
  } 
  return false;
}

// collects users input, will stop if user input 'q', basically the console interface
void run() {
  bool running = true;
  char command;

  while(running) {
    displayMenu();
    cin >> command;
    command = tolower(command);

    if (command == 'q') {
      running = saveOrNot();
    } else {
      processCommand(command);
    }
  }

  cout << "Goodbye, see you soon!";
}

// main, starts the application by invoking init() and run() method
int main() {
  cout << "Heyo my favourite person!" << endl;
  init();
  run();
  return 0;
}

