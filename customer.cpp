#include "customer.h"

bool areacomparator ( const customer::item& l, const customer::item& r){
	return (l.area) > (r.area); 
}

customer::customer(){
	totalarea = 0;
	x = 0;
	y = 0;
	weight = 0;
}

void customer::add_item(int length, int width){
	items.push_back(item());
	items[(int)items.size()-1].length = length;
	items[(int)items.size()-1].width = width;
	items[(int)items.size()-1].area = length*width;
}

void customer::sort_items(){
	sort(items.begin(), items.end(), areacomparator);
}