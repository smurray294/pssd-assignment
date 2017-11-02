#include "MaxRectsBinPack.h"
#include "customer.h"
#include <vector>
#include <cstdio>

using namespace rbp;

// struct item{
//     int length;
//     int width;
//     int area;
//     int x;
//     int y;
//     int id;
// };

class bpInterface{
public:
	bpInterface();

	MaxRectsBinPack bin;

	void updateIDs(std::vector<customer> &customers, std::vector<item> &nonseq);

	bool pack(std::vector<customer> &customers);
	bool packHelper(std::vector<item> &nonseq);

};
