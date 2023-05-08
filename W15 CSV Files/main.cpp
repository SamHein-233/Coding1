#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class character {
public:
string name;
string catchphrase;
int id;

  character(string n, string givenCatch, int givenID) {
    name = n;
    catchphrase = givenCatch;
    id = givenID;
  }
  character() {
    // does nothing
  }
};

//global array of characters
character characters[100];
int index = 0;

void load() {
  // get the file open
  ifstream file("characters.csv");
  string line;

  if(file.is_open()) {
    character temp;
    
    while(getline(file, line)) {
      // cout << "The first comma is character #" << line.find(",") << ".\n";
      // cout << line << "\n";
      // cout << "Name is " << line.substr(0,line.find(",")) << "\n";

      temp.name = line.substr(0,line.find(","));

      //find the first comma
      int comma = line.find(",");
      //save the name
      string name = line.substr(0, comma);
      //erase the name and the comma
      line.erase(0, comma +1);

      // cout << "line is now " << line << "\n";
      //find the second comma
      comma = line.find(".");
      //find the id number
      int id = stoi(line.substr(0, comma));
      //erase the id number and the comma
      line.erase(0, comma + 1);

      temp.id = id;

      // cout << "ID = " << id << ".\n";
      // cout << "Catchphrase = " << line << "\n";

      // cout << "The line is now: " << line << ".\n";

      temp.catchphrase = line;

      //add to the array of characters
      characters[index++] = temp;
    }
  }
  file.close();
}

void save() {
  ofstream file("characters.csv");

  if(file.is_open()){
    for(int i = 0; i < index; i++) {
      file << characters[i].name << ",";
      file << characters[i].id << ",";
      file << characters[i].catchphrase << "\n";
    }
  }
  
  file.close();
}

void add() {
  cout << "Let's add a character!\n";
  character temp;

  cout << "What is their name?\n";
  string input;
  getline(cin, input);
  temp.name = input;

  cout << "ID is " << index << ".\n";
  temp.id = index + 1;

  cout << "What is their catch phrase?\n";
  getline(cin, input);
  temp.catchphrase = input;

  //add the array of characters
  characters[index++] = temp;
}

void show() {
  cout << "herer are the characters:\n";

  for(int i = 0; i < index; i++) {
    cout << characters[i].id << "\t";
    cout << characters[i].name << "\t";
    cout << characters[i].catchphrase << "\n";
  }
  
}

void edit() {
  cout << "Who would you like to edit?\n";
  string input;
  getline(cin,input);
  
  for(int i = 0; i < index; i++) {
    if(characters[i].name == input) {
      cout << "Edit 'name' or 'phrase'?\n";
      getline(cin, input);

      if(input == "name") {
        cout << "What would you like to change their name to?\n";
        getline(cin, input);
        characters[i].name = input;
      }
      else if(input == "phrase") {
        cout << "What is their new catch phrase?\n";
        getline(cin, input);
        characters[i].catchphrase = input;
      }
      else {
        cout << "That is not one of the options.\n";
      }
    }
  }
}

int main() {
  load();
  show();
  add();
  edit();
  save();
}