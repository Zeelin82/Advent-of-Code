#include "pch.h"
#include "FirstDecember.h"


FirstDecember::FirstDecember()
{
}


FirstDecember::~FirstDecember()
{
}

void FirstDecember::PartOne() {
	std::ifstream file = FileReader::OpenFile("../FirstDecember/FirstDecember.txt");
	std::string line = "";
	int frequency = 0;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			int amount = 1;
			if (line[0] == '+') {
				line.erase(0, 1);
			}
			else {
				line.erase(0, 1);
				amount = -1;
			}
			amount *= std::stoi(line);
			frequency += amount;
		}
		file.close();
	}
	std::cout << frequency;
}

void FirstDecember::PartTwo() {
	std::ifstream file = FileReader::OpenFile("../FirstDecember/FirstDecember.txt");
	std::string line = "";
	int frequency = 0;
	std::vector<int> frequencyChange;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			int amount = 1;
			if (line[0] == '+') {
				line.erase(0, 1);
			}
			else {
				line.erase(0, 1);
				amount = -1;
			}
			frequencyChange.push_back(amount *= std::stoi(line));
		}
		file.close();
	}
	bool found = false;
	std::set<int> visitedFrequencies;
	visitedFrequencies.insert(0);
	while (!found) {
		for (int i = 0; i < frequencyChange.size(); i++) {
			frequency += frequencyChange[i];
			if (visitedFrequencies.find(frequency) == visitedFrequencies.end()) {
				visitedFrequencies.insert(frequency);
			}
			else {
				found = true;
				break;
			}
		}
	}
	std::cout << frequency;
}
