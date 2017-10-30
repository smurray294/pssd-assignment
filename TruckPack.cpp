#include "TruckPack.h"
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct item{
    int length;
    int width;
    int area;
};

bool comparator ( const item& l, const item& r)
    { return l.area > r.area; }

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

TruckPack::Node* TruckPack::inserts(Node* node, int itemWidth, int itemLength) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    if(node->left || node->right) {
        Node* newNode = NULL;
        if(node->left) {
            newNode = inserts(node->left, itemWidth, itemLength);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = inserts(node->right, itemWidth, itemLength);
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

TruckPack::Node* TruckPack::insertl(Node* node, int itemWidth, int itemLength) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    if(node->left || node->right) {
        Node* newNode = NULL;
        if(node->left) {
            newNode = insertl(node->left, itemWidth, itemLength);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = insertl(node->right, itemWidth, itemLength);
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

bool TruckPack::feasiblePack(vector<customer> customers){
    // can we pack?

    bool fail = 1;
    int counter = 0;


    // sequential?
    // for (int i = 0; i < (int)customers.size(); ++i)
    // {
    //     for (int j = 0; j < (int)customers[i].items.size(); ++j)
    //     {
    //         cout << "packing item " << counter++ << " " << customers[i].items[j].width << " by " << customers[i].items[j].length << endl;
    //         if (insert(customers[i].items[j].width, customers[i].items[j].length) == NULL){
    //             cout << "failed" << endl;
    //         } else {
    //             cout << "success" << endl;
    //         }
    //     }

    // }

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
        }

    }

    sort(nonseq.begin(), nonseq.end(), comparator);

    for (int i = 0; i < (int)nonseq.size(); ++i)
    {
        //cout << "packing item " << i << " " << nonseq[i].width << " by " << nonseq[i].length << endl;

       // if (insertx(nonseq[i].width, nonseq[i].length) == NULL){
        if (insertl(nonseq[i].width, nonseq[i].length) == NULL){
            if (inserts(nonseq[i].width, nonseq[i].length) == NULL){
                return 0;
            }
        } else {
            //cout << "success" << endl;
        }
    }

    //printTree("results.txt");

    return 1;
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