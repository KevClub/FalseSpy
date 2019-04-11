/*
    Header file containing locations for spyfall game.
*/
#ifndef LOCATIONS_H
#define LOACTIONS_H
#include <iostream>
#include <string>
using namespace std;

class Location {
private:
  string name;
  string roles[10];
  int length = 0;

public:
  //default constructor
  Location()
  { }

  //Constructor
  Location(string n)
  {
    name = n;
  }

  //Get the name of the location
  string getName()
  {
    return name;
  }

  //set the roles in the array
  void setRole(string r)
  {
    if(length <= 10)
    {
      roles[length] = r;
      length++;
    }
    else
    {
      cout << "Array out of bounds." << endl;
    }
  }

  //Get the role you are using
  string getRole(int random_integer)
  {
    if(random_integer <= length)
      return roles[random_integer];
    else
      return "Invalid, see getRole (Out of bounds)";
  }
};

#endif
