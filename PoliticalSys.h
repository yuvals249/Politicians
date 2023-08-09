#ifndef ASSIGNMENT5_POLITICALSYS_H
#define ASSIGNMENT5_POLITICALSYS_H
#include "iostream"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Politician.h"
#include "Party.h"
#include "LDPolitician.h"
#include "LRPolitician.h"
#include "SDPolitician.h"
#include "SRPolitician.h"
#include "DParty.h"
#include "RParty.h"
#include "Error.h"
using namespace std;


// This class responsible to the cases of the political system
// Each political system has 2 vectors array. one for all the parties and second for all the politicians.
// There is a Party* biggestParty for the biggest party in the system in the given time to returns it in O(1).
// There is also two helper functions to insert all the politicians and parties from the configuration
// file at the start.
class PoliticalSys {

    vector<Politician*> allPoliticians;
    vector<Party*> allParties;
    Party* biggestParty = nullptr;

    // Function that receives string with all the information of the politician and creates him.
    // The function returns reference for him after its done.
    Politician& insertToAllPoliticiansVector(string politicianInfo);

    // Function that receives string with all the information of the party and creates it.
    // The function returns reference for it after its done.
    Party& insertToAllPartiesVector(string politicianInfo);

    // Function that responsible to update the biggest party in the system after each change.
    void updateBiggestParty();

    // Function that receives reference to new party and adds politicians to it.
    void addPoliticiansToParty(Party& newParty);

    // Function that receives reference to new politician and adds fit party to it if exists.
    bool addPartyToPolitician(Politician& newPolitician);



public:

    // Constructor
    PoliticalSys();
    // Default constructor
    PoliticalSys(const string& path);
//    // Copy constructor

//    PoliticalSys(const PoliticalSys& cSource);

    // Destructor
    ~PoliticalSys();

    // Function that adds a new politician to the system.
    void addPolitician();

    // Function that adds a new party to the system.
    void addParty();

    // Function that removes a politician from the system.
    bool removePolitician();

    // Function that removes a party from the system.
    bool removeParty();

    // Function that makes elections in the system and updates the chairman for each party.
    void elections();

    // Function that prints all the politicians in the system.
    void printPoliticians();

    // Function that prints all the parties in the system and the politicians in them.
    void printParties();

    // Function that returns the biggest party and how much politicians it has.
    // This function returns it on O(1) run time.
    void BiggestParty();

};


#endif //ASSIGNMENT5_POLITICALSYS_H