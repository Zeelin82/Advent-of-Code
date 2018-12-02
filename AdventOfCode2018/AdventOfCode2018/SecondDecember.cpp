#include "pch.h"
#include "SecondDecember.h"


SecondDecember::SecondDecember()
{
}


SecondDecember::~SecondDecember()
{
}

void SecondDecember::PartOne() {
	std::ifstream file = FileReader::OpenFile("../SecondDecember/SecondDecember.txt");
	int twoTimes = 0;
	int ThreeTimes = 0;
	std::string line;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::sort(line.begin(), line.end());
			char previousChar = line[0];
			int firstIndexOfChar = 0;
			bool twice = false;
			bool thrice = false;
			for (int i = 1; i <= line.length(); i++) {
				if (previousChar != line[i % line.length()]) {
					if ((i - firstIndexOfChar) == 2 ) {
						twice = true;
					}
					else if ((i - firstIndexOfChar) == 3) {
						thrice = true;
					}
					previousChar = line[i];
					firstIndexOfChar = i;
				}
			}
			if (twice) {
				twoTimes++;
			}
			if (thrice) {
				ThreeTimes++;
			}
			std::cout << line << " " << twoTimes << " " << ThreeTimes << "\n";
		}
		file.close();
	}
	std::cout << twoTimes * ThreeTimes;
}

void SecondDecember::PartTwo() {
	std::ifstream file = FileReader::OpenFile("../SecondDecember/SecondDecember.txt");
	std::string line;
	std::list<std::string> boxes;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			boxes.push_back(line);
		}
		bool found = false;
		while (!found) {
			std::string box = boxes.front();
			boxes.pop_front();
			int matchingBoxes = 0;
			for (auto boxCompare : boxes) {
				int NotMatching = 0;
				for (int i = 0; i < box.length(); i++) {
					if (box[i] != boxCompare[i]) {
						NotMatching++;
					}
					if (NotMatching > 1) {
						break;
					}
				}
				if (NotMatching <= 1) {
					matchingBoxes++;
				}
			}
			if (matchingBoxes > 0) {
				boxes.push_back(box);
			}
			if (boxes.size() == 2) {
				found = true;
			}
		}
		file.close();
		std::string firstBox = boxes.front();
		std::string secondBox = boxes.back();
		for (int i = 0; i < firstBox.size(); i++) {
			if (firstBox[i] == secondBox[i]) {
				std::cout << firstBox[i];
			}
		}
	}
}