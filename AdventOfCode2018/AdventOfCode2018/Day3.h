#pragma once
#include "FileReader.h"
#include <string>
#include <set>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>

class Day3
{
private:
	static std::map<std::string, int> split(std::string incommingString);
public:
	Day3();
	~Day3();

	static void PartOne();
};

