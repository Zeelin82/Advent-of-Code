#include "pch.h"
#include "Day3.h"


Day3::Day3()
{
}


Day3::~Day3()
{
}

std::vector<int> Day3::split(std::string incommingString) {
	std::vector<std::string> input;
	boost::split(input, incommingString, boost::is_any_of(" "));
	
	//remove :
	input[2].erase(input[2].length() - 1, input[2].length());
	
	//split position
	std::vector<std::string> position;
	boost::split(position, input[2], boost::is_any_of(","));

	//split size
	std::vector<std::string> size;
	boost::split(size, input[3], boost::is_any_of("x"));

	int id = std::stoi(input[0].erase(0, 1));
	int x = std::stoi(position[0]);
	int y = std::stoi(position[1]);
	int width = std::stoi(size[0]);
	int height = std::stoi(size[1]);
	std::vector<int> output = {id, x, y, width, height};

	return output;
}

void Day3::PartOne() {
	std::ifstream file = FileReader::OpenFile("../Input/Day3.txt");
	std::string line;
	std::set<int> fabric;
	std::set<int> overlap;
	std::pair<std::set<int>::iterator, bool> ret;
	std::vector<int> input;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			input = split(line);
			for 
			
		}
		file.close();
	}
}