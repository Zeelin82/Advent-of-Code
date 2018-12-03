#pragma once
#include "FileReader.h"
#include <string>
#include <set>
#include <vector>
#include <unordered_set>
#include <boost/algorithm/string.hpp>

class Day3
{
public:
	Day3();
	~Day3();
	static std::vector<int> split(std::string incommingString);
	static void PartOne();
};

