#include <vector>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int, Node*, Node*);
};
Node* constructTree(const vector<int>& num);
Node* getByValue(Node* root, int val);
Node* LCAUpDown(Node* root, Node* p, Node* q);
Node* LCADownUp(Node* root, Node* p, Node* q);
Node* LCABST(Node* root, Node* p, Node* q);
void lowestCommonAncestorTest();
