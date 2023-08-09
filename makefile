Ass5: main.o Party.o DParty.o RParty.o Politician.o LDPolitician.o LRPolitician.o SDPolitician.o SRPolitician.o PoliticalSys.o
	g++ main.o Party.o DParty.o RParty.o Politician.o LDPolitician.o LRPolitician.o SDPolitician.o SRPolitician.o PoliticalSys.o -o Ass5
main.o: main.cpp PoliticalSys.h Party.h DParty.h RParty.h Politician.h LDPolitician.h LRPolitician.h SDPolitician.h SRPolitician.h Error.h
	g++ -c main.cpp
Party.o: Party.h Party.cpp Politician.h
	g++ -c Party.cpp
DParty.o: DParty.cpp DParty.h Party.h Politician.h
	g++ -c DParty.cpp
RParty.o: RParty.h RParty.cpp Party.h Politician.h
	g++ -c RParty.cpp
Politician.o: Politician.h Politician.cpp
	g++ -c Politician.cpp
LDPolitician.o: LDPolitician.h LDPolitician.cpp Politician.h
	g++ -c LDPolitician.cpp
LRPolitician.o: LRPolitician.h LRPolitician.cpp Politician.h
	g++ -c LRPolitician.cpp
SDPolitician.o: SDPolitician.h SDPolitician.cpp Politician.h
	g++ -c SDPolitician.cpp
SRPolitician.o: SRPolitician.h SRPolitician.cpp Politician.h
	g++ -c SRPolitician.cpp
PoliticalSys.o: PoliticalSys.h PoliticalSys.cpp Party.h DParty.h RParty.h Politician.h LDPolitician.h LRPolitician.h SDPolitician.h SRPolitician.h Error.h
	g++ -c PoliticalSys.cpp
clean:
	rm -f *.o Ass5

