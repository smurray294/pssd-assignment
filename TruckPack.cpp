#include "TruckPack.h"
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool aacomparator ( const item& l, const item& r)
    { return l.area > r.area; }

bool wwcomparator ( const item& l, const item& r)
    { return l.width > r.width; }

bool llcomparator ( const item& l, const item& r)
    { return l.length > r.length; }

bool iidcomparator ( const item& l, const item& r)
    { return l.id < r.id; }

// void TruckPack::initialize(int width, int length){
//     truckWidth = width;
//     truckLength = length;
//     root.left = NULL;
//     root.right = NULL;
//     root.x = 0; 
//     root.y = 0;
//     root.width = width;
//     root.length = length;
// }

TruckPack::TruckPack(){
    truckWidth = 20;
    truckLength = 40;
    root.left = NULL;
    root.right = NULL;
    root.x = 0; 
    root.y = 0;
    root.width = 20;
    root.length = 40;
}

void TruckPack::initialise(){
    truckWidth = 20;
    truckLength = 40;
    root.left = NULL;
    root.right = NULL;
    root.x = 0; 
    root.y = 0;
    root.width = 20;
    root.length = 40;
}

TruckPack::Node* TruckPack::inserts(Node* node, item &myItem) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    int itemWidth = myItem.width;
    int itemLength = myItem.length;

    if(node->left || node->right) {
        Node* newNode = NULL;
        if(node->left) {
            newNode = inserts(node->left, myItem);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = inserts(node->right, myItem);
            if(newNode != NULL) {
                return newNode;
            }
        }
        //Didn't fit either subtree
        return NULL;
    }
    // This node is a leaf, but can we fit the new rectangle here?
    if(itemWidth > node->width || itemLength > node->length) {
        //No space
        return NULL;
    }

    // The new cell will fit, split the remaining space along the shorter axis,
    // that is probably more optimal.
    int newWidth = node->width - itemWidth;
    int newLength = node->length - itemLength;

    myItem.x = node->x;
    myItem.y = node->y;

    node->left = new Node;
    node->right = new Node;

    (node->left)->left = NULL;
    (node->left)->right = NULL;
    (node->right)->left = NULL;
    (node->right)->right = NULL;

    // Split the remaining space in horizontal direction.
    if(newWidth <= newLength) {
        (node->left)->x = node->x + itemWidth;
        (node->left)->y = node->y;
        (node->left)->width = newWidth;
        (node->left)->length = itemLength;

        (node->right)->x = node->x;
        (node->right)->y = node->y + itemLength;
        (node->right)->width = node->width;
        (node->right)->length = newLength;
    // Split the remaining space in vertical direction.
    } else {
        (node->left)->x = node->x;
        (node->left)->y = node->y + itemLength;
        (node->left)->width = itemWidth;
        (node->left)->length = newLength;

        (node->right)->x = node->x + itemWidth;
        (node->right)->y = node->y;
        (node->right)->width = newWidth;
        (node->right)->length = node->length;
    }
    // Note that as a result of the above, it can happen that node.left or node.right
    // is now a degenerate (zero area) rectangle. No need to do anything about it,
    // like remove the nodes as "unnecessary" since they need to exist as children of
    // this node (this node can't be a leaf anymore).

    // This node is now a non-leaf, so shrink its area - it now denotes
    // *occupied* space instead of free space. Its children spawn the resulting
    // area of free space.
    node->width = itemWidth;
    node->length = itemLength;

    return node;
}

TruckPack::Node* TruckPack::insertl(Node* node, item &myItem) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    int itemWidth = myItem.width;
    int itemLength = myItem.length;   

    if(node->left || node->right) {
        Node* newNode = NULL;
        if(node->left) {
            newNode = insertl(node->left, myItem);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = insertl(node->right, myItem);
            if(newNode != NULL) {
                return newNode;
            }
        }
        //Didn't fit either subtree
        return NULL;
    }
    // This node is a leaf, but can we fit the new rectangle here?
    if(itemWidth > node->width || itemLength > node->length) {
        //No space
        return NULL;
    }

    // The new cell will fit, split the remaining space along the shorter axis,
    // that is probably more optimal.
    int newWidth = node->width - itemWidth;
    int newLength = node->length - itemLength;

    node->left = new Node;
    node->right = new Node;

    myItem.x = node->x;
    myItem.y = node->y;

    (node->left)->left = NULL;
    (node->left)->right = NULL;
    (node->right)->left = NULL;
    (node->right)->right = NULL;

    // Split the remaining space in horizontal direction.
    if(newWidth >= newLength) {
        (node->left)->x = node->x + itemWidth;
        (node->left)->y = node->y;
        (node->left)->width = newWidth;
        (node->left)->length = itemLength;

        (node->right)->x = node->x;
        (node->right)->y = node->y + itemLength;
        (node->right)->width = node->width;
        (node->right)->length = newLength;
    // Split the remaining space in vertical direction.
    } else {
        (node->left)->x = node->x;
        (node->left)->y = node->y + itemLength;
        (node->left)->width = itemWidth;
        (node->left)->length = newLength;

        (node->right)->x = node->x + itemWidth;
        (node->right)->y = node->y;
        (node->right)->width = newWidth;
        (node->right)->length = node->length;
    }
    // Note that as a result of the above, it can happen that node.left or node.right
    // is now a degenerate (zero area) rectangle. No need to do anything about it,
    // like remove the nodes as "unnecessary" since they need to exist as children of
    // this node (this node can't be a leaf anymore).

    // This node is now a non-leaf, so shrink its area - it now denotes
    // *occupied* space instead of free space. Its children spawn the resulting
    // area of free space.
    node->width = itemWidth;
    node->length = itemLength;

    return node;
}

TruckPack::Nodex* TruckPack::insertx(Nodex* node, int itemWidth, int itemLength) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    if(node->left || node->right) {
        Nodex* newNode = NULL;
        if(node->left) {
            newNode = insertx(node->left, itemWidth, itemLength);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = insertx(node->right, itemWidth, itemLength);
            if(newNode != NULL) {
                return newNode;
            }
        }
        //Didn't fit either subtree
        return NULL;
    }

    int flag = 0;
    // This node is a leaf, but can we fit the new rectangle here?
    if(itemWidth > node->width1 || itemLength > node->length1) {
        //No space
        if(itemWidth > node->width2 || itemLength > node->length2){
            return NULL;
        }
        flag = 2;
    } else {
        flag = 1;
    }

    // The new cell will fit, split the remaining space along the shorter axis,
    // that is probably more optimal.

    int newWidth;
    int newLength;

    if (flag == 1){
        newWidth = node->width1 - itemWidth;
        newLength = node->length1 - itemLength;
    } else {
        newWidth = node->width2 - itemWidth;
        newLength = node->length2 - itemLength;
    }


    node->left = new Nodex;
    node->right = new Nodex;

    (node->left)->left = NULL;
    (node->left)->right = NULL;
    (node->right)->left = NULL;
    (node->right)->right = NULL;

    // Split the remaining space in horizontal direction.
    (node->left)->x1 = node->x1 + itemWidth;
    (node->left)->y1 = node->y1;
    (node->left)->width1 = newWidth;
    (node->left)->length1 = itemLength;

    (node->right)->x1 = node->x1;
    (node->right)->y1 = node->y1 + itemLength;
    (node->right)->width1 = node->width1;
    (node->right)->length1 = newLength;
    // Split the remaining space in vertical direction.
    (node->left)->x2 = node->x2;
    (node->left)->y2 = node->y2 + itemLength;
    (node->left)->width2 = itemWidth;
    (node->left)->length2 = newLength;

    (node->right)->x2 = node->x2 + itemWidth;
    (node->right)->y2 = node->y2;
    (node->right)->width2 = newWidth;
    (node->right)->length2 = node->length2;
    // Note that as a result of the above, it can happen that node.left or node.right
    // is now a degenerate (zero area) rectangle. No need to do anything about it,
    // like remove the nodes as "unnecessary" since they need to exist as children of
    // this node (this node can't be a leaf anymore).

    // This node is now a non-leaf, so shrink its area - it now denotes
    // *occupied* space instead of free space. Its children spawn the resulting
    // area of free space.
    node->width1 = itemWidth;
    node->length1 = itemLength;

    node->width2 = itemWidth;
    node->length2 = itemLength;

    return node;
}

void TruckPack::updateIDs(std::vector<customer> &customers, std::vector<item> &nonseq){
    std::sort(nonseq.begin(), nonseq.end(), iidcomparator);

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << nonseq[i].id << endl;
    }

    cout << nonseq.size() << endl;

    for (int k = 0; k < (int)nonseq.size(); ++k)
    {
        for (int i = 0; i < (int)customers.size(); ++i)
        {
            for (int j = 0; j < (int)customers[i].items.size(); ++j)
            {
                if (customers[i].items[j].id == nonseq[k].id){
                    customers[i].items[j].x = nonseq[k].x;
                    customers[i].items[j].y = nonseq[k].y;
                    cout << customers[i].items[j].x << " " << customers[i].items[j].y << endl;
                }
            }

        }
    }
}

bool TruckPack::pack(vector<customer> &customers){
    // can we pack?

    bool fail;
    int counter = 0;

    vector<item> nonseq;
    // non sequential
    for (int i = 0; i < (int)customers.size(); ++i)
    {
        for (int j = 0; j < (int)customers[i].items.size(); ++j)
        {
            nonseq.push_back(item());
            nonseq[(int)nonseq.size()-1].width = customers[i].items[j].width;
            nonseq[(int)nonseq.size()-1].length = customers[i].items[j].length;
            nonseq[(int)nonseq.size()-1].area = customers[i].items[j].area;
            nonseq[(int)nonseq.size()-1].id = customers[i].items[j].id;
            //cout << customers[i].items[j].id << endl;
        }

    }

    fail = 1;
    initialise();

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (insertl(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (inserts(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    sort(nonseq.begin(), nonseq.end(), aacomparator);

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (insertl(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (inserts(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    sort(nonseq.begin(), nonseq.end(), wwcomparator);

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (insertl(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (inserts(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    sort(nonseq.begin(), nonseq.end(), llcomparator);

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (insertl(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    initialise();
    fail = 1;

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (inserts(nonseq[i]) == NULL){
            fail = 0;
        }
    }

    if (fail == 1){
        updateIDs(customers, nonseq);
        return 1;
    }

    //printTree("results.txt");

    return 0;
}

void TruckPack::printTree(string filename){
	ofstream myfile;
	myfile.open(filename);
	printTreeHelper(&root, myfile);
	myfile.close();
}

void TruckPack::printTreeHelper(Node* node, ofstream &myfile){
	// x y width length
	if (node != NULL){
		if (node->left != NULL && node->right != NULL){
			myfile << node->x << " " << node->y << " " << node->width << " " << node->length << endl;
		}

		if (node->left){
			printTreeHelper(node->left, myfile);
		}

		if (node->right){
			printTreeHelper(node->right, myfile);
		}
	}
}