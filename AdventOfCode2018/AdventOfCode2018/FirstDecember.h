#pragma once
#include "FileReader.h"
#include <fstream>
#include <string>
#include <vector>
#include <set>
class FirstDecember
{
private:
	void AddToFrequency(int &frequency, int &amount);
public:
	FirstDecember();
	~FirstDecember();
	static void PartOne();
	static void PartTwo();
};

