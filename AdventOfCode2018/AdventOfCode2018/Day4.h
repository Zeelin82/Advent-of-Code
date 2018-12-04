#pragma once
#include "FileReader.h"
#include <string>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <map>

class Day4
{
public:
	Day4();
	~Day4();
	static void PartOne();
	static void PartTwo();
};

class GuardEvent {
public:
	GuardEvent() {};
	GuardEvent(std::string line) {
		std::string lineDate = line.substr(1, 10);
		std::string lineTime = line.substr(12, 5);
		this->date = std::stoi(lineDate.erase(4, 1).erase(6, 1));
		this->time = std::stoi(lineTime.erase(2, 1));
		this->guardEvent = line.substr(19, line.size());
		//std::cout << lineDate << " " << lineTime << " " << guardEvent;
	}
	~GuardEvent() {};
	int date;
	int time;
	std::string guardEvent;
	bool operator < (const GuardEvent& timeEvent) const {
		if (date < timeEvent.date) { return true; }
		else if (date == timeEvent.date) { return (time < timeEvent.time); }
		else { return false; }
	}
};

class Guard {
public:
	Guard() {};
	~Guard() {};
	Guard(int id) {
		this->id = id;
		this->fellAsleep = 0;
	}
	int id;
	mutable std::vector<std::vector<int>> sleeping;
	mutable int fellAsleep;
	bool operator < (const Guard& guard) const {
		return (id < guard.id);
	}
};
