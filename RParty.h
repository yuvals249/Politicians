#ifndef ASSIGNMENT5_RPARTY_H
#define ASSIGNMENT5_RPARTY_H
#include "Party.h"
#include "iostream"
using namespace std;

class RParty:
        public Party{

public:
    // Constructor
    RParty(string partyName): Party(partyName) {};
    // Copy constructor
    RParty(const Party& cSource): Party(cSource) {};
    // Destructor
    virtual ~RParty() = default;

    // Virtual functions that prints the information of the party and of the members in it.
    virtual void printParty();

    // Virtual function that received pointer to politician and adds him to the current party.
    virtual bool addPolitician(Politician* politician);

};


#endif //ASSIGNMENT5_RPARTY_H