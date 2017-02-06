#include "stdafx.h"
#include "ReadWrite.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

//ReadWrite::ReadWrite() {} // Default Constructor

int ReadWrite::Error() { return -1; }

// Reads from File, sorts by Isogram, passes to writer
void ReadWrite::Read()
{
	std::string Name;
	getline(std::cin, Name);
	std::ifstream reader(Name + ".txt");

	if (!reader)
	{
		std::cout << "Error reading the input file." << std::endl;
		std::cout << "Please check that the file exists or is not open by another program." << std::endl;
		Error();
	}

	while (!reader.eof())
	{
		getline(reader, Word, '\n');
		if (IsIsogram(Word))
		{
			File.append(Word + "\n");
		}
		else
		{
			std::cout << Word << " is not an isogram." << std::endl;
		}
	}

	return;
}

// Writes to the File
void ReadWrite::Write()
{
	std::cout << "Please enter the name of the output file to store the Isograms: ";
	std::string Name;
	getline(std::cin, Name);

	std::ofstream writer(Name + ".txt", std::ios::app);

	if (!writer)
	{
		std::cout << "Error writing to file." << std::endl;
		std::cout << "Please check that the file exists or is not open by another program." << std::endl;
		Error();
	}

	writer << File << std::endl;
	writer.close();

	return;
}


// Returns true or false whether word is isogram or not
bool ReadWrite::IsIsogram(std::string Word)
{
	if (Word.length() <= 1) { return true; } // sorter considers 0 and 1 letter words to be isograms as the letters 
											 // obviosuly do not repeat and instead a more meaningful error is given (see CheckGuessValidity() )
	std::map<char, bool> LetterSeen; // Setup map
	for (auto Letter : Word)	// For all letters of the word
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}




