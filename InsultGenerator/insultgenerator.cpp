//============================================================================
// Name        : OliverAustinAssignment1.cpp
// Author      : Oliver Austin - 20011458
//============================================================================

#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "insultgenerator.h"
using namespace std;

FileException::FileException(const string& message) :
	message(message) {
}
string& FileException::what() {
	return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) :
	message(message) {
}
string& NumInsultsOutOfBounds::what() {
	return message;
}

void InsultGenerator::initialize() {
	int numberOfWords=1;
	string word;

	ifstream fileIn;
	fileIn.open("InsultsSource.txt");
	if (fileIn.fail()) {
		throw FileException("Error opening text file");
	}
	else {
		while (fileIn >> word) {
			if (numberOfWords == 1) {
				firstWord.push_back(word);
			}
			if (numberOfWords == 2) {
				secondWord.push_back(word);
			}
			if (numberOfWords == 3) {
				thirdWord.push_back(word);
			}

		if (numberOfWords == 3) {
			numberOfWords = 1;
		}
		else {
			numberOfWords++;
		}
	}

	sort(firstWord.begin(), firstWord.end());
	sort(secondWord.begin(), secondWord.end());
	sort(thirdWord.begin(), thirdWord.end());

	fileIn.close();
	}
}
const string InsultGenerator::talkToMe() {
	return "Thou " + firstWord.at(rand() % 49) + " " + secondWord.at(
			rand() % 49) + " " + thirdWord.at(rand() % 49) + "!";
}

void InsultGenerator::checkDuplicates(vector<string> insults){
	int count = 0;
	string currentInsult;

	while (count < insults.size()) {
		// if duplicate insult
		if (currentInsult == insults.at(count)) {
			//generate new insult
			currentInsult = talkToMe();
			count = -1;
		}
		count++;
	}
}

const vector<string> InsultGenerator::generate(const int numberOfInsults) {
	string currentInsult;
	vector<string> insults;

	if (!(numberOfInsults>0 && numberOfInsults<10001)) {
		throw NumInsultsOutOfBounds(
				"Invalid number of insults, please specify a number between 1 and 10000");
	}
	else {
		int i=0;

		while (i < numberOfInsults){
			currentInsult = talkToMe();
			checkDuplicates(insults);
			insults.push_back(currentInsult);
			i++;
		}
		sort(insults.begin(), insults.end());
	}
	return insults;
}

void InsultGenerator::generateAndSave(const string file,
		const int numberOfInsults) {
	vector<string> insults;

	if (numberOfInsults < 1 || numberOfInsults > 10000) {
		throw NumInsultsOutOfBounds(
				"Invalid number of insults, please specify a number between 1 and 10000");
	}
	else {
		ofstream fileOut(file);
		if (fileOut.fail()) {
			throw FileException("Error creating file");
		}
		else {
			insults = generate(numberOfInsults);
			int count=0;

			while (count < numberOfInsults) {
				fileOut << insults.at(count) << endl;
				count++;
			}
		}
		fileOut.close();
	}
}
