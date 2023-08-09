#include "SRPolitician.h"

// Virtual functions that prints the information of the politician.
const void SRPolitician::printPolitician() const {
    string chairman = this->chairman != nullptr ? this->chairman->getFirstName() : "None";
    cout << "Republican Person:" << this->firstName << " " << this->lastName << ", Id:" << this->id
         << ", Power:" << this->power << ", Type:S, Chairman: " << chairman << endl;
}

// Function that returns the power of the politician to primaries depends his type (Leader / Social).
const int SRPolitician::getPower() const {
    return this->power * 2;
}