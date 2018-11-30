#pragma once
#include <fstream>
#include <iostream>
class FileReader
{
public:
	FileReader();
	~FileReader();
	static std::ifstream OpenFile(std::string filePath);
};

