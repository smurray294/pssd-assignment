#include "initialRoute.h"
#include "TruckPack.h"

using namespace std;

double areaW = 0.2;
double weightW = 1.0-areaW;

//typedef pair<int,int> mypair;
// bool comparator ( const mypair& l, const mypair& r){
// 	return (l.first*areaW + weights[l.second]*weightW) > (r.first*areaW + weights[r.second]*weightW); 
// }
bool comparator ( const customer& l, const customer& r){
	return (l.totalarea*areaW + l.weight*weightW) > (r.totalarea*areaW + r.weight*weightW); 
}

bool areacomparator ( const customer& l, const customer& r){
	return (l.totalarea) > (r.totalarea); 
}


initialRoute::initialRoute(int numTrucks, vector<customer> myCusts){
	trucks = numTrucks;

	for (int i = 0; i < trucks; ++i){
		routes.push_back(route());
		routes[i].freeArea = 800;
		routes[i].currWeight = 0;
		routes[i].numItems = 0;
	}

	customers=myCusts;
	sort(customers.begin(), customers.end(), comparator);
	// remove depot
	customers.pop_back();
}

bool initialRoute::generateRoutes(){
	// feasibility of inserting a customer i into every position of every route
	// is tested

	// loop through customers
	for (int icusts = 0; icusts < (int)customers.size(); ++icusts)
	{
		// loop through routes
		int minarea = 800;
		int minareai = -1;
		int temparea;
		failed = 1;
		for (int iroutes = 0; iroutes < trucks; ++iroutes)
		{
			//temparea = routes[iroutes].freeArea - areas[icusts].first;
			temparea = routes[iroutes].freeArea - customers[icusts].totalarea;
			if (temparea < minarea && temparea >= 0){
				// check weight

				if ((routes[iroutes].currWeight + customers[icusts].weight) <= 90){
					// minarea = temparea;
					// minareai = iroutes;
					// failed = 0;
					vector<customer> temp = routes[iroutes].customers;
					temp.push_back(customers[icusts]);
					sort(temp.begin(), temp.end(), areacomparator);
					TruckPack feasible;
					if (feasible.feasiblePack(temp) == 0){
						
					} else {
						failed = 0;
						routes[iroutes].currWeight += customers[icusts].weight;
						routes[iroutes].freeArea -= customers[icusts].totalarea;
						routes[iroutes].customers.push_back(customers[icusts]);
						routes[iroutes].numItems += customers[icusts].items.size();
						break;
					}			
				}
			}
		}

		if (failed == 1){
			return 0;
		}

		// add and update route
		// if (failed == 0){
		// 	vector<customer> temp = routes[minareai].customers;
		// 	temp.push_back(customers[icusts]);
		// 	sort(temp.begin(), temp.end(), areacomparator);
		// 	TruckPack feasible;
		// 	if (feasible.feasiblePack(temp) == 0){
		// 		cout << "failed packing" << endl;
		// 	}

		// 	routes[minareai].currWeight += customers[icusts].weight;
		// 	routes[minareai].freeArea -= customers[icusts].totalarea;
		// 	routes[minareai].customers.push_back(customers[icusts]);
		// 	routes[minareai].numItems += customers[icusts].items.size();
		// } else {
		// 	cout << "failed" << endl;
		// }
	}

	return 1;
}

void initialRoute::printRoutes(){
	for (int i = 0; i < trucks; ++i)
	{
		cout << "truck " << i << " total weight: " << routes[i].currWeight << " num items: " << routes[i].numItems << endl;
		for (int j = 0; j < (int)routes[i].customers.size(); ++j)
		{
			cout << routes[i].customers[j].id << " " << "weight: " << routes[i].customers[j].weight << " total area: " << routes[i].customers[j].totalarea << endl;
		}
	}

	TruckPack test;
	test.feasiblePack(routes[0].customers);
}
