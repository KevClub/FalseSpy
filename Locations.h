/*
    Header file containing locations for spyfall game.
*/
#ifndef LOCATIONS_H
#define LOACTIONS_H
#include <string>
using namespace std;

class Location {
private:
  string name;
  string[10] roles;

public:
  Location(string n)
  {
    name = n;
  }
  getName()
  {
    return name;
  }
  setRole(string r)
  {
    roles[] = r;
  }
};

#endif
