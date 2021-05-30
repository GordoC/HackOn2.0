#pragma once
#include <iostream>

using namespace std;

class JournalEntry {
	private:
  		string text;
  
  	public: 
      JournalEntry(string aText) {
        text = aText;
      }

      JournalEntry() {
        text = "";
      }

  		void setText(string input) {
          text = input;
        }
  		string getText() {
          return text;
        }
};

