#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "question.cpp"
#include "message.cpp"

using namespace std;

class MessageManager {
  private:
    map<string, vector<Message>> messages; 
    map<string, vector<Question>> questions; 

  public:
    MessageManager() {
      messages.insert({"happy", initHappyMessages()});
      messages.insert({"sad", initSadMessages()});
      messages.insert({"angry", initAngryMessages()});
      questions.insert({"happy", initHappyQuestions()});
      questions.insert({"sad", initSadQuestions()});
      questions.insert({"angry", initAngryQuestions()});
    }

    void getMessage(string mood) {
      int i = rand() % 5;
      vector<Message> msg = messages.find(mood)->second;
      cout << msg[i].getMessage() << endl;
    }

    void getQuestion(string mood) {
      int i = rand() % 5;
      string input;
      vector<Question> quest = questions.find(mood)->second;
      cout << quest[i].getQuestion() << endl;
      cin.ignore(1000,'\n');
      getline(cin, input);
      cout << "That's really intresting to hear! I hope things will always get better for you. Do you have any other plans for today?" << endl;
    }

    void checkUpQuestion(string mood) {
      getQuestion(mood);
    }

    vector<Message> initHappyMessages() {
      vector<Message> mHappy =
      {
        Message("I'm so glad for you!"),
        Message("More to come!"),
        Message("I'm so proud of you!"),
        Message("Big thumbs up!"),
        Message("We love your company!")
      };
      return mHappy;
    }

    vector<Message> initSadMessages() {
      vector<Message> mSad =
      {
        Message("There’s always light after the storm!"),
        Message("Do a handstand! Sometimes we just need to turn that frown upside down!"),
        Message("Off days happen! Tomorrow will be a better one."),
        Message("Take a deeeeeeep breath."),
        Message("You got this!")
      };
      return mSad;
    }

    vector<Message> initAngryMessages() {
      vector<Message> mAngry =
      {
        Message("Take a deep breath, and think about that makes you happy!"),
        Message("Take a walk outside and enjoy the beautiful weather!"),
        Message("There is always a better day to look forward to.  Maybe tomorrow will be the day!"),
        Message("Take a nap! Try to forget anything that could have made you upset today."),
        Message("Try doing something else! Refreshing your mind can help your situation.")
      };
      return mAngry;
    }

    vector<Question> initHappyQuestions() {
      vector<Question> qHappy =
      {
        Question("What in your life do you feel grateful and thankful for?"),
        Question("Have you tried doing something new today?"),
        Question("Can you think of ways to share your feelings of happiness to others?"),
        Question("Are there things you can do tomorrow to keep maintain the good mood from today?"),
        Question("Can you think of anything that can make you even happier than you are now?")
      };
      return qHappy;
    }

    vector<Question> initSadQuestions() {
      vector<Question> qSad =
      {
        Question("Think of the things that can keep you from feeling down.  Everyone has something that can make them happy, can you think of yours?"),
        Question("Don't feel down.  Think about everything you have accomplished in your life.  How far have you come?"),
        Question("Focus on the positive effects of the things you are doing.  How can they bring happiness?"),
        Question("Find someone to talk to! What similar situations could they be facing?"),
        Question("Think about how your day went.  What small things from today can you appreciate?")
      };
      return qSad;
    }

    vector<Question> initAngryQuestions() {
      vector<Question> qAngry =
      {
        Question("Everyone can go through a tough day.  Have you tried what you can do to not experience the same situation?"),
        Question("Seeing the calm skies can help reduce the stress built up in that day.  Have you tried looking outside to get some fresh air?"),
        Question("What's something that you can do to let out that anger?"),
        Question("Being angry is normal so don't worry about it. Try taking 10 deep breaths and type done when you're finished. Did that help?"),
        Question("Try understanding your anger, why are you angry in the first place?")
      };
      return qAngry;
    }
};