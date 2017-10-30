#include <vector>
#include <iostream>
using namespace std;

vector<int> weights;

struct route{
	vector<int> cust;
	int freeArea;
	int currWeight;
};

typedef pair<int,int> mypair;
bool comparator ( const mypair& l, const mypair& r){
	double areaW = 0.2;
	double weightW = 0.8;
	return (l.first*areaW + weights[l.second]*weightW) > (r.first*areaW + weights[r.second]*weightW); 
}

int main(){
	vector< pair<int,int> > areas;
	int trucks = 3;

	int arr[15] = {7,30,16,9,21,15,19,23,11,5,19,29,23,21,10};


	for (int i = 0; i < 15; ++i)
	{
		weights.push_back(arr[i]);
	}

	int ii = 0;
	areas.push_back(make_pair(7*9 + 34*3,ii++));
	areas.push_back(make_pair(14*5 + 36*3,ii++));
	areas.push_back(make_pair(29*3 + 5*8,ii++));
	areas.push_back(make_pair(19*3 + 9*4,ii++));
	areas.push_back(make_pair(6*10 + 8*10,ii++));
	areas.push_back(make_pair(19*9,ii++));
	areas.push_back(make_pair(7*11,ii++));
	areas.push_back(make_pair(12*7,ii++));
	areas.push_back(make_pair(22*4 + 31*3,ii++));
	areas.push_back(make_pair(10*4 + 8*8,ii++));
	areas.push_back(make_pair(20*4 + 30*2,ii++));
	areas.push_back(make_pair(17*3,ii++));
	areas.push_back(make_pair(7*17,ii++));
	areas.push_back(make_pair(5*9,ii++));
	areas.push_back(make_pair(18*6 + 31*3,ii++));

	sort(areas.begin(), areas.end(), comparator);


	for (int i = 0; i < 15; ++i)
	{
		cout << areas[i].first << " " << areas[i].second << " " << weights[areas[i].second] << endl;
	}

	vector<route> routes;

	vector<int> temp;
	for (int i = 0; i < trucks; ++i){
		routes.push_back(route());
		routes[i].freeArea = 800;
	}


	// feasibility of inserting a customer i into every position of every route
	// is tested

	// loop through customers
	for (int icusts = 0; icusts < 15; ++icusts)
	{

		// loop through routes
		int minarea = 800;
		int minareai = -1;
		int temparea;
		for (int iroutes = 0; iroutes < trucks; ++iroutes)
		{

			// // loop through positions in routes
			// for (int ipos = 0; ipos < routes[iroutes].cust; ++i)
			// {
			// 	/* code */
			// }

			// check area
			// temparea = routes[iroutes].freeArea - areas[icusts].first;
			// if (temparea < minarea && temparea >= 0){
			// 	// check weight

			// 	if ((routes[iroutes].currWeight + weights[areas[icusts].second]) <= 90){
			// 		minarea = temparea;
			// 		minareai = iroutes;
			// 		cout << icusts << endl;
			// 	}

			// }

			temparea = routes[iroutes].freeArea - areas[icusts].first;
			if (temparea < minarea && temparea >= 0){
				// check weight

				if ((routes[iroutes].currWeight + weights[areas[icusts].second]) <= 90){
					minarea = temparea;
					minareai = iroutes;
				}
			}



			// int tempWeight = routes[iroutes].currWeight + weights[areas[icusts].second];
			// int tempArea = routes[iroutes].freeArea - areas[icusts].first;
			// if (tempWeight <= 90){
			// 	if (tempArea < minarea && tempArea >= 0){

			// 	}
			// }
		}
		
		// add and update route
		routes[minareai].currWeight += weights[areas[icusts].second];
		routes[minareai].freeArea = temparea;
		routes[minareai].cust.push_back(areas[icusts].second);
	}



	for (int i = 0; i < trucks; ++i)
	{
		cout << "truck " << i << endl;
		for (int j = 0; j < (int)routes[i].cust.size(); ++j)
		{
			cout << routes[i].cust[j] << " " << "weight: " << weights[routes[i].cust[j]] << endl;
		}
	}
}
