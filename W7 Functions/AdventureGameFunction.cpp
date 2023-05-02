#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int health = 30;
int totalTreasure = 0;

void story(){
  cout << "One day after scrolling on tiktok for hours,\n";
  cout << "you decide you want to do something productive.\n";
}

bool askYN(string question = "Would you like to go on an adventure? "){
  while(true){
    cout << question << "(y/n)\n";
    char input;
    cin >> input;

    if(input == 'y'){
      return true;
    }

    else if(input == 'n'){
      return false;
    }
  } //end of while
}

int rollDie(int sides = 6){
  return rand() % sides;
}

void ending(){
  cout << "You return home with " << health << " health and " << totalTreasure << " treasure.\n";
}

void adventure(){
  rollDie(); //block
  rollDie(); //attack
  if(rollDie() >= rollDie()){
    cout << "Your block was successful!\n";
    totalTreasure += 15;
  }
  else{
    health -= rollDie();
    cout << "You didn't block successfully.\n";
  }
    cout << "Your health is at " << health << " and you have " << totalTreasure << " treasure.\n";
}

int main() {
  srand(time(0));
  
  story();

  do{
    if (askYN()) {
      cout << "Let the adventure begin!\n";
    }
    else {
      ending();
      break;
    }
      
    adventure();
  } while (health > 0);

    if (health < 0){
      cout << "You have died.\n";
    }
}