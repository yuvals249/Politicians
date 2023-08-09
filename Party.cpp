#include "Party.h"

// Constructor
Party::Party(string partyName) {
    this->partyName = partyName;
    this->Chairman = nullptr;
}

// Copy Constructor
Party::Party(const Party& cSource) {
    this->partyName = cSource.partyName;
    this->Chairman = cSource.Chairman;
    this->partyMembers = cSource.partyMembers;
}

// Virtual function that received pointer to politician and adds him to the current party.
// The function returns true if the function succeed.
bool Party::addPolitician(Politician* politician) {
    partyMembers.push_back(politician);
    politician->setParty(this);
    politician->setChairman(this->Chairman);
    return true;
}

// Function that received pointer to politician and removes him from the current party.
void Party::removePolitician(Politician* politician) {
    if (this->Chairman != nullptr && this->Chairman->getId() == politician->getId()) {
        this->Chairman = nullptr;
        vector<Politician *>::iterator it;
        for (it = partyMembers.begin(); it != partyMembers.end(); ++it) {
            (*it)->setChairman(nullptr);
        }
    }
    if (politician->getParty() == this) {
        politician->setChairman(nullptr);
        politician->setParty(nullptr);
    }
    vector<Politician *>::iterator it;
    int i = 0;
    for (it = partyMembers.begin(); it != partyMembers.end(); ++it) {
        if ((*it)->getId() == politician->getId()) {
            break;

        }
        i++;
    }
    partyMembers.erase(partyMembers.begin() + i);
}



// Function that made a primaries and update who won the election as the chairman.
Politician& Party::primaries() {
    Politician* mostPowerfulPolitician = nullptr;
    vector<Politician*>::iterator it;
    for ( it = partyMembers.begin(); it != partyMembers.end(); ++it ) {
        if ((*it)->getPower() == (*it)->getPurePower()) {
            if (mostPowerfulPolitician == nullptr) {
                mostPowerfulPolitician = *it;
            }
            else {
                if (mostPowerfulPolitician->getPurePower() < (*it)->getPurePower()) {
                    mostPowerfulPolitician = *it;
                }
            }
        }
    }
    if (mostPowerfulPolitician != nullptr) {
        for ( it = partyMembers.begin(); it != partyMembers.end(); ++it ) {
            (*it)->setChairman(mostPowerfulPolitician);
        }
        this->Chairman = mostPowerfulPolitician;
    }
    return *mostPowerfulPolitician;
}

// Function that returns the sum of the power of all the politicians in this party.
int Party::partyPower() {
    int totalPowerOfParty = 0;
    vector<Politician*>::iterator it;
    for ( it = partyMembers.begin(); it != partyMembers.end(); ++it ) {
        totalPowerOfParty += (*it)->getPower();
    }
    return totalPowerOfParty;
}

// Function that returns the name of the chairman in the party if there is politician as chairman or None if not.
const string Party::getChairmanName() const {
    if (this->Chairman == nullptr) {
        return "None";
    }
    else {
        return this->Chairman->getFirstName();
    }
}
