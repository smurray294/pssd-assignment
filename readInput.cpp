#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "readInput.h"
#include "customer.h"
#include "initialRoute.h"

using namespace std;
	
void readInput::readInputFile(string filename){
	ifstream inFile(filename.c_str());
	string line;

	// check file opened
	if (!inFile){
		cerr << "unable to open file";
		exit(1); // call system to stop
	}

	string firstWord = "";
	int nodecount = 0;

	int temp1;
	int temp2;
	int temp1d;
	double temp2d;
	double temp3d;
	double tempwidth;
	int templength;
	int tempweight;

	istringstream iss;
	// read file line by line
	while (getline(inFile,line)){
		firstWord = line.substr(0, line.find(" "));

		if (firstWord == "Instance:"){
			instance = line.substr(line.find(" "), line.length());

		} else if (firstWord == "Class:"){
			numclass = atoi(line.substr(line.find(" "), line.length()).c_str());
			getline(inFile,line);
			iss.str(line);
			iss >> numcustomers;
			// initialise customers
			for (int i = 0; i <= numcustomers; ++i){
				customers.push_back(customer());
			}
			getline(inFile,line);
			iss.str(line);
			iss >> numvehicles;
			getline(inFile,line);
			iss.str(line);
			iss >> numitems;
		} else if (firstWord == "Capacity"){
			getline(inFile,line);
			iss.str(line);
			iss >> vehiclecap >> vehiclel >> vehiclew;
		} else if (firstWord == "Node"){
			nodecount++;
			if (nodecount == 1){

				for (int i = 0; i <= numcustomers; ++i){
					getline(inFile,line);
					customerlocdemand.push_back(line);
					iss.str(line);
					iss >> temp1d >> temp2d >> temp3d >> tempweight;
					weights.push_back(tempweight);
					customers[temp1d].id = temp1d;
					customers[temp1d].x = temp2d;
					customers[temp1d].y = temp3d;
					customers[temp1d].weight = tempweight;
				}
			} else if (nodecount == 2){
				int itemid = 0;
				for (int i = 0; i <= numcustomers; ++i){
					getline(inFile,line);
					customeritems.push_back(line);
					iss.str(line);
					
					iss >> temp1 >> temp2;
					customers[temp1].numitems = temp2;
					for (int i = 0; i < temp2; ++i){
						iss >> templength >> tempwidth;
						widths.push_back(tempwidth);
						lengths.push_back(templength);
						customers[temp1].add_item(templength, tempwidth, itemid);
						itemid++;
						customers[temp1].totalarea += customers[temp1].items[i].area;
					}
					customers[temp1].sort_items();
				}
			}
		}
	}
}


void readInput::printDataOF(double obj){
	cout << "Instance: " << instance << endl;
	cout << "Class: " << numclass << endl;
	cout << "Objective value: " << obj << endl;
	cout << "Number of vehicles: " << numvehicles << endl;


}