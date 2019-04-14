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
  string description;
  string roles[10];
  int length;

public:
  //default constructor
  Location()
  {
    length =0;
  }

  //Constructor
  Location(string n, string d)
  {
    name = n;
    description = d;
    length = 0;
  }

  //Get the name of the location
  string getName()
  {
    return name;
  }
  string getDesc()
  {
    return description;
  }

  //set the roles in the array
  void addRole(string r)
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
