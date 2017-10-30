#include <vector>
#include <iostream>
#include "customer.h"

class initialRoute{
private:

	void generateRoutes();
	void printRoute();
public:

	initialRoute(int numTrucks, std::vector<customer> myCusts);

	struct route{
		std::vector<customer> customers;
		int freeArea;
		int currWeight;
	};

	// std::vector< pair<int,int> > areas;
	// std::vector<int> weights;
	std::vector<customer> customers;
	int trucks;
	std::vector<route> routes;

	double areaW;
	double weightW;

	bool failed = 0;

};