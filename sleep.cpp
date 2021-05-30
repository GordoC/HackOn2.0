class Sleep {
  private:
  	int minSleep;
  	int quality;
  
  public:
    Sleep(int aMinSleep, int aQuality) {
        minSleep = aMinSleep;
        quality = aQuality;
    }

    Sleep() {
      minSleep = 0;
      quality = 0;
    }

  	void setMinSleep(int x) {
     	minSleep = x; 
    }
  
  	int getMinSleep() {
     	return minSleep; 
    }
  
  	void setQuality(int x) {
     	quality = x; 
    }
  
  	int getQuality() {
     	return quality; 
    }

    // compares two Sleep objects and return true or false depending if they are the same
    bool compare(Sleep sleep) {
        return minSleep == sleep.getMinSleep() || quality == sleep.getQuality();
    }
};

