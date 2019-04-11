/*
  Game of spyfall Driver
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Locations.h"
#include "Players.h"

using namespace std;

//Prototypes
int randomNumGen(int);
Location getLocation(Location*, int);

//main function
int main()
{
  int LOCATION_SIZE = 2;
  Location locations[LOCATION_SIZE];

//~~~~~~~~~~~~~~~~~~~ School Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location school("School", "Place where young people attend to learn.");
  school.setRole("Teacher");
  school.setRole("Student");
  school.setRole("Janitor");
  school.setRole("Gym Coach");
  school.setRole("Freshman");
  school.setRole("Student President");
  school.setRole("Principal");
  school.setRole("Visiter");
  school.setRole("Teacher");
  school.setRole("Visiter");
  locations[0] = school;


//~~~~~~~~~~~~~~~~~~~ Bus Stop Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location busStop("Bus Stop", "Place where you wait for the public bus to pick you up.");
  busStop.setRole("Bus Driver");
  busStop.setRole("Student");
  busStop.setRole("Constrution Worker");
  busStop.setRole("Single Mother");
  busStop.setRole("Upset Obese Child");
  busStop.setRole("Busy Business Man");
  busStop.setRole("Deilan");
  busStop.setRole("Driver");
  busStop.setRole("Baby man");
  busStop.setRole("Visiter");
  locations[1] = busStop;

//Get current Location
Location yourLocation = getLocation(locations, randomNumGen(LOCATION_SIZE));


//Players
Player players[10];
int numPlayers = 0;

//Bryan
Player bryan("Bryan");
bryan.setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = bryan;
numPlayers++;

//Chester
Player chester("Chester");
chester.setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = chester;
numPlayers++;

//Seth
Player seth("Seth");
seth.setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = seth;
numPlayers++;

//Make someone the spy
Player spy = players[randomNumGen(numPlayers)];
for (int i =0; i < numPlayers; i++)
{
  if(players[i].getName() == spy.getName())
  {
    players[i].spyValue(true);
    players[i].setRole("Spy");
  }
}
spy.spyValue(true);
spy.setRole("Spy");

//UI
  cout << "Your random number is: " << randomNumGen(LOCATION_SIZE) << endl;
  cout << "The location is: " << yourLocation.getName() << endl;
  cout << "Description: " << yourLocation.getDesc() << endl;
  cout << "Your role is: " << seth.getRole() << endl;
  cout << "The spy was: " << spy.getName() << endl;

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Spy: " << spy.getName() << endl << spy.getRole() << endl << spy.isSpy() << endl;
  cout << "Seth: " << seth.getName() << endl << seth.getRole() << endl << seth.isSpy() << endl;
  cout << "Bryan: " << bryan.getName() << endl << bryan.getRole() << endl << bryan.isSpy() << endl;
  cout << "Chester: " << chester.getName() << endl << chester.getRole() << endl << chester.isSpy() << endl;

  return 0;
}


////~~~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Creates a random number and returns it.
int randomNumGen(int length)
{
  //Error: isn't completely random
  srand((unsigned)time(0));
    int random_integer;
    random_integer = (rand()%length);
    return random_integer;
}

/*
  Purpose: returns a random location.
  Arguments: accepts an array of locations, and random integer.
  Returns: Location object
*/
Location getLocation(Location* locations, int random_integer)
{
  return locations[random_integer];
}
