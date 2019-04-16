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
  const int LOCATION_SIZE = 6;
  Location locations[LOCATION_SIZE];
  srand((unsigned)time(0));

//~~~~~~~~~~~~~~~~~~~ School Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location school("High School", "Place where young people attend to learn.");
  school.addRole("Teacher");
  school.addRole("Student");
  school.addRole("Janitor");
  school.addRole("Gym Coach");
  school.addRole("Freshman");
  school.addRole("Student President");
  school.addRole("Principal");
  school.addRole("Visiter");
  school.addRole("Teacher");
  school.addRole("Visiter");
  locations[0] = school;


//~~~~~~~~~~~~~~~~~~~ Bus Stop Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location busStop("Bus Stop", "Place where you wait for the public bus to pick you up.");
  busStop.addRole("Bus Driver");
  busStop.addRole("Student");
  busStop.addRole("Constrution Worker");
  busStop.addRole("Single Mother");
  busStop.addRole("Upset Obese Child");
  busStop.addRole("Busy Business Man");
  busStop.addRole("Deilan");
  busStop.addRole("Driver");
  busStop.addRole("Baby man");
  busStop.addRole("Visitor");
  locations[1] = busStop;

  //~~~~~~~~~~~~~~~~~~~ Army Base Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location armyBase("Army Base", "Base of operations for an army set out to war.");
  armyBase.addRole("Captian");
  armyBase.addRole("Prissoner of War");
  armyBase.addRole("Cadet");
  armyBase.addRole("Armsman");
  armyBase.addRole("Navy Seal");
  armyBase.addRole("Private");
  armyBase.addRole("Drill Sergent");
  armyBase.addRole("General");
  armyBase.addRole("Veteran");
  armyBase.addRole("Injured Soldier");
  locations[2] = armyBase;

  //~~~~~~~~~~~~~~~~~~~ Wedding Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location wedding("Wedding", "At a ceramony of 2 loved ones coming together to live.");
  wedding.addRole("Bride");
  wedding.addRole("Groom");
  wedding.addRole("Best Man");
  wedding.addRole("Priest");
  wedding.addRole("Bride's Maid");
  wedding.addRole("Drunk Uncle");
  wedding.addRole("Wedding Crasher");
  wedding.addRole("Bride's Father");
  wedding.addRole("High School Friend");
  wedding.addRole("Ring Bearer");
  locations[3] = wedding;

  //~~~~~~~~~~~~~~~~~~~ Anime Convention Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location anime("Anime Convention", "Nerdy group of people who enjoy animated Japanese cartoons gather in one place.");
  anime.addRole("Goku (from DBZ)");
  anime.addRole("Naruto (from naruto)");
  anime.addRole("Saskai (from naruto)");
  anime.addRole("Shinichi (from parasyte)");
  anime.addRole("Attendent");
  anime.addRole("Lost (confused) Grandmother");
  anime.addRole("Host");
  anime.addRole("BodyGuard");
  anime.addRole("Manga Author");
  anime.addRole("Worker");
  locations[4] = anime;

  //~~~~~~~~~~~~~~~~~~~ Anime Convention Location ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Location conference("Conference Room", "the place where the bois go when they get payed more than women.");
  conference.addRole("CEO");
  conference.addRole("Networker");
  conference.addRole("Sales Person");
  conference.addRole("Person who walked in on the meeting");
  conference.addRole("Organizer");
  conference.addRole("Finance Chair/Treasurer");
  conference.addRole("Presentation Team");
  conference.addRole("Presentation Team");
  conference.addRole("Presentation Team");
  conference.addRole("Body Guard");
  locations[5] = conference;

//Get current Location
Location yourLocation = getLocation(locations, randomNumGen(LOCATION_SIZE));


//Players
Player *players[10];
int numPlayers = 0;

//Bryan
Player* bryan = new Player("Bryan");
bryan->setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = bryan;
numPlayers++;

//Chester
Player* chester = new Player("Chester");
chester->setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = chester;
numPlayers++;

//Seth
Player* seth = new Player("Seth");
seth->setRole(yourLocation.getRole(randomNumGen(10)));
players[numPlayers] = seth;
numPlayers++;

//Make someone the spy
Player* spy = new Player();
*spy = *players[randomNumGen(numPlayers)];
for(int i =0; i < numPlayers; i++)
{
  if(players[i]->getName() == spy->getName())
  {
    players[i]->setRole("Spy");
    players[i]->spyValue(true);
  }
}

//UI
cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Game ]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
cout << "Player: " << seth->getName() << endl << "# Players: " << numPlayers << endl;
cout  << endl << endl;

  if(seth->getRole() != "Spy")
  {
    cout << "The location is: " << yourLocation.getName() << endl;
    cout << "Description: " << yourLocation.getDesc() << endl;
    cout << "Your role is: " << seth->getRole() << endl;
    cout << endl << "The game plays out..." << endl << endl;
    cout << "The spy was: " << spy->getName() << endl;
  }
  else if(seth->getRole() == "Spy")
  {
    cout << "Your role is: " << seth->getRole() << endl;
    cout << "Try and guess the location without being caught." << endl;
    cout << endl << "The game plays out..." << endl << endl;
    cout << "The spy was: You" << endl;
  }


  cout << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~[ DEV/PROGRAMMER KNOWLEDGE ]~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "Spy: " << spy->getName() << endl << "-------------------" << endl;
  cout << "P1: " << seth->getName() << endl << seth->getRole() << endl << seth->isSpy() << endl;
  cout << "P2: " << bryan->getName() << endl << bryan->getRole() << endl << bryan->isSpy() << endl;
  cout << "P3: " << chester->getName() << endl << chester->getRole() << endl << chester->isSpy() << endl;


delete spy;
delete bryan;
delete chester;
delete seth;
//delete players;

  system("PAUSE");
  return 0;
}


////~~~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Creates a random number and returns it.
int randomNumGen(int length)
{
    int random_integer;
    random_integer = (rand() % length);
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
