#include <iostream>

using namespace std;

class Mood {
  private:
  	string mood;
  	string colour;
  
  public:
    Mood(string aMood) {
        mood = aMood;
        colour = whatColour(aMood);
    }

    Mood() {
      mood = "";
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
  		mood = text;
    }

  	string getMood(){
      return mood;
    }
  
  	void setColour(string text){
  		colour = text;
    }
  	string getColour(){
      return colour;
    }
        
    // compares two Mood objects and return true or false depending if they are the same
    bool compare(Mood aMood) {
        return mood == aMood.getMood() || colour == aMood.getColour() ; 
    }
};