#include "readInput.h"
#include "TruckPack.h"
#include "customer.h"
#include "initialRoute.h"
#include <iostream>
#include <sstream>

using namespace std;

// typedef pair<int,int> mypair;
// bool comparator ( const mypair& l, const mypair& r)
// 	{ return l.first > r.first; }

//"2l_cvrp0101.txt 2l_cvrp0802.txt 2l_cvrp1503.txt 2l_cvrp2204.txt 2l_cvrp2905.txt 2l_cvrp0102.txt 2l_cvrp0803.txt 2l_cvrp1504.txt 2l_cvrp2205.txt 2l_cvrp3001.txt 2l_cvrp0103.txt 2l_cvrp0804.txt 2l_cvrp1505.txt 2l_cvrp2301.txt 2l_cvrp3002.txt 2l_cvrp0104.txt 2l_cvrp0805.txt 2l_cvrp1601.txt 2l_cvrp2302.txt 2l_cvrp3003.txt 2l_cvrp0105.txt 2l_cvrp0901.txt 2l_cvrp1602.txt 2l_cvrp2303.txt 2l_cvrp3004.txt 2l_cvrp0201.txt 2l_cvrp0902.txt 2l_cvrp1603.txt 2l_cvrp2304.txt 2l_cvrp3005.txt 2l_cvrp0202.txt 2l_cvrp0903.txt 2l_cvrp1604.txt 2l_cvrp2305.txt 2l_cvrp3101.txt 2l_cvrp0203.txt 2l_cvrp0904.txt 2l_cvrp1605.txt 2l_cvrp2401.txt 2l_cvrp3102.txt 2l_cvrp0204.txt 2l_cvrp0905.txt 2l_cvrp1701.txt 2l_cvrp2402.txt 2l_cvrp3103.txt 2l_cvrp0205.txt 2l_cvrp1001.txt 2l_cvrp1702.txt 2l_cvrp2403.txt 2l_cvrp3104.txt 2l_cvrp0301.txt 2l_cvrp1002.txt 2l_cvrp1703.txt 2l_cvrp2404.txt 2l_cvrp3105.txt 2l_cvrp0302.txt 2l_cvrp1003.txt 2l_cvrp1704.txt 2l_cvrp2405.txt 2l_cvrp3201.txt 2l_cvrp0303.txt 2l_cvrp1004.txt 2l_cvrp1705.txt 2l_cvrp2501.txt 2l_cvrp3202.txt 2l_cvrp0304.txt 2l_cvrp1005.txt 2l_cvrp1801.txt 2l_cvrp2502.txt 2l_cvrp3203.txt 2l_cvrp0305.txt 2l_cvrp1101.txt 2l_cvrp1802.txt 2l_cvrp2503.txt 2l_cvrp3204.txt 2l_cvrp0401.txt 2l_cvrp1102.txt 2l_cvrp1803.txt 2l_cvrp2504.txt 2l_cvrp3205.txt 2l_cvrp0402.txt 2l_cvrp1103.txt 2l_cvrp1804.txt 2l_cvrp2505.txt 2l_cvrp3301.txt 2l_cvrp0403.txt 2l_cvrp1104.txt 2l_cvrp1805.txt 2l_cvrp2601.txt 2l_cvrp3302.txt 2l_cvrp0404.txt 2l_cvrp1105.txt 2l_cvrp1901.txt 2l_cvrp2602.txt 2l_cvrp3303.txt 2l_cvrp0405.txt 2l_cvrp1201.txt 2l_cvrp1902.txt 2l_cvrp2603.txt 2l_cvrp3304.txt 2l_cvrp0501.txt 2l_cvrp1202.txt 2l_cvrp1903.txt 2l_cvrp2604.txt 2l_cvrp3305.txt 2l_cvrp0502.txt 2l_cvrp1203.txt 2l_cvrp1904.txt 2l_cvrp2605.txt 2l_cvrp3401.txt 2l_cvrp0503.txt 2l_cvrp1204.txt 2l_cvrp1905.txt 2l_cvrp2701.txt 2l_cvrp3402.txt 2l_cvrp0504.txt 2l_cvrp1205.txt 2l_cvrp2001.txt 2l_cvrp2702.txt 2l_cvrp3403.txt 2l_cvrp0505.txt 2l_cvrp1301.txt 2l_cvrp2002.txt 2l_cvrp2703.txt 2l_cvrp3404.txt 2l_cvrp0601.txt 2l_cvrp1302.txt 2l_cvrp2003.txt 2l_cvrp2704.txt 2l_cvrp3405.txt 2l_cvrp0602.txt 2l_cvrp1303.txt 2l_cvrp2004.txt 2l_cvrp2705.txt 2l_cvrp3501.txt 2l_cvrp0603.txt 2l_cvrp1304.txt 2l_cvrp2005.txt 2l_cvrp2801.txt 2l_cvrp3502.txt 2l_cvrp0604.txt 2l_cvrp1305.txt 2l_cvrp2101.txt 2l_cvrp2802.txt 2l_cvrp3503.txt 2l_cvrp0605.txt 2l_cvrp1401.txt 2l_cvrp2102.txt 2l_cvrp2803.txt 2l_cvrp3504.txt 2l_cvrp0701.txt 2l_cvrp1402.txt 2l_cvrp2103.txt 2l_cvrp2804.txt 2l_cvrp3505.txt 2l_cvrp0702.txt 2l_cvrp1403.txt 2l_cvrp2104.txt 2l_cvrp2805.txt 2l_cvrp3601.txt 2l_cvrp0703.txt 2l_cvrp1404.txt 2l_cvrp2105.txt 2l_cvrp2901.txt 2l_cvrp3602.txt 2l_cvrp0704.txt 2l_cvrp1405.txt 2l_cvrp2201.txt 2l_cvrp2902.txt 2l_cvrp3603.txt 2l_cvrp0705.txt 2l_cvrp1501.txt 2l_cvrp2202.txt 2l_cvrp2903.txt 2l_cvrp3604.txt 2l_cvrp0801.txt 2l_cvrp1502.txt 2l_cvrp2203.txt 2l_cvrp2904.txt 2l_cvrp3605.txt"

int main(){

	// ******CHANGE FILE HERE**********

	//string input = "2l_cvrp0101.txt 2l_cvrp0802.txt 2l_cvrp1503.txt";

	// string input = "2l_cvrp0101.txt 2l_cvrp0102.txt 2l_cvrp0103.txt 2l_cvrp0104.txt 2l_cvrp0105.txt 2l_cvrp0201.txt 2l_cvrp0202.txt 2l_cvrp0203.txt 2l_cvrp0204.txt 2l_cvrp0205.txt 2l_cvrp0301.txt 2l_cvrp0302.txt 2l_cvrp0303.txt 2l_cvrp0304.txt 2l_cvrp0305.txt 2l_cvrp0401.txt 2l_cvrp0402.txt 2l_cvrp0403.txt 2l_cvrp0404.txt 2l_cvrp0405.txt 2l_cvrp0501.txt 2l_cvrp0502.txt 2l_cvrp0503.txt 2l_cvrp0504.txt 2l_cvrp0505.txt 2l_cvrp0601.txt 2l_cvrp0602.txt 2l_cvrp0603.txt 2l_cvrp0604.txt 2l_cvrp0605.txt 2l_cvrp0701.txt 2l_cvrp0702.txt 2l_cvrp0703.txt 2l_cvrp0704.txt 2l_cvrp0705.txt 2l_cvrp0801.txt 2l_cvrp0802.txt 2l_cvrp0803.txt 2l_cvrp0804.txt 2l_cvrp0805.txt 2l_cvrp0901.txt 2l_cvrp0902.txt 2l_cvrp0903.txt 2l_cvrp0904.txt 2l_cvrp0905.txt 2l_cvrp1001.txt 2l_cvrp1002.txt 2l_cvrp1003.txt 2l_cvrp1004.txt 2l_cvrp1005.txt 2l_cvrp1101.txt 2l_cvrp1102.txt 2l_cvrp1103.txt 2l_cvrp1104.txt 2l_cvrp1105.txt 2l_cvrp1201.txt 2l_cvrp1202.txt 2l_cvrp1203.txt 2l_cvrp1204.txt 2l_cvrp1205.txt 2l_cvrp1301.txt 2l_cvrp1302.txt 2l_cvrp1303.txt 2l_cvrp1304.txt 2l_cvrp1305.txt 2l_cvrp1401.txt 2l_cvrp1402.txt 2l_cvrp1403.txt 2l_cvrp1404.txt 2l_cvrp1405.txt 2l_cvrp1501.txt 2l_cvrp1502.txt 2l_cvrp1503.txt 2l_cvrp1504.txt 2l_cvrp1505.txt 2l_cvrp1601.txt 2l_cvrp1602.txt 2l_cvrp1603.txt 2l_cvrp1604.txt 2l_cvrp1605.txt 2l_cvrp1701.txt 2l_cvrp1702.txt 2l_cvrp1703.txt 2l_cvrp1704.txt 2l_cvrp1705.txt 2l_cvrp1801.txt 2l_cvrp1802.txt 2l_cvrp1803.txt 2l_cvrp1804.txt 2l_cvrp1805.txt 2l_cvrp1901.txt 2l_cvrp1902.txt 2l_cvrp1903.txt 2l_cvrp1904.txt 2l_cvrp1905.txt 2l_cvrp2001.txt 2l_cvrp2002.txt 2l_cvrp2003.txt 2l_cvrp2004.txt 2l_cvrp2005.txt 2l_cvrp2101.txt 2l_cvrp2102.txt 2l_cvrp2103.txt 2l_cvrp2104.txt 2l_cvrp2105.txt 2l_cvrp2201.txt 2l_cvrp2202.txt 2l_cvrp2203.txt 2l_cvrp2204.txt 2l_cvrp2205.txt 2l_cvrp2301.txt 2l_cvrp2302.txt 2l_cvrp2303.txt 2l_cvrp2304.txt 2l_cvrp2305.txt 2l_cvrp2401.txt 2l_cvrp2402.txt 2l_cvrp2403.txt 2l_cvrp2404.txt 2l_cvrp2405.txt 2l_cvrp2501.txt 2l_cvrp2502.txt 2l_cvrp2503.txt 2l_cvrp2504.txt 2l_cvrp2505.txt 2l_cvrp2601.txt 2l_cvrp2602.txt 2l_cvrp2603.txt 2l_cvrp2604.txt 2l_cvrp2605.txt 2l_cvrp2701.txt 2l_cvrp2702.txt 2l_cvrp2703.txt 2l_cvrp2704.txt 2l_cvrp2705.txt 2l_cvrp2801.txt 2l_cvrp2802.txt 2l_cvrp2803.txt 2l_cvrp2804.txt 2l_cvrp2805.txt 2l_cvrp2901.txt 2l_cvrp2902.txt 2l_cvrp2903.txt 2l_cvrp2904.txt 2l_cvrp2905.txt 2l_cvrp3001.txt 2l_cvrp3002.txt 2l_cvrp3003.txt 2l_cvrp3004.txt 2l_cvrp3005.txt 2l_cvrp3101.txt 2l_cvrp3102.txt 2l_cvrp3103.txt 2l_cvrp3104.txt 2l_cvrp3105.txt 2l_cvrp3201.txt 2l_cvrp3202.txt 2l_cvrp3203.txt 2l_cvrp3204.txt 2l_cvrp3205.txt 2l_cvrp3301.txt 2l_cvrp3302.txt 2l_cvrp3303.txt 2l_cvrp3304.txt 2l_cvrp3305.txt 2l_cvrp3401.txt 2l_cvrp3402.txt 2l_cvrp3403.txt 2l_cvrp3404.txt 2l_cvrp3405.txt 2l_cvrp3501.txt 2l_cvrp3502.txt 2l_cvrp3503.txt 2l_cvrp3504.txt 2l_cvrp3505.txt 2l_cvrp3601.txt 2l_cvrp3602.txt 2l_cvrp3603.txt 2l_cvrp3604.txt 2l_cvrp3605.txt";
	// string buf;
	// stringstream ss(input);
	// string filename;

	// while (ss >> buf){
	// 	filename = "2L-CVRP test instances/" + buf;
	// 	readInput reader;
	// 	reader.readInputFile(filename);

	// 	initialRoute route(reader.numvehicles, reader.customers);
	// 	if (route.generateRoutes() == 1){
	// 		cout << "solution found" << endl;
	// 	} else {
	// 		cout << "solution NOT found" << endl;
	// 	}
	// }


	string filename;


	// string input = "2l_cvrp0101.txt 2l_cvrp0102.txt 2l_cvrp0103.txt 2l_cvrp0104.txt 2l_cvrp0105.txt 2l_cvrp0201.txt 2l_cvrp0202.txt 2l_cvrp0203.txt 2l_cvrp0204.txt 2l_cvrp0205.txt 2l_cvrp0301.txt 2l_cvrp0302.txt 2l_cvrp0303.txt 2l_cvrp0304.txt 2l_cvrp0305.txt 2l_cvrp0401.txt 2l_cvrp0402.txt 2l_cvrp0403.txt 2l_cvrp0404.txt 2l_cvrp0405.txt 2l_cvrp0501.txt 2l_cvrp0502.txt 2l_cvrp0503.txt 2l_cvrp0504.txt 2l_cvrp0505.txt 2l_cvrp0601.txt 2l_cvrp0602.txt 2l_cvrp0603.txt 2l_cvrp0604.txt 2l_cvrp0605.txt 2l_cvrp0701.txt 2l_cvrp0702.txt 2l_cvrp0703.txt 2l_cvrp0704.txt 2l_cvrp0705.txt 2l_cvrp0801.txt 2l_cvrp0802.txt 2l_cvrp0803.txt 2l_cvrp0804.txt 2l_cvrp0805.txt 2l_cvrp0901.txt 2l_cvrp0902.txt 2l_cvrp0903.txt 2l_cvrp0904.txt 2l_cvrp0905.txt 2l_cvrp1001.txt 2l_cvrp1002.txt 2l_cvrp1003.txt 2l_cvrp1004.txt 2l_cvrp1005.txt 2l_cvrp1101.txt 2l_cvrp1102.txt 2l_cvrp1103.txt 2l_cvrp1104.txt 2l_cvrp1105.txt 2l_cvrp1201.txt 2l_cvrp1202.txt 2l_cvrp1203.txt 2l_cvrp1204.txt 2l_cvrp1205.txt 2l_cvrp1301.txt 2l_cvrp1302.txt 2l_cvrp1303.txt 2l_cvrp1304.txt 2l_cvrp1305.txt 2l_cvrp1401.txt 2l_cvrp1402.txt 2l_cvrp1403.txt 2l_cvrp1404.txt 2l_cvrp1405.txt 2l_cvrp1501.txt 2l_cvrp1502.txt 2l_cvrp1503.txt 2l_cvrp1504.txt 2l_cvrp1505.txt 2l_cvrp1601.txt 2l_cvrp1602.txt 2l_cvrp1603.txt 2l_cvrp1604.txt 2l_cvrp1605.txt 2l_cvrp1701.txt 2l_cvrp1702.txt 2l_cvrp1703.txt 2l_cvrp1704.txt 2l_cvrp1705.txt 2l_cvrp1801.txt 2l_cvrp1802.txt 2l_cvrp1803.txt 2l_cvrp1804.txt 2l_cvrp1805.txt 2l_cvrp1901.txt 2l_cvrp1902.txt 2l_cvrp1903.txt 2l_cvrp1904.txt 2l_cvrp1905.txt 2l_cvrp2001.txt 2l_cvrp2002.txt 2l_cvrp2003.txt 2l_cvrp2004.txt 2l_cvrp2005.txt 2l_cvrp2101.txt 2l_cvrp2102.txt 2l_cvrp2103.txt 2l_cvrp2104.txt 2l_cvrp2105.txt 2l_cvrp2201.txt 2l_cvrp2202.txt 2l_cvrp2203.txt 2l_cvrp2204.txt 2l_cvrp2205.txt 2l_cvrp2301.txt 2l_cvrp2302.txt 2l_cvrp2303.txt 2l_cvrp2304.txt 2l_cvrp2305.txt 2l_cvrp2401.txt 2l_cvrp2402.txt 2l_cvrp2403.txt 2l_cvrp2404.txt 2l_cvrp2405.txt 2l_cvrp2501.txt 2l_cvrp2502.txt 2l_cvrp2503.txt 2l_cvrp2504.txt 2l_cvrp2505.txt 2l_cvrp2601.txt 2l_cvrp2602.txt 2l_cvrp2603.txt 2l_cvrp2604.txt 2l_cvrp2605.txt 2l_cvrp2701.txt 2l_cvrp2702.txt 2l_cvrp2703.txt 2l_cvrp2704.txt 2l_cvrp2705.txt 2l_cvrp2801.txt 2l_cvrp2802.txt 2l_cvrp2803.txt 2l_cvrp2804.txt 2l_cvrp2805.txt 2l_cvrp2901.txt 2l_cvrp2902.txt 2l_cvrp2903.txt 2l_cvrp2904.txt 2l_cvrp2905.txt 2l_cvrp3001.txt 2l_cvrp3002.txt 2l_cvrp3003.txt 2l_cvrp3004.txt 2l_cvrp3005.txt 2l_cvrp3101.txt 2l_cvrp3102.txt 2l_cvrp3103.txt 2l_cvrp3104.txt 2l_cvrp3105.txt 2l_cvrp3201.txt 2l_cvrp3202.txt 2l_cvrp3203.txt 2l_cvrp3204.txt 2l_cvrp3205.txt 2l_cvrp3301.txt 2l_cvrp3302.txt 2l_cvrp3303.txt 2l_cvrp3304.txt 2l_cvrp3305.txt 2l_cvrp3401.txt 2l_cvrp3402.txt 2l_cvrp3403.txt 2l_cvrp3404.txt 2l_cvrp3405.txt 2l_cvrp3501.txt 2l_cvrp3502.txt 2l_cvrp3503.txt 2l_cvrp3504.txt 2l_cvrp3505.txt 2l_cvrp3601.txt 2l_cvrp3602.txt 2l_cvrp3603.txt 2l_cvrp3604.txt 2l_cvrp3605.txt";
	// string buf;
	// stringstream ss(input);
	// int counter;
	// int success;
	// while (ss >> buf){
	// 	filename = "2L-CVRP test instances/" + buf;
	// 	readInput reader;
	// 	reader.readInputFile(filename);

	// 	bool fail = 1;
	// 	double areaMult = 1.0;

	// 	while (fail == 1 && areaMult >= 0.0){
	// 		fail = 0;
	// 		initialRoute route(reader.numvehicles, reader.vehiclecap, reader.customers, areaMult);
	// 		if (route.generateRoutes() == 0){
	// 			fail = 1;
	// 		}
	// 		areaMult -= 0.01;
	// 		//cout << areaMult << endl;
	// 	}

	// 	if (fail == 0){
	// 		cout << "solution found with areaW = " << areaMult << endl;
	// 		success++;
	// 	} else {
	// 		cout << "solution NOT found for " << filename << endl;
	// 	}
	// 	counter++;
	// }
	// cout << "found " << success << "/" << counter << " solutions" << endl;

	filename = "2L-CVRP test instances/2l_cvrp0101.txt";
	readInput reader;
	reader.readInputFile(filename);

	bool fail = 1;
	double areaMult = 0.2;

	 // while (fail == 1 && areaMult >= 0.0){
		fail = 0;
		initialRoute route(reader.numvehicles, reader.vehiclecap, reader.customers, areaMult);
		if (route.generateRoutes() == 0){
			fail = 1;
		}
		//  areaMult -= 0.01;
	 // }

	if (fail == 0){
		cout << "solution found with areaW = " << areaMult << endl;
	} else {
		cout << "solution NOT found for " << filename << endl;
	}

	reader.printDataOF(256.0);
	route.printRoutesOF();
	// route.printRoutes();




	// initialRoute route(reader.numvehicles, reader.customers, 0.5);
	// if (route.generateRoutes() == 1){
	// 	cout << "solution found" << endl;
	// } else {
	// 	cout << "solution NOT found" << endl;
	// }
	// route.printRoutes();

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