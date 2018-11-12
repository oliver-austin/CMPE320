#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// class to throw errors on failed file I/O
class FileException {
public:
	// construct exception with the specified error message
    FileException(const string& message);

    // method to display the error message
    string& what(void);
private:
    string message;
};

// class to generate  insults
class InsultGenerator {
public:
    // method to generate the specified number of insults
    const vector<string> generate(const int);

    //method to generate the specified number of insults, and save them to the specified file
    void generateAndSave(const string, const int);

	// method to load source phrases from text file
    void initialize(void);

    // method to return a randomly generated insult
    const string talkToMe(void);
private:
    // vectors for storing the words from which the insults are composed
    vector<string> firstWord;
    vector<string> secondWord;
    vector<string> thirdWord;

    // helper function to check for duplicate insults, if duplicate is found a new insult is generated to replace it
    void checkDuplicates(vector<string> insults);
};

// class to throw errors when provided with an invalid number of insults
class NumInsultsOutOfBounds {
public:
	// construct exception with the specified error message
    NumInsultsOutOfBounds(const string& message);

    // method to display the error message
    string& what(void);
private:
    string message;
};
