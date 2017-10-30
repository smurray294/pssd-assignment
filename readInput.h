#ifndef READINPUT_H
#define READINPUT_H

#include <vector>
#include <string>
#include "customer.h"

class readInput{
private:
	std::string instance;

	int numclass;

	int numitems;

	int vehiclecap;
	int vehiclel;
	int vehiclew;

	std::vector<std::string> customerlocdemand;
	std::vector<std::string> customeritems;



public:
	void readInputFile(std::string filename);

	void printData();

	std::vector<customer> customers;
	int numcustomers;
	int numvehicles;

	std::vector<int> widths;
	std::vector<int> lengths;
	std::vector<double> weights;
};

#endif