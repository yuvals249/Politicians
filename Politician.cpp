#include "Politician.h"

// Constructor
Politician::Politician(string firstName, string lastName, int id, int power) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->party = nullptr;
    this->chairman = nullptr;
    this->power = power;
}

// Copy Constructor
Politician::Politician(const Politician& cSource) {
    this->firstName = cSource.firstName;
    this->lastName = cSource.lastName;
    this->id =cSource.id;
    this->party = cSource.party;
    this->chairman = cSource.chairman;
    this->power = cSource.power;
}

// Function that returns a string of the firstName attribute of the politician.
const string& Politician::getFirstName() const {
    return firstName;
}

//const string& Politician::getLastName() const {
//    return lastName;
//}

// Function that returns an integer of the id attribute of the politician.
const int Politician::getId() const {
    return id;
}

// Function that returns a pointer to the party of this the politician.
Party* Politician::getParty() const {
    return party;
}

//Politician* Politician::getChairman() const {
//    return chairman;
//}