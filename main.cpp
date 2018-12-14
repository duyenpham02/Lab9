// main.cpp
// Duyen Pham
// COSC 2030 - 01
// Lab09
// Dec 2, 2018

#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::getline;
using std::string;
using std::ifstream;
using std::ofstream;

string promptUser(void);
void readText(ifstream& inFile);
void writeText(ofstream& outFile, string data);

int main()
{
	ifstream inFile;
	ofstream outFile;
	string fileName;
	int sum = 0;
	string data;

	// Get the file name and store it
	fileName = promptUser();

	// Attempt to open the file
	inFile.open(fileName.c_str());

	if (!inFile)
	{
		cerr << "File: \"" << fileName << "\" cannot be opened." << endl;
		exit(1);
	}

	readText(inFile);
	writeText(outFile, data);

	inFile.close();


	cout << "The sum is " << sum << endl;

	return 0;
}

string promptUser(void)
{
	string file;

	cout << "\n\nEnter name of input file: ";
	getline(cin, file);

	return file;
}

void readText(ifstream& inFile)
{
	string input;

	while (!inFile.eof())
	{
		getline(inFile, input);
		//integers.push_back(stoi(input));

		cout << input << endl;
	}
}

void writeText(ofstream& outFile, string data)
{
	outFile.open("output.txt");

	cout << "Writing to a file" << endl;
	cout << "Enter whatever: ";
	getline(cin, data);

	outFile << data << endl;

	outFile.close();
}




