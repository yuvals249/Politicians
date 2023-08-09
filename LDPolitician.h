#ifndef ASSIGNMENT5_LDPOLITICIAN_H
#define ASSIGNMENT5_LDPOLITICIAN_H
#include "Politician.h"
#include "iostream"
using namespace std;

class LDPolitician:
        public Politician{

public:
    // Constructor
    LDPolitician(string firstName, string lastName, int id, int power): Politician(firstName, lastName, id, power) {};
    // Copy constructor
    LDPolitician(const LDPolitician& cSource): Politician(cSource) {};
    // Destructor
    virtual ~LDPolitician() = default;

    // Virtual functions that prints the information of the politician.
    virtual const void printPolitician() const;

    // Function that returns the power of the politician to primaries depends his type (Leader / Social).
    virtual const int getPower() const;

    // The implement of virtual functions that implements the polymorphism in politician and return true or false if
    // the party that received is fits.
    virtual const bool potentialMatch(DParty* party) const {return true;}

    // The implement of virtual functions that implements the polymorphism in politician and return true or false if
    // the party that received is fits.
    virtual const bool potentialMatch(RParty* party) const {return false;}
};


#endif //ASSIGNMENT5_LDPOLITICIAN_H