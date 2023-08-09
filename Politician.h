#ifndef ASSIGNMENT5_POLITICIAN_H
#define ASSIGNMENT5_POLITICIAN_H
#include "iostream"
using namespace std;

// Class declarations
class Party;
class DParty;
class RParty;

// This abstract class implement politician module.
// Each politician has six attributes: firstName and lastName that save strings of his name, id that saves an integer
// of the id, pointer to party that save the party of the politician, Chairman that save the politician of the
// politician's party and power that saves an integer of the power.
class Politician {
protected:
    string firstName;
    string lastName;
    int id;
    Party* party;
    Politician* chairman;
    int power;

public:

    // Constructor
    Politician(string firstName, string lastName, int id, int power);
    // Copy Constructor
    Politician(const Politician& cSource);
    // Destructor
    virtual ~Politician() = default;

    // Pure virtual functions that prints the information of the politician.
    virtual const void printPolitician() const = 0;

    // Pure virtual functions that returns the power of the politician.
    virtual const int getPower() const = 0;

    // Function that returns the power attribute of the politician.
    const int getPurePower() const {return this->power;}

    // Function that receives a pointer to Politician and set him as the chairman of the current politician.
    const void setChairman(Politician* cSource) {this->chairman = cSource;}

    // Function that receives a pointer to Party and set it as the party of the current politician.
    const void setParty(Party* cSource) {this->party = cSource;}

    // Function that returns a string of the firstName attribute of the politician.
    const string& getFirstName() const;

//    const string& getLastName() const;

    // Function that returns an integer of the id attribute of the politician.
    const int getId() const;

    // Function that returns a pointer to the party of this the politician.
    Party* getParty() const;

//    Politician* getChairman() const;

    // Pure virtual functions that implements the polymorphism in politician and return true or false if the party that
    // received is fits.
    virtual const bool potentialMatch(DParty* party) const = 0;

    // Pure virtual functions that implements the polymorphism in politician and return true or false if the party that
    // received is fits.
    virtual const bool potentialMatch(RParty* party) const = 0;


};


#endif //ASSIGNMENT5_POLITICIAN_H