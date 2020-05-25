#include "Prepositions.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <fstream>
#include <streambuf>

using namespace std;

set<string> MakePrepositions(string fileName);
int CalculatePrepositions(string sentence, set<string> PrepositionSet, Prepositions* newObject);
vector<string> ParseInput(string input);
vector<string> ParseSentence(string sentence);
void PrintOutput(vector<Prepositions*> sentences);


int main() {
	string fileName = "List_Of_Prepositions.txt";
	set<string> PrepositionSet = MakePrepositions(fileName);
	string input;
	//Load in data
	cout << "Enter in the text you want to input." << endl;
	getline(cin, input);

	//Parse input string into sentences and insert into sentences
	vector<string> processedInput = ParseInput(input);
	vector<Prepositions*> sentences;

	for (int i = 0; i < processedInput.size(); ++i) {
		//Prepositions* newObject = new Prepositions();
		Prepositions* newObject = new Prepositions(processedInput.at(i), i + 1);
		int numOfPreps = CalculatePrepositions(processedInput.at(i), PrepositionSet, newObject);
		sentences.push_back(newObject);
	}
	
	cout << endl;

	PrintOutput(sentences);

	system("pause");
	return 0;
}

vector<string> ParseInput(string input) {
	vector<string> parsedInput;
	stringstream ss;
	for (int i = 0; i < input.size(); ++i) {
		ss << input.at(i);
		if ((input.at(i) == '.') || (input.at(i) == '?') || (input.at(i) == '!')) {
			parsedInput.push_back(ss.str());
			ss.str(std::string());
		}
	}
	return parsedInput;
}

int CalculatePrepositions(string sentence, set<string> PrepositionSet, Prepositions* newObject) {
	vector<string> parsedSentence = ParseSentence(sentence);
	int numOfPrepositions = 0;
	for (int i = 0; i < parsedSentence.size(); ++i) {
		if (PrepositionSet.count(parsedSentence.at(i)) != 0) {
			numOfPrepositions += 1;
			newObject->AddPreposition(parsedSentence.at(i));
		}
	}
	newObject->SetNumOfPrepositions(numOfPrepositions);
	return numOfPrepositions;
}

vector<string> ParseSentence(string sentence) {
	vector<string> parsedSentence;
	stringstream ss(sentence);
	string word;
	while (getline(ss, word, ' ')) {
		parsedSentence.push_back(word);
	}
	return parsedSentence;
}

set<string> MakePrepositions(string fileName) {
	ifstream ifs(fileName);
	string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
	vector<string> prepositionsVect = ParseSentence(content);
	set<string> PrepositionSet;
	for (int i = 0; i < prepositionsVect.size(); ++i) {
		PrepositionSet.insert(prepositionsVect.at(i));
	}
	return PrepositionSet;
}

void PrintOutput(vector<Prepositions*> sentences) {
	int numOfBadSentences = 0;
	for (int i = 0; i < sentences.size(); ++i) {
		if (sentences.at(i)->GetPrepositions() > 3) {
			numOfBadSentences += 1;

		}
	}

	if (numOfBadSentences == 0) {
		cout << "Fantastic writing! You have no sentences with more than three prepositions." << endl;
	}
	else {
		cout << "Below is a list of sentences that have over three prepositions." << endl;
		cout << "***************************************************************" << endl;
	}

	for (int i = 0; i < sentences.size(); ++i) {
		if (sentences.at(i)->GetPrepositions() > 3) {
			cout << sentences.at(i)->ToString() << endl;
		}
	}
}