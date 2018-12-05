#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
class FileReader
{
public:
	FileReader();
	~FileReader();
	static std::ifstream OpenFile(std::string filePath);
	static std::vector<std::string> GetFile(std::string filePath);
};

