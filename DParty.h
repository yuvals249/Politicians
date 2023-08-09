#ifndef ASSIGNMENT5_DPARTY_H
#define ASSIGNMENT5_DPARTY_H
#include "Party.h"
#include "iostream"
using namespace std;

class DParty:
        public Party{

public:
    // Constructor
    explicit DParty(string partyName): Party(partyName) {};
    // Copy constructor
    explicit DParty(const Party& cSource): Party(cSource) {};
    // Destructor
    virtual ~DParty() = default;

// Virtual functions that prints the information of the party and of the members in it.
    virtual void printParty();

    // Virtual function that received pointer to politician and adds him to the current party.
    virtual bool addPolitician(Politician* politician);

};


#endif //ASSIGNMENT5_DPARTY_H