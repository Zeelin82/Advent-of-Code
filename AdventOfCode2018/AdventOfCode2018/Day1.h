#pragma once
#include "FileReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <set>
class Day1
{
private:
	void AddToFrequency(int &frequency, int &amount);
public:
	Day1();
	~Day1();
	static void PartOne();
	static void PartTwo();
};

