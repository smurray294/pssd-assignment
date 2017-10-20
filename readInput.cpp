#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "readInput.h"

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
	int tempwidth;
	int templength;

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
				}
			} else if (nodecount == 2){
				for (int i = 0; i <= numcustomers; ++i){
					getline(inFile,line);
					customeritems.push_back(line);
					iss.str(line);
					iss >> temp1 >> temp2;
					for (int i = 0; i < temp2; ++i){
						iss >> tempwidth >> templength;
						widths.push_back(tempwidth);
						lengths.push_back(templength);
					}
				}
			}
		}
	}
}


void readInput::printData(){
	cout << "Instance:\t" << instance << endl;
	cout << "Class:\t" << numclass << endl;
	cout << "Customers:\t" << numcustomers << endl;
	cout << "Vehicles:\t" << numvehicles << endl;
	cout << "Items:\t" << numitems << endl;
	cout << "Vehicle stats:\t" << vehiclecap << " " << vehiclel << " " << vehiclew << endl;

	for (int i = 0; i < (int)customerlocdemand.size(); ++i){
		cout << customerlocdemand[i] << endl; 
	}

	for (int i = 0; i < (int)customeritems.size(); ++i){
		cout << customeritems[i] << endl; 
	}

}