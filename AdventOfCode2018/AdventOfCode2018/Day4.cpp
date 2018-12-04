#include "pch.h"
#include "Day4.h"


Day4::Day4()
{
}


Day4::~Day4()
{
}

void Day4::PartOne() {
	std::ifstream file = FileReader::OpenFile("../Input/Day4.txt");
	std::string line = "";
	std::list<GuardEvent> guardEvents;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			GuardEvent g = line;
			guardEvents.push_back(g);
		}
		file.close();
	}
	guardEvents.sort();

	//store the sleeping guard schedule in sleeping guards
	std::set<Guard> sleepingGuards;
	GuardEvent e;
	int guardId;
	bool allEvents = false;
	while (!allEvents) {
		e = guardEvents.front();
		guardEvents.pop_front();
		if (e.guardEvent[0] == 'G') {
			std::vector<std::string> input;
			boost::split(input, e.guardEvent, boost::is_any_of(" "));
			guardId = std::stoi(input[1].erase(0, 1));
			sleepingGuards.insert(Guard(guardId));
			sleepingGuards.find(guardId)->sleeping.push_back(std::vector<int>(60));
		}
		else if (e.guardEvent[0] == 'f') {
			std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
			guard->fellAsleep = e.time;
		}
		else if (e.guardEvent[0] == 'w') {
			std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
			for (int i = guard->fellAsleep; i < e.time; i++) {
				guard->sleeping[guard->sleeping.size() - 1][i] = 1;
			}
		}
		if (guardEvents.size() == 0) {
			allEvents = true;
		}
	}

	//find the sleepiest guard
	int maxSleepTime = 0;
	for (auto g : sleepingGuards) {
		int time = 0;
		for (int i = 0; i < g.sleeping.size(); i++) {
			for (int j = 0; j < g.sleeping[i].size(); j++) {
				if (g.sleeping[i][j] == 1) {
					time++;
				}
			}
		}
		if (time > maxSleepTime) {
			maxSleepTime = time;
			guardId = g.id;
		}
	}

	//find all times the guard sleept
	std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
	std::vector<int> mostSleepyTimes(60);
	sleepingGuards.find(guardId);
	for (int i = 0; i < guard->sleeping.size(); i++) {
		for (int j = 0; j < guard->sleeping[i].size(); j++) {
			if (guard->sleeping[i][j] == 1) {
				mostSleepyTimes[j]++;
			}
		}
	}
	
	//find the sleepiest time
	int time = 0;
	int mostSleepyTime = 0;
	for (int i = 0; i < mostSleepyTimes.size(); i++) {
		if (mostSleepyTimes[i] > time) {
			time = mostSleepyTimes[i];
			mostSleepyTime = i;
		}
	}
	std::cout << guard->id << " " << mostSleepyTime << " " << guard->id*mostSleepyTime;
}

void Day4::PartTwo() {
	std::ifstream file = FileReader::OpenFile("../Input/Day4.txt");
	std::string line = "";
	std::list<GuardEvent> guardEvents;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			GuardEvent g = line;
			guardEvents.push_back(g);
		}
		file.close();
	}
	guardEvents.sort();

	//Store the minutes that each guard has sleept for each minute
	std::set<Guard> sleepingGuards;
	GuardEvent e;
	int guardId;
	bool allEvents = false;
	while (!allEvents) {
		e = guardEvents.front();
		guardEvents.pop_front();
		if (e.guardEvent[0] == 'G') {
			std::vector<std::string> input;
			boost::split(input, e.guardEvent, boost::is_any_of(" "));
			guardId = std::stoi(input[1].erase(0, 1));
			Guard guard(guardId);
			if (guard.sleeping.size() == 0) {
				guard.sleeping.push_back(std::vector<int>(60));
			}
			sleepingGuards.insert(guard);
			
		}
		else if (e.guardEvent[0] == 'f') {
			std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
			guard->fellAsleep = e.time;
			if (guard->sleeping.size() == 0) {
				guard->sleeping.push_back(std::vector<int>(60));
			}
		}
		else if (e.guardEvent[0] == 'w') {
			std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
			for (int i = guard->fellAsleep; i < e.time; i++) {
				guard->sleeping[0][i]++;
			}
		}
		if (guardEvents.size() == 0) {
			allEvents = true;
		}
	}

	//find the sleepiest guard on a single minute
	int maxSleepTime = 0;
	for (auto g : sleepingGuards) {
		for (int i = 0; i < g.sleeping[0].size(); i++) {
			if (g.sleeping[0][i] > maxSleepTime) {
				maxSleepTime = g.sleeping[0][i];
				guardId = g.id;
			}
		}
	}

	//find the sleepiest time
	std::set<Guard>::iterator guard = sleepingGuards.find(guardId);
	int mostSleepyTime = 0;
	int time = 0;
	for (int i = 0; i < guard->sleeping[0].size(); i++) {
		if (guard->sleeping[0][i] > time) {
			time = guard->sleeping[0][i];
			mostSleepyTime = i;
		}
	}
	std::cout << guard->id << " " << mostSleepyTime << " " << guard->id*mostSleepyTime;
}
