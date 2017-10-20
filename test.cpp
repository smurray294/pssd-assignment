#include <iostream>
#include <utility>
#include <vector>
using namespace std;


class RectangleTruckPack {
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


void RectangleTruckPack::Initialize(int width, int length)
{
    truckWidth = width;
    truckLength = length;
    root.left = NULL;
    root.right = NULL;
    root.x = 0; 
    root.y = 0;
    root.width = width;
    root.length = length;
}

RectangleTruckPack::Node* RectangleTruckPack::insert(Node* node, int itemWidth, int itemLength) {
    // If this node is an internal node, try both leaves for possible space.
    // (The rectangle in an internal node stores used space, the leaves store free space)
    if(node->left || node->right) {
        Node* newNode = NULL;
        if(node->left) {
            newNode = insert(node->left, itemWidth, itemLength);
            if(newNode != NULL) {
                return newNode;
            }
        }
        if(node->right) {
            newNode = insert(node->right, itemWidth, itemLength);
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

void RectangleTruckPack::printTree(){
	printTreeHelper(&root);
}

void RectangleTruckPack::printTreeHelper(Node* node){
	// x y width length
	if (node != NULL){
		if (node->left != NULL && node->right != NULL){
			cout << node->x << " " << node->y << " " << node->width << " " << node->length << endl;
		}

		if (node->left){
			printTreeHelper(node->left);
		}

		if (node->right){
			printTreeHelper(node->right);
		}
	}
}

typedef pair<int,int> mypair;
bool comparator ( const mypair& l, const mypair& r)
	{ return l.first > r.first; }

int main(){
	RectangleTruckPack obj;
	obj.Initialize(20,40);
	vector<int> widths;
	vector<int> lengths;
	// for (int i = 0; i < 10; ++i){
	// 	widths.push_back(5);
	// 	lengths.push_back(i+1);
	// }

	widths.push_back(5);
	widths.push_back(10);
	widths.push_back(5);
	widths.push_back(9);
	widths.push_back(8);
	widths.push_back(7);
	widths.push_back(12);
	widths.push_back(5);
	widths.push_back(20);

	lengths.push_back(4);
	lengths.push_back(10);
	lengths.push_back(6);
	lengths.push_back(8);
	lengths.push_back(7);
	lengths.push_back(10);
	lengths.push_back(20);
	lengths.push_back(5);
	lengths.push_back(1);



	vector< pair<int,int> > v;

	for (int i = 0; i < (int)widths.size(); ++i){
		v.push_back(make_pair(widths[i]*lengths[i],i));
	}

	sort(v.begin(), v.end(), comparator);

	for (int i = 0; i < (int)v.size(); ++i){
		//cout << v[i].first << endl;
		obj.insert(widths[v[i].second], lengths[v[i].second]);
	}

	obj.printTree();


	// obj.insert(2,2);
	// obj.insert(2,2);
	//obj.printTree();
}