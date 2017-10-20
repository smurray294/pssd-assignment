#ifndef TRUCKPACK_H
#define TRUCKPACK_H

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

    Node *insert(int itemWidth, int itemLength) {
        return insert(&root, itemWidth, itemLength);
    }

    void Initialize(int width, int length);
    void printTree();
    void printTreeHelper(Node* node);
private:
    Node root;
    int truckWidth;
    int truckLength;
    Node* insert(Node* node, int itemWidth, int itemLength);
};

#endif