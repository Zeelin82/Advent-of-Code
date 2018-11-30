#include "pch.h"
#include "FirstDecember.h"



FirstDecember::FirstDecember()
{
}


FirstDecember::~FirstDecember()
{
}

void FirstDecember::PartOne() {
	std::ifstream file = FileReader::OpenFile("../FirstDecember/firstDecember.txt");
	std::string input = "";
	std::string line;
	if (file.is_open()) {
		while ( std::getline (file, line)) {
			input += line;
		}
		file.close();
	}
	int totalValue = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == input[((i + 1) % input.length())]) {
			totalValue += (static_cast<int>(input[i]) - 48);
		}
	}
	std::cout << totalValue << "\n";
}

void FirstDecember::PartTwo() {
	std::ifstream file = FileReader::OpenFile("../FirstDecember/firstDecember.txt");
	std::string input = "";
	std::string line;
	if (file.is_open()) {
		while (std::getline(file, line)) {
			input += line;
		}
		file.close();
	}
	int totalValue = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == input[((i + input.length() / 2) % input.length())]) {
			totalValue += (static_cast<int>(input[i]) - 48);
		}
	}
	std::cout << totalValue;
}