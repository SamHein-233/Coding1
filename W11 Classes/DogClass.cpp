#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
  Your assignment is to create a new class of your own design
  with at least two data members
  a constructor that will randomly populate the data
  or allow for customization (for example: robot("artoo", 5))
  a status() member function
  and at least one other function

  also create UML map for the class either on paper or digitally.
*/

//global variables
string dogToys[5];

class dog {
public:
  string name;
  int energy;
  int toy;

  dog() {
    cout << "A new dog came to the shelter today!\n";
    name = "Dog";
    energy = 10;
  }

  void status() {
    cout << "[" << name << ": " << energy << "]\n";
  }

  dog(string givenName, int givenEnergy) {
    cout << "Give your dog a name and toy.\n";
    name = givenName;
    energy = givenEnergy;
    toy = rand() % 5;
    status();
  }
  
  void pickToy(){
    cout << "Your dog picked " << dogToys[toy] << ".\n";
  }
};

int main() {
  srand(time(0));
  
  dogToys[0] = "Tennis Ball";
  dogToys[1] = "Kong Ball";
  dogToys[2] = "Dog Bone";
  dogToys[3] = "Stuffed Animal";
  dogToys[4] = "Rope";

  dog bowser;
  bowser.status();
  bowser.pickToy();

  dog drake("Drake", 4);
  drake.pickToy();
}