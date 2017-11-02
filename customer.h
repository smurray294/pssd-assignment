#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include "item.h"

class customer{
public:
	void add_item(int length, int width, int d);
	void sort_items();
	customer();

	std::vector<item> items;

	int totalarea;
	int x;
	int y;
	int weight;
	int id;
	int numitems;
};

#endif