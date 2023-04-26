#include <iostream>
#include <fstream>
using namespace std;

//global array
string favGames[100];
int index = 0;

//global variables
string input;

/*
  for your assignmen:
    create a favgames program.
    use functions
    add
    show
    remove
    edit
    load previous list from file
    save list to file
*/

void add() {
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

void show() {
  for(int i = 0; i < index; i++) {
    //skip removed names
    if(favGames[i] == ""){
      continue;
    }
    cout << favGames[i] << "\n";
  }
}

void remove(){
  cout << "What name would you like to remove?\n";
  string input;
  getline(cin, input);

  //look through the names for the name they typed
  for(int i = 0; i < index; i++) {
    if(favGames[i] == input) {
      cout << "I have found it! I am removing the name.\n";
      favGames[i] = "";
    }
  }
}

void edit(){
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

void load() {
  //try to open save file
  string line;
  ifstream gamesList("games.txt");

  if(gamesList.is_open()) {
    while(getline(gamesList, line)){
      favGames[index++] = line;
    }
  }
  else {
    cout << "File couldn't be loaded.\n";
  }
  // add each line from the file to the array
  // close the file
}

void save() {
  // open the file
  ofstream gamesList;
  gamesList.open("games.txt");
  for(int i = 0; i < index; i++) {
    gamesList << favGames[i] << "\n";
  }
  gamesList.close();
  // use a for loop to write all of the array lines to the file.
  // file << favGames[i] << "\n";
  //close the file
}

void addList() {
  cout << "What would you like to add?\n";
  cout << "Type 'back' to exit add mode.\n";
  while(true) {
    cin >> input;
    if(input == "back") {
      break;
    }
    favGames[index++] = input;
  }
  save();
}

void quit(){
  cout << "All done.\n";
}

int main() {
  load();
    while(true){
    cout << "What would you like to do?\n";
    cout << "Type 'add' to add games.\n";
    cout << "Type 'show' to show your list of favorite games.\n";
    cout << "Type 'remove' to remove any entry.\n";
    cout << "Type 'edit' to change one of your entries.\n";
    cout << "Type 'save' to save a .txt file.\n";
    cout << "Type 'addList' to load add to .txt file.\n";
    cout << "Type 'quit' to quit.\n";

    cin >> input;
  
    if(input == "add"){
      add();
    }

    if(input == "show"){
      show();
    }

    if(input == "remove"){
      remove();
    }

    if(input == "edit"){
      edit();
    }

    // if(input == "load"){
    //   load();
    // }

    if(input == "save"){
      save();
    }

    if(input == "addList"){
      addList();
    }

    if(input == "quit") {
      quit();
      break;
    }
  }//endwhile
}