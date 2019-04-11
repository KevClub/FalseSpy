#ifndef PLAYERS_H
#define PLAYERS_H
#include <iostream>
#include <string>
using namespace std;


class Player
{
private:
  string name;
  string role;
  bool spy;

public:
    Player()
    {

    }
    Player(string n)
    {
      name = n;
      spy = false;
    }
    void setRole(string r)
    {
      role = r;
    }
    string getRole()
    {
      return role;
    }
    string getName()
    {
      return name;
    }
    void spyValue(bool b)
    {
      spy = b;
    }
    bool isSpy()
    {
      return spy;
    }
};
#endif
