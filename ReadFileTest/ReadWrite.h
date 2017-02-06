#ifndef READWRITE_H
#define READWRITE_H

#include <string>

class ReadWrite
{
public:
	void Read();
	void Write();
	bool IsIsogram(std::string);
	int Error();

private:
	std::string Word; // Word for analysis
	std::string File; // Isogram File Output
};



#endif // READWRITE_H