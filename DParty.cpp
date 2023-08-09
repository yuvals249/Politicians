#include "DParty.h"

// Virtual functions that prints the information of the party and of the members in it.
void DParty::printParty() {
    string chairman;
    if (this->Chairman != nullptr) {
        chairman = this->Chairman->getFirstName();
    }
    else {
        chairman = "None";
    }
    cout << "Democrat Party: " << this->partyName << ", chairman:" << chairman << ", Size:"
         << this->partyMembers.size() << endl;
    vector<Politician*>::iterator it;
    for ( it = partyMembers.begin(); it != partyMembers.end(); ++it ) {
        cout << "\t";
        (*it)->printPolitician();
    }
}

// Virtual function that received pointer to politician and adds him to the current party using party::addPolitician.
// The function returns true if he could add or false either.
bool DParty::addPolitician(Politician* politician) {
    if (politician->potentialMatch(this)) {
        Party::addPolitician(politician);
        return true;
    }
    return false;
}