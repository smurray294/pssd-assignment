#include <vector>
#include <iostream>
#include "customer.h"
#include "bpInterface.h"

class initialRoute{
private:


public:
	bool generateRoutes();
	void printRoutes();
	void printItems();
	void printRoutesOF();

	initialRoute(int numTrucks, int cap, std::vector<customer> myCusts, double areaMult);

	struct route{
		std::vector<customer> customers;
		int freeArea;
		int currWeight;
		int numItems;
	};

	// std::vector< pair<int,int> > areas;
	// std::vector<int> weights;
	std::vector<customer> customers;
	int trucks;
	int capacity;
	std::vector<route> routes;

	// double areaW;
	// double weightW;

	bool failed;

};