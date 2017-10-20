#ifndef READINPUT_H
#define READINPUT_H

#include <vector>
#include <string>

class readInput{
private:
	std::string instance;

	int numclass;
	int numcustomers;
	int numvehicles;
	int numitems;

	int vehiclecap;
	int vehiclel;
	int vehiclew;

	std::vector<std::string> customerlocdemand;
	std::vector<std::string> customeritems;


public:
	void readInputFile(std::string filename);

	void printData();

	std::vector<int> widths;
	std::vector<int> lengths;
};

#endif