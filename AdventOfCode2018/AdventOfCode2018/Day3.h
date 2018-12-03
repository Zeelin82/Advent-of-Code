#pragma once
#include "FileReader.h"
#include <string>
#include <set>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>

class Claim {
private:
	int id;
	int x;
	int y;
	int width;
	int height;
public:
	Claim() {};
	Claim(int id, int x, int y, int width, int height) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	~Claim() {}

	int getId() { return id; }
	int getX() { return x; }
	int getY() { return y; }
	int getWidth() { return width; }
	int getHeight() { return height; }
};

struct Point { int x, y; };

class Day3
{
private:
	static std::map<std::string, int> split(std::string incommingString);
	static bool doClaimOverlap(Claim a, Claim b);
public:
	Day3();
	~Day3();

	static void PartOne();
	static void PartTwo();
};

