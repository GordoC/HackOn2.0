#pragma once
#include <iostream>

using namespace std;

class Mood {
  private:
  	string moodText;
  	string colour;
  
  public:
    Mood(string aMood) {
        moodText = aMood;
        colour = whatColour(aMood);
    }

    Mood() {
      moodText = "";
      colour = "";
    }

    // returns a colour based on the mood given
    string whatColour(string aMood) {
      if (aMood == "happy") {
        return "yellow";
      } else if (aMood == "sad") {
        return "blue";
      } else if (aMood == "angry") {
        return "red";
      } else {
        return "N/A";
      }
    }

  	void setMood(string text){
  		moodText = text;
    }

  	string getMood(){
      return moodText;
    }
  
  	void setColour(string text){
  		colour = text;
    }
  	string getColour(){
      return colour;
    }
        
    // compares two Mood objects and return true or false depending if they are the same
    bool compare(Mood aMood) {
        return moodText == aMood.getMood() || colour == aMood.getColour() ; 
    }
};