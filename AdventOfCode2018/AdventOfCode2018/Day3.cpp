#include "pch.h"
#include "Day3.h"


Day3::Day3()
{
}


Day3::~Day3()
{
}

std::map<std::string, int> Day3::split(std::string incommingString) {
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

	std::map<std::string, int> output;
	output["id"] = std::stoi(input[0].erase(0, 1));
	output["x"] = std::stoi(position[0]);
	output["y"] = std::stoi(position[1]);
	output["width"] = std::stoi(size[0]);
	output["height"] = std::stoi(size[1]);

	return output;
}

void Day3::PartOne() {
	std::ifstream file = FileReader::OpenFile("../Input/Day3.txt");
	std::string line;
	std::set<std::string> fabric;
	std::set<std::string> overlap;
	std::map<std::string, int> input;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			input = split(line);
			for (int i = 0; i < input["height"]; i++) {
				for (int j = 0; j < input["width"]; j++) {
					int x = input["x"] + j;
					int y = input["y"] + i;
					std::string coordinate = std::to_string(x) + "," + std::to_string(y);

					if (!fabric.insert(coordinate).second) {
						overlap.insert(coordinate);
					}
				}
			}
		}
		file.close();
	}
	std::cout << overlap.size();
}
