#ifndef ASSIGNMENT5_PARTY_H
#define ASSIGNMENT5_PARTY_H
#include "Politician.h"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// This abstract class implement party module.
// Each party has three attributes: party name that save string of the party name, Chairman that save the politician
// who is the chairman of the party and vector partyMembers that saves all the politicians in this party.
class Party {

protected:
    string partyName;
    Politician* Chairman;
    vector<Politician*> partyMembers;

public:
    // Constructor
    explicit Party(string partyName);
    // Copy Constructor
    Party(const Party& cSource);
    // Destructor
    virtual ~Party() = default;

    // Virtual function that received pointer to politician and adds him to the current party.
    virtual bool addPolitician(Politician* politician);

    // Function that received pointer to politician and removes him from the current party.
    void removePolitician(Politician* politician);

// Function that made a primaries and update who won the election as the chairman.
    Politician& primaries();

    // Function that returns the sum of the power of all the politicians in this party.
    int partyPower();

    // Function that returns the name of the chairman in the party.
    const string getChairmanName() const;

    // Pure virtual functions that prints the information of the party.
    virtual void printParty() = 0;

    // Function that returns the number of the partisans in the party.
    const int getSize() const {return this->partyMembers.size();}

    // Function that returns the name of the party.
    const string getPartyName() const {return this->partyName;}

    // Function that returns the vector array of the party's members.
    const vector<Politician*> getPartyMembers() const {return this->partyMembers;}

//    // Function that return pointer to the chairman.
//    Politician* getChairman() const {return this->Chairman;}
};


#endif //ASSIGNMENT5_PARTY_H