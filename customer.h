#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>

class customer{
public:
	struct item{
		int length;
		int width;
		int area;
	};

	void add_item(int length, int width);
	void sort_items();
	customer();

	std::vector<item> items;

	int totalarea;
	int x;
	int y;
	int weight;
	int id;
};

#endif