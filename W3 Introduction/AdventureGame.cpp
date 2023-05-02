#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  
  //     seed the random number generator
  // start the loop
  string input;

  string playerName;
  cout << "Hello! Please enter your name!\n";
  cin >> playerName;
  cout << "Hello " << playerName << ", welcome to your Snowy Adventure Game!\n";
  
  int health = 10;
  int attack;
  int block;
  int turns = 0;
  
  do {
    turns += 1;
    block = rand() % 5;
    attack = rand() % 5;

    cout << "Look out! Here comes the Abominable Snowman!\n";
    cout << "He attacks you taking " << attack << " damage!\n";
    cout << "You block " << block << " damage!\n";

    if(block >= attack){
      cout << "Your block was successful!\n";
      cout << "You maintain your health at " << health << ".\n";
    }
      
    else {
      health -= attack;
      cout << "Your block wasn't strong enough!\n"; 
      cout << "You now have " << health << " health.\n";
    }
    
  } while (health > 0 && turns < 4);

  if (health > 0){
    cout << "Congradulations! You won!\n";
  }
  else{
    cout << "You have died.\n";
  }
  // add 1 to turns
  // start the encounter
  // randomly generate numbers for attack (range = 0-4) and block (range = 0-4)
  // if block is greater or equal to attack, successful block
  // otherwise, subtract attack value from health.
  // keep looping while health is greater than zero and fewer than 4 turns have happened

  // if health is greater than 0, congratulate player
  // otherwise, tell the player they're dead.
}