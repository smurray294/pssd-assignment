#include <vector>
#include <iostream>
#include "customer.h"

class initialRoute{
private:


public:
	bool generateRoutes();
	void printRoutes();

	initialRoute(int numTrucks, std::vector<customer> myCusts);

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
	std::vector<route> routes;

	// double areaW;
	// double weightW;

	bool failed;

};