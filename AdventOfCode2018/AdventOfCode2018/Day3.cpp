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
	auto before = std::chrono::high_resolution_clock::now();
	
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
	auto after = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration<double>(after - before);
	printf("Time taken: %fs \n", delta.count());
}

bool Day3::doClaimOverlap(Claim a, Claim b) {
	Point aTopLeft = { a.getX(), a.getY() };
	Point aBottomRight = { a.getX() + a.getWidth() - 1, a.getY() + a.getHeight() - 1 };
	Point bTopLeft = { b.getX(), b.getY() };
	Point bBottomRight = { b.getX() + b.getWidth() - 1, b.getY() + b.getHeight() - 1 };

	if (aTopLeft.x > bBottomRight.x || bTopLeft.x > aBottomRight.x) {
		return false;
	}
	if (aTopLeft.y > bBottomRight.y || bTopLeft.y > aBottomRight.y) {
		return false;
	}
	return true;
}

void Day3::PartTwo() {
	auto before = std::chrono::high_resolution_clock::now();
	std::ifstream file = FileReader::OpenFile("../Input/Day3.txt");
	std::string line;
	std::vector<Claim> claims;
	std::map<std::string, int> input;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			input = split(line);
			Claim claim = { input["id"], input["x"], input["y"], input["width"], input["height"] };
			claims.push_back(claim);
		}
		file.close();
	}
	Claim claim;
	int i = 0;
	bool found = false;
	while (!found && i < claims.size()) {
		int overlap = 0;
		for (int j = 0; j < claims.size(); j++) {
			if (claims[i].getId() != claims[j].getId()) {
				if (doClaimOverlap(claims[i], claims[j])) {
					overlap++;
				}
			}
		}
		if (overlap == 0) {
			claim = claims[i];
			found = true;
		}
		i++;
	}
	std::cout << i << " " << claim.getId();
	auto after = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration<double>(after - before);
	printf("Time taken: %fs \n", delta.count());
}
