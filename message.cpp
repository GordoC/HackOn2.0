#include <iostream>

using namespace std;

class Message {
  private:
  	string message;
  	string mood;
  
  public:
    Message(string aMessage, string aMood) {
      message = aMessage;
      mood = aMood;
    }

  	void setMessage(string text) {
     	message = text; 
    }
  
  	string getMessage() {
     	return message; 
    }

    void setMood(string aMood) {
      mood = aMood;
    }

    string getMood() {
      return mood;
    }
 	
};

