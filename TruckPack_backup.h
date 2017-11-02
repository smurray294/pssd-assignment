#ifndef TRUCKPACK_H
#define TRUCKPACK_H

#include <string>
#include <fstream>
#include <vector>
#include "customer.h"

struct item{
    int length;
    int width;
    int area;
    int x;
    int y;
    int id;
};

class TruckPack{
public:
	struct Node {
        Node* left;
        Node* right;
        int width;
        int length;
        int x;
        int y;
    };

    struct Nodex {
        Nodex* left;
        Nodex* right;
        int width1;
        int length1;
        int x1;
        int y1;
        int width2;
        int length2;
        int x2;
        int y2;
    };

    TruckPack();

    Node *insertl(item &myItem) {
        return insertl(&root, myItem);
    }

    Node *inserts(item &myItem) {
        return inserts(&root, myItem);
    }

    Nodex *insertx(int itemWidth, int itemLength) {
        return insertx(&rootx, itemWidth, itemLength);
    }

   // void initialize(int width, int length);
    bool pack(std::vector<customer> customers);
    void printTree(std::string filename);
    void printTreeHelper(Node* node, std::ofstream &myfile);
    void initialise();
private:
    Node root;
    Nodex rootx;
    int truckWidth;
    int truckLength;
    Node* insertl(Node* node, int itemWidth, int itemLength);
    Node* inserts(Node* node, int itemWidth, int itemLength);
    Nodex* insertx(Nodex* node, int itemWidth, int itemLength);

};

#endif