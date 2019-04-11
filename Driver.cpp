/*
  Game of spyfall Driver
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Locations.h"

using namespace std;

int randomNumGen(int);

Location getLocation(Location*, int);

int main()
{
  int LOCATION_SIZE = 2;
  Location locations[LOCATION_SIZE];

  Location school("School");
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

  Location busStop("Bus Stop");
  busStop.setRole("Bus Driver");
  busStop.setRole("Student");
  busStop.setRole("Constrution Worker");
  busStop.setRole("Single Mother");
  busStop.setRole("Upset Obese Child");
  busStop.setRole("Busy Business Man");
  busStop.setRole("Deilan");
  busStop.setRole("Chester");
  busStop.setRole("Baby man");
  busStop.setRole("Bryan");
  locations[1] = busStop;

  Location yourLocation = getLocation(locations, randomNumGen(LOCATION_SIZE));

  cout << "Your random number is: " << randomNumGen(LOCATION_SIZE) << endl;
  cout << "The location is :" << yourLocation.getName() << endl;
  cout << "Your role is :" << yourLocation.getRole(randomNumGen(10 )) << endl;
}

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
