#include "PoliticalSys.h"

// Function that responsible to update the biggest party in the system after each change.
void PoliticalSys::updateBiggestParty() {

    vector<Party*>::iterator partyIt;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        if (this->biggestParty == nullptr) {
            this->biggestParty = (*partyIt);
        }
        else if (this->biggestParty->getSize() < (*partyIt)->getSize()) {
            this->biggestParty = (*partyIt);
        }
        else {
            if (this->biggestParty->getSize() == (*partyIt)->getSize() &&
                this->biggestParty->getPartyName() < (*partyIt)->getPartyName()) {
                this->biggestParty = (*partyIt);
            }
        }
    }
}

// Function that receives string with all the information of the politician and creates him.
// The function returns reference for him after its done.
Politician& PoliticalSys::insertToAllPoliticiansVector (string politicianInfo) {
    string firstName, lastName;
    int id, power;
    char politicalBloc, politicalType;
    Politician* politician;
    istringstream currentWord(politicianInfo);
    currentWord >> firstName;
    currentWord >> lastName;
    currentWord >> id;
    currentWord >> power;
    currentWord >> politicalBloc;
    currentWord >> politicalType;
    if (politicalBloc == 'D' && politicalType == 'L') {
        politician = new LDPolitician(firstName, lastName, id, power);
    }
    else if (politicalBloc == 'R' && politicalType == 'L') {
        politician = new LRPolitician(firstName, lastName, id, power);
    }
    else if (politicalBloc == 'D' && politicalType == 'S') {
        politician = new SDPolitician(firstName, lastName, id, power);
    }
    else {      // if (politicalBloc == 'R' && politicalType == 'S')
        politician = new SRPolitician(firstName, lastName, id, power);
    }
    this->allPoliticians.push_back(politician);
    return *politician;
}

// Function that receives string with all the information of the party and creates it.
// The function returns reference for it after its done.
Party& PoliticalSys::insertToAllPartiesVector (string partyInfo) {
    string partyName;
    char politicalBloc;
    Party* party;
    istringstream currentWord(partyInfo);
    currentWord >> partyName;
    currentWord >> politicalBloc;
    if (politicalBloc == 'D') {
        party = new DParty(partyName);
    }
    else {      // politicalBloc == 'R'
        party = new RParty(partyName);
    }
    this->allParties.push_back(party);
    return *party;
}

// Constructor that initialize the political system and adds all the parties and politicians from
// the configuration file.
PoliticalSys::PoliticalSys(const string& path) {
    string line, word;
    bool isParty = false;
    ifstream textFile(path);
    if(textFile.is_open()) {
        getline(textFile, line);
        while(getline(textFile, line)) {
            istringstream currentLine(line);
            if(!line.empty() && line[line.size() - 1] == '\r')
                line.erase(line.size() -1);
            if (line == "Parties:") {
                isParty = true;
                continue;
            }
            if (!isParty) {
                insertToAllPoliticiansVector(line);
            }
            else {
                insertToAllPartiesVector(line);
            }
        }
        textFile.close();
    }
    vector<Party*>::iterator partyIt;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        addPoliticiansToParty(*(*partyIt));
    }
    updateBiggestParty();
}

// Function that receives reference to new party and adds politicians to it.
void PoliticalSys::addPoliticiansToParty(Party& newParty) {
    vector<Politician*>::iterator politicianIt;
    Party* deletedParty;
    for (politicianIt = this->allPoliticians.begin(); politicianIt != this->allPoliticians.end(); ++politicianIt) {
        if (((*politicianIt)->getParty() == nullptr)) {
            (newParty).addPolitician(*politicianIt);
            continue;
        }
        if ((*politicianIt)->getParty()->getSize() > (newParty).getSize()) {
            deletedParty = (*politicianIt)->getParty();
            if (newParty.addPolitician(*politicianIt)) {
                deletedParty->removePolitician(*politicianIt);
            }
        }
//        if ((*politicianIt)->getParty()->getSize() > (newParty).getSize()) {
//            deletedParty = (*politicianIt)->getParty();
//            deletedParty->removePolitician(*politicianIt);
//            if (!(newParty).addPolitician(*politicianIt)) {
//                deletedParty->addPolitician((*politicianIt));
//            }
//        }
    }
}

// Function that receives reference to new politician and adds fit party to it if exists.
bool PoliticalSys::addPartyToPolitician(Politician& newPolitician) {
    bool thereIsMatchingParty = false;
    vector<Party*>::iterator partyIt;
    Party* deletedParty;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        if (((newPolitician).getParty() == nullptr)) {
            if ((*partyIt)->addPolitician(&newPolitician)) {
                thereIsMatchingParty = true;
            }
            continue;
        }
        if ((newPolitician).getParty()->getSize() > (*partyIt)->getSize()) {
            deletedParty = (newPolitician).getParty();
            deletedParty->removePolitician(&newPolitician);
            if (! ((*partyIt)->addPolitician(&newPolitician)) ) {
                deletedParty->addPolitician((&newPolitician));
            }
            else {
                thereIsMatchingParty = true;
            }
        }
    }
    updateBiggestParty();
    return thereIsMatchingParty;
}

// Case 1
// Function that adds a new politician to the system.
void PoliticalSys::addPolitician() {
    string politicianInString;
    string firstName, lastName, id, power, politicalBloc, politicalType;
    vector<Politician*>::iterator politicianIt;
    cout << "---Create Politician---" << endl;
    while (true) {
        cout << "First name:" << endl;
        cin >> firstName;
        cout << "Last name:" << endl;
        cin >> lastName;
        cout << "ID:" << endl;
        cin >> id;
        cout << "Power:" << endl;
        cin >> power;
        cout << "Republican or Democratic person" << endl;
        cin >> politicalBloc;
        cout << "Leader or Social" << endl;
        cin >> politicalType;
        try {
            if ( (!all_of(id.begin(), id.end(), ::isdigit)) || (stoi(id)) < 1 ) {
                throw ErrorInvalidDetails();
            }
            for (politicianIt = this->allPoliticians.begin(); politicianIt != this->allPoliticians.end(); ++politicianIt) {
                if ((*politicianIt)->getId() == stoi(id)) {
                    throw ErrorInvalidDetails();
                }
            }
            if ( (!all_of(power.begin(), power.end(), ::isdigit)) || stoi(power) < 0 ) {
                throw ErrorInvalidDetails();
            }
            if ( (politicalBloc.length() != 1) || ((politicalBloc != "R") && (politicalBloc != "D")) ) {
                throw ErrorInvalidDetails();
            }
            if ( (politicalType.length() != 1) || ((politicalType != "S") && (politicalType != "L")) ) {
                throw ErrorInvalidDetails();
            }
        }
        catch (Error& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    politicianInString = firstName + " " + lastName + " " + id + " " + power + " " + politicalBloc + " " + politicalType;
    Politician& newPolitician = insertToAllPoliticiansVector(politicianInString);
    addPartyToPolitician(newPolitician);
//    updateBiggestParty();
}

// Case 2
// Function that adds a new party to the system.
void PoliticalSys::addParty() {
    string partyInString;
    string partyName, politicalBloc;
    vector<Party*>::iterator partyIt;
    cout << "---Create Party---" << endl;
    while (true) {
        cout << "Name:" << endl;
        cin >> partyName;
        cout << "Republican or Democratic party" << endl;
        cin >> politicalBloc;
        try {
            for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
                if ((*partyIt)->getPartyName() == partyName) {
                    throw ErrorInvalidDetails();
                }
            }
            if ( (politicalBloc.length() != 1) || ((politicalBloc != "R") && (politicalBloc != "D")) ) {
                throw ErrorInvalidDetails();
            }
        }
        catch (Error& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }

    partyInString = partyName + " " + politicalBloc;
    Party& newParty = insertToAllPartiesVector (partyInString);
    addPoliticiansToParty(newParty);
    updateBiggestParty();
}

// Case 3
// Function that removes a politician from the system.
bool PoliticalSys::removePolitician() {
    string politicianId;
    Politician* politicianToDelete = nullptr;
    vector<Politician*>::iterator politicianIt;
    cout << "---Remove Politician---" << endl;
    while (true) {
        cout << "Enter the ID:" << endl;
        cin >> politicianId;
        try {
            if ( (!all_of(politicianId.begin(), politicianId.end(), ::isdigit)) || (stoi(politicianId)) < 1 ) {
                throw ErrorInvalidId();
            }
            for (politicianIt = this->allPoliticians.begin(); politicianIt != this->allPoliticians.end(); ++politicianIt) {
                if ((*politicianIt)->getId() == stoi(politicianId)) {
                    politicianToDelete = *politicianIt;
                    if ((*politicianIt)->getParty() != nullptr) {
                        (*politicianIt)->getParty()->removePolitician(*politicianIt);
                    }
                    break;
                }
            }
            if (politicianToDelete == nullptr) {
                throw ErrorInvalidId();
            }
        }
        catch (Error& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }

    vector<Politician *>::iterator it;
    int i = 0;
    for (it = this->allPoliticians.begin(); it != this->allPoliticians.end(); ++it) {
        if ((*it)->getId() == politicianToDelete->getId()) {
            break;

        }
        i++;
    }
    this->allPoliticians.erase(this->allPoliticians.begin() + i);
    delete politicianToDelete;
    updateBiggestParty();
}

// Case 4
// Function that removes a party from the system.
bool PoliticalSys::removeParty() {
    if (this->allParties.empty()) {
        return true;
    }
    string partyName;
    Party *partyToDelete = nullptr;
    vector<Party*>::iterator partyIt;
    cout << "---Remove Party---" << endl;
    while (true) {
        cout << "Enter party name:" << endl;
        cin >> partyName;
        try {
            for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
                if ((*partyIt)->getPartyName() == partyName) {
                    partyToDelete = *partyIt;
                    break;
                }
            }
            if (partyToDelete == nullptr) {
                throw ErrorInvalidName();
            }
        }
        catch (Error& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
    vector<Politician*> partyToDeleteMembers;
    partyToDeleteMembers = partyToDelete->getPartyMembers();
    while (!(partyToDelete->getPartyMembers()).empty()) {
        partyToDelete->removePolitician(*(partyToDelete->getPartyMembers()).begin());
    }
    vector<Party*>::iterator it;
    int i = 0;
    for (it = this->allParties.begin(); it != this->allParties.end(); ++it) {
        if ((*it)->getPartyName() == partyToDelete->getPartyName()) {
            break;

        }
        i++;
    }
    this->allParties.erase(this->allParties.begin() + i);

    vector<Politician*>::iterator politicianIt;
    for (politicianIt = partyToDeleteMembers.begin(); politicianIt != partyToDeleteMembers.end(); ++politicianIt) {
        addPartyToPolitician(*(*politicianIt));
    }
    delete partyToDelete;
    updateBiggestParty();
}

// Case 5
// Function that makes elections in the system and updates the chairman for each party.
void PoliticalSys::elections() {
    if (this->allParties.empty() || this->allPoliticians.empty()) {
        return;
    }
    Party *mostPowerfulParty = nullptr;
    cout << "----Primaries----" << endl;
    Politician *mostPowerfulPolitician;
    vector<Party *>::iterator partyIt;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        mostPowerfulPolitician = &(*partyIt)->primaries();
        if (mostPowerfulPolitician == nullptr) {
            cout << "None is the chairman of " << (*partyIt)->getPartyName() << endl;
        } else {
            cout << mostPowerfulPolitician->getFirstName() << " is the chairman of " << (*partyIt)->getPartyName()
                 << endl;
        }
    }
    cout << "----Elections----" << endl;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        cout << "Party: " << (*partyIt)->getPartyName() << ",Power: " << (*partyIt)->partyPower() << endl;
        if (mostPowerfulParty == nullptr) {
            mostPowerfulParty = (*partyIt);
        } else {
            if (mostPowerfulParty->partyPower() < (*partyIt)->partyPower()) {
                mostPowerfulParty = (*partyIt);
            }
        }
    }
    cout << "----Elections Results----" << endl;
    cout << mostPowerfulParty->getPartyName() << " party won the elections and " <<
         mostPowerfulParty->getChairmanName() << " is the prime minister" << endl;
}

// Case 6
// Function that prints all the politicians in the system.
void PoliticalSys::printPoliticians() {
    if (this->allPoliticians.empty()) {
        return;
    }
    cout << "----Politicians----" << endl;
    vector<Politician*>::iterator politicianIt;
    for (politicianIt = this->allPoliticians.begin(); politicianIt != this->allPoliticians.end(); ++politicianIt) {
        (*politicianIt)->printPolitician();
    }
}

// Case 7
// Function that prints all the parties in the system and the politicians in them.
void PoliticalSys::printParties() {
    if (this->allParties.empty()) {
        return;
    }
    cout << "----Parties----" << endl;
    vector<Party *>::iterator partyIt;
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        (*partyIt)->printParty();
    }
}

// Case 8
// Function that returns the biggest party and how much politicians it has.
// This function returns it on O(1) run time.
void PoliticalSys::BiggestParty() {
    if (this->allParties.empty()) {
        return;
    }
    cout << "----Biggest Party----" << endl;
    cout << "[" << this->biggestParty->getPartyName() << "," << this->biggestParty->getSize() << "]" << endl;
}

// Case 0
// Destructor
// This functions deletes all the politicians and parties from the system and clear them from the memory.
PoliticalSys::~PoliticalSys() {
    vector<Party*>::iterator partyIt;
    vector<Politician*>::iterator politicianIt;
    for (politicianIt = this->allPoliticians.begin(); politicianIt != this->allPoliticians.end(); ++politicianIt) {
        delete (*politicianIt);
    }
    for (partyIt = this->allParties.begin(); partyIt != this->allParties.end(); ++partyIt) {
        delete (*partyIt);
    }
    this->allPoliticians.clear();
    this->allPoliticians.clear();
}