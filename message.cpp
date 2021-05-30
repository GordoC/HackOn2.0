#pragma once
#include <iostream>

using namespace std;

class Message {
  private:
  	string message;
  
  public:
    Message(string aMessage) {
      message = aMessage;
    }

    Message() {
      message = "";
    }

  	void setMessage(string text) {
     	message = text; 
    }
  
  	string getMessage() {
     	return message; 
    }
 	
};

