#include "pch.h"
#include "FileReader.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

std::ifstream FileReader::OpenFile(std::string filePath) {
	std::ifstream inFile;
	inFile.open(filePath);
	if (!inFile) {
		std::cerr << "unable to open file.";
	}
	return inFile;
}