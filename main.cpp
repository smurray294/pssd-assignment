#include "readInput.h"
#include "TruckPack.h"
#include <iostream>

using namespace std;

typedef pair<int,int> mypair;
bool comparator ( const mypair& l, const mypair& r)
	{ return l.first > r.first; }

int main(){
	TruckPack packing;
	packing.Initialize(20,40);
	vector<int> widths;
	vector<int> lengths;
	// for (int i = 0; i < 10; ++i){
	// 	widths.push_back(5);
	// 	lengths.push_back(i+1);
	// }

	widths.push_back(5);
	widths.push_back(10);
	widths.push_back(5);
	widths.push_back(9);
	widths.push_back(8);
	widths.push_back(7);
	widths.push_back(12);
	widths.push_back(5);
	widths.push_back(20);

	lengths.push_back(4);
	lengths.push_back(10);
	lengths.push_back(6);
	lengths.push_back(8);
	lengths.push_back(7);
	lengths.push_back(10);
	lengths.push_back(20);
	lengths.push_back(5);
	lengths.push_back(1);

	vector< pair<int,int> > v;

	for (int i = 0; i < (int)widths.size(); ++i){
		v.push_back(make_pair(widths[i]*lengths[i],i));
	}

	sort(v.begin(), v.end(), comparator);

	for (int i = 0; i < (int)v.size(); ++i){
		//cout << v[i].first << endl;
		packing.insert(widths[v[i].second], lengths[v[i].second]);
	}

	packing.printTree();

	readInput reader;
	string filename = "2l_cvrp0101.txt";
	reader.readInputFile(filename);
	reader.printData();
}