#include "pch.h"
#include "Day5.h"


Day5::Day5()
{
}


Day5::~Day5()
{
}

void Day5::PartOne() {
	std::vector<std::string> file = FileReader::GetFile("../Input/Day5.txt");
	std::string polymer;
	for (auto row : file) {
		polymer += row;
	}
	std::string a;
	std::string b;
	for (int i = 0; i < polymer.length() - 1; i++) {
		a = polymer[i];
		b = polymer[i + 1];
		if (boost::iequals(a, b)) {
			if (a != b) {
				polymer.erase(i, 2);
				if (i > 0) {
					i = i - 2;
				}
				else {
					i = i - 1;
				}
			}
		}
	}
	std::cout << polymer.size();
}

void Day5::PartTwo() {
	std::vector<std::string> file = FileReader::GetFile("../Input/Day5.txt");
	std::string polymer;
	for (auto row : file) {
		polymer += row;
	}
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string removedLetter;
	int testSize = polymer.size();

	for (int i = 0; i < alphabet.size(); i++) {
		std::string testString = "";
		for (int j = 0; j < polymer.size(); j++) {
			testString.push_back(polymer[j]);
		}
		std::string letter(1, alphabet[i]);
		std::string a;
		std::string b;
		for (int k = 0; k < testString.length() - 1; k++) {
			a = testString[k];
			b = testString[k + 1];
			
			if (boost::iequals(a, letter))
			{
				testString.erase(k, 1);
				if (k > 0) {
					k = k - 2;
				}
				else {
					k--;
				}
			}
			else {
				if (boost::iequals(a, b)) {
					if (a != b) {
						testString.erase(k, 2);
						if (k > 0) {
							k = k - 2;
						}
						else {
							k = k - 1;
						}
					}
				}
			}
		}
		if (testString.size() < testSize) {
			testSize = testString.size();
			removedLetter = (1, alphabet[i]);
		}
		std::cout << alphabet[i];
	}
	
	std::cout << " " << testSize << " " << removedLetter;
}
