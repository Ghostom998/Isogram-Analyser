// ReadFileTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include "ReadWrite.h"
#include <string>
#include <iostream>

using namespace std;

void Intro();

ReadWrite Isogram;

int main()
{
	Intro();
	Isogram.Read();
	Isogram.Write();
    return 0;
}


void Intro() 
{
	std::cout << "Welcome to the Anagram Analyser. \n";
	std::cout << "The program will process a .txt file of words seperated with a newline.\n\n";
	std::cout << "Please enter the name of the text file you wish to analyse (*.txt): ";
	return;
}
