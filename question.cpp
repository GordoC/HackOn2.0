#include <iostream>

using namespace std;

class Question {
  private:
  	string question;
  	string mood;
  	bool goodAnswer;
      
  public:
  	void setQuestion(string text){
      question = text;
    }
  	string getQuestion() {
      return question;
    }
  
  	void setMood(string text) {
      mood = text;
    }
  	string getMood() {
      return mood;
    }
  
  	void setGoodAnswer(bool ans) {
      goodAnswer = ans;
    }
  	bool getGoodAnswer() {
      return goodAnswer;
    }
};