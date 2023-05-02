#include <iostream>
using namespace std;

int main() {
  string favGames[100];
  int index = 0;

  while(true) {
    cout << "what would you like to do?\n";
    cout << "Type 'bulkAdd' to add games.\n";
    cout << "Type 'show' to show your list of favorite games.\n";
    cout << "Type 'quit' to quit.\n";
    cout << "Type 'edit' to edit last entry.\n";
    cout << "Type 'find' to change any entry.\n";

    string input;
    cin >> input;

    if(input == "bulkAdd"){
      while(true){
      cout << "What game would you like to add?\n";
      cout << "Or type 'back' to go back to main menu.\n";
      cin >> input;

        if(input == "back"){
        break;
        }

          else{
            favGames[index] = input;
            index++;
          }
      }//end while
    }

    if(input == "quit"){
      cout << "Thanks for playing!\n";
      break;
      } 
    
    if(input == "show"){
      cout << "Here is your list of games:\n";
      for(int i = 0; i < index; i++){
        cout << i + 1 << ". " << favGames[i] << "\n";
      }
    }

    if(input == "edit") {
      cout << "Please re-enter last game name.\n";
      cin >> input;
      favGames[index - 1] = input;
    }

    if(input == "find"){
      cout << "What game would you like to edit?\n";
      cin >> input;
      for(int i = 0; i < index; i++) {
        if(favGames[i] == input) {
          cout << "Found It!\n";
          cout << "What would you like to change this to?\n";
          cin >> input;
          favGames[i] = input;
        }
      }
    }
  }  //end of while
}