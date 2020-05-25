#include <sstream>

#include "Prepositions.h"

Prepositions::Prepositions(string newSentence, int sentenceNumber) {//, int numOfPreps = 0) {
	sentence = newSentence;
	sentenceID = sentenceNumber;
	numOfPrepositions = 0;
	//numOfPrepositions = numOfPreps;
}

int Prepositions::GetPrepositions() {
	return numOfPrepositions;
}

string Prepositions::ToString() {
	stringstream ss;
	ss << "Sentence #" << sentenceID << "... " << sentence << endl;
	ss << "has " << numOfPrepositions << " prepositions:" << endl ;
	for (int i = 0; i < prepositionsUsed.size(); ++i) {
		ss << prepositionsUsed.at(i);
		if (i != prepositionsUsed.size() - 1) {
			ss << ", ";
		}
	}
	ss << endl << endl;
	return ss.str();
}

void Prepositions::AddPreposition(string newPrep) {
	prepositionsUsed.push_back(newPrep);
}

void Prepositions::SetNumOfPrepositions(int numPrepositions) {
	numOfPrepositions = numPrepositions;
}
