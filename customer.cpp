#include "customer.h"
#include <iostream>

using namespace std;

bool areacomparator ( const item& l, const item& r){
	return (l.area) > (r.area); 
}

customer::customer(){
	totalarea = 0;
	x = 0;
	y = 0;
	weight = 0;
}

void customer::add_item(int length, int width, int id){
	items.push_back(item());
	items[(int)items.size()-1].length = length;
	items[(int)items.size()-1].width = width;
	items[(int)items.size()-1].area = length*width;
	items[(int)items.size()-1].id = id;
	//cout << id << endl;
}

void customer::sort_items(){
	sort(items.begin(), items.end(), areacomparator);
}