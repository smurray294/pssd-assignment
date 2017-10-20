#include "readInput.h"
#include "TruckPack.h"
#include <iostream>

using namespace std;

typedef pair<int,int> mypair;
bool comparator ( const mypair& l, const mypair& r)
	{ return l.first > r.first; }

int main(){

	readInput reader;
	string filename = "2l_cvrp0101.txt";
	reader.readInputFile(filename);
	//reader.printData();

	TruckPack packing;
	packing.Initialize(20,40);
	// vector<int> widths;
	// vector<int> lengths;

	vector< pair<int,int> > v;

	for (int i = 0; i < (int)reader.widths.size(); ++i){
		v.push_back(make_pair(reader.widths[i]*reader.lengths[i],i));
	}

	sort(v.begin(), v.end(), comparator);

	for (int i = 0; i < (int)v.size(); ++i){
		//cout << v[i].first << endl;
		packing.insert(reader.widths[v[i].second], reader.lengths[v[i].second]);
	}

	packing.printTree("results.txt");


}