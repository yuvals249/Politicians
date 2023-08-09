#ifndef ASSIGNMENT5_LRPOLITICIAN_H
#define ASSIGNMENT5_LRPOLITICIAN_H
#include "Politician.h"
#include "iostream"
using namespace std;

class LRPolitician:
        public Politician{

public:
    // Constructor
    LRPolitician(string firstName, string lastName, int id, int power): Politician(firstName, lastName, id, power) {};
    // Copy constructor
    LRPolitician(const LRPolitician& cSource): Politician(cSource) {};
    // Destructor
    virtual ~LRPolitician() = default;

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


#endif //ASSIGNMENT5_LRPOLITICIAN_H