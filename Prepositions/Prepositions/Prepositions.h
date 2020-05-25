#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Prepositions {

public:
	Prepositions(string sentence, int numOfPrepositions);//, int numOfPreps);
	int GetPrepositions();
	string ToString();
	void AddPreposition(string newPrep);
	void SetNumOfPrepositions(int numOfPrepositions);

private:
	int sentenceID;
	int numOfPrepositions;
	string sentence;
	vector<string> prepositionsUsed;
};