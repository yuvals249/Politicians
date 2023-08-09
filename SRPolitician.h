#ifndef ASSIGNMENT5_SRPOLITICIAN_H
#define ASSIGNMENT5_SRPOLITICIAN_H
#include "Politician.h"
#include "iostream"
using namespace std;

class SRPolitician:
        public Politician{

public:
    // Constructor
    SRPolitician(string firstName, string lastName, int id, int power): Politician(firstName, lastName, id, power) {};
    // Copy constructor
    SRPolitician(const SRPolitician& cSource): Politician(cSource) {};
    // Destructor
    virtual ~SRPolitician() = default;

    // Virtual functions that prints the information of the politician.
    virtual const void printPolitician() const;

    // Function that returns the power of the politician to primaries depends his type (Leader / Social).
    virtual const int getPower() const;

    // The implement of virtual functions that implements the polymorphism in politician and return true or false if
    // the party that received is fits.
    virtual const bool potentialMatch(DParty* party) const {return false;}

    // The implement of virtual functions that implements the polymorphism in politician and return true or false if
    // the party that received is fits.
    virtual const bool potentialMatch(RParty* party) const {return true;}
};


#endif //ASSIGNMENT5_SRPOLITICIAN_H