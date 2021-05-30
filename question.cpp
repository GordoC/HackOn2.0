#pragma once
#include <iostream>

using namespace std;

class Question {
  private:
  	string question;
  	bool goodAnswer;
      
  public:
    Question(string text) {
      question = text;
    }

  	void setQuestion(string text){
      question = text;
    }
  	string getQuestion() {
      return question;
    }
  
  	void setGoodAnswer(bool ans) {
      goodAnswer = ans;
    }
  	bool getGoodAnswer() {
      return goodAnswer;
    }
};