#include "readInput.h"
#include "TruckPack.h"
#include "customer.h"
#include "initialRoute.h"
#include <iostream>

using namespace std;

// typedef pair<int,int> mypair;
// bool comparator ( const mypair& l, const mypair& r)
// 	{ return l.first > r.first; }

int main(){

	// ******CHANGE FILE HERE**********

	readInput reader;
	string filename = "2L-CVRP test instances/2l_cvrp0101.txt";
	reader.readInputFile(filename);
	//reader.printData();


	TruckPack packing;
	//packing.initialize(20,40);
	// vector<int> widths;
	// vector<int> lengths;

	initialRoute route(reader.numvehicles, reader.customers);
	if (route.generateRoutes() == 1){
		cout << "solution found" << endl;
	} else {
		cout << "solution NOT found" << endl;
	}
	//route.printRoutes();

	// packing.insert(9,19);
	// packing.insert(3,36);
	// packing.printTree("results.txt");

	// vector< pair<int,int> > v;

	// for (int i = 0; i < (int)reader.widths.size(); ++i){
	// 	v.push_back(make_pair(reader.widths[i]*reader.lengths[i],i));
	// }


	// sort(v.begin(), v.end(), comparator);

	// // for (int i = 0; i < (int)v.size(); ++i)
	// // {
	// // 	cout << v[i].first << endl;
	// // }

	// for (int i = 0; i < (int)v.size(); ++i){
	// 	//cout << v[i].first << endl;
	// 	packing.insert(reader.widths[v[i].second], reader.lengths[v[i].second]);
	// }

	// for (int i = 0; i < reader.numcustomers; ++i)
	// {
	// 	cout << "customer " << i << ": ";
	// 	cout << reader.customers[i].x << " " << reader.customers[i].y << " " << reader.customers[i].weight << " (" << reader.customers[i].totalarea << ")" << endl;
	// 	cout << "items" << endl;
	// 	for (int j = 0; j < (int)reader.customers[i].items.size(); ++j)
	// 	{
	// 		cout << "\t" << reader.customers[i].items[j].width << " " << reader.customers[i].items[j].length << " " << reader.customers[i].items[j].area << endl;
	// 	}
	// }

	//packing.printTree("results.txt");

	// for (int i = 0; i < (int)reader.weights.size(); ++i){
	// 	cout << reader.weights[i] << endl;
	// }

}