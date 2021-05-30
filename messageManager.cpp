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
      if (mood == "happy") {

      } else if (mood == "sad") {

      } else if (mood == "angry") {

      } else {

      }
    }

    void getQuestion(string mood) {
      if (mood == "happy") {

      } else if (mood == "sad") {

      } else if (mood == "angry") {

      } else {

      }
    }

    void checkUpQuestions(string mood) {
      getQuestion(mood);
    }

    vector<Message> initHappyMessages() {
      vector<Message> mHappy =
      {
        "blah blah blah",
        "etc"
      };
      return mHappy;
    }

    vector<Message> initSadMessages() {
      vector<Message> mSad =
      {
        
      };
      return mSad;
    }

    vector<Message> initAngryMessages() {
      vector<Message> mAngry =
      {
        
      };
      return mAngry;
    }

    vector<Question> initHappyQuestions() {
      vector<Question> qHappy =
      {
        
      };
      return qHappy;
    }

    vector<Question> initSadQuestions() {
      vector<Question> qSad =
      {
        
      };
      return qSad;
    }

    vector<Question> initAngryQuestions() {
      vector<Question> qAngry =
      {
        
      };
      return qAngry;
    }
};