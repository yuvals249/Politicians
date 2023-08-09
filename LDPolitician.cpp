#include "LDPolitician.h"

// Virtual functions that prints the information of the politician.
const void LDPolitician::printPolitician() const {
    string chairman = this->chairman != nullptr ? this->chairman->getFirstName() : "None";
    cout << "Democratic Person:" << this->firstName << " " << this->lastName << ", Id:" << this->id
         << ", Power:" << this->power << ", Type:L, Chairman: " << chairman << endl;
}

// Function that returns the power of the politician to primaries depends his type (Leader / Social).
const int LDPolitician::getPower() const {
    return getPurePower();
}
