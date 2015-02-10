#include "checkTree.h"
#include <stdlib.h>
#include <iostream>
#include "tree.h"
#include <time.h>
using namespace std;

int checkHeight(Node* root){
	if(root==nullptr) return 0;
	int left = checkHeight(root->left);
	if(left==-1) return -1;
	int right = checkHeight(root->right);
	if(right==-1) return -1;

	if(abs(left-right)>=2){
		return -1;
	}else{
		return max(left, right)+1;
	}
}

bool checkBalanced(Node* root){
	if(root==nullptr) return nullptr;
	int height = checkHeight(root);
	if(height==-1) return false;
	return true;
}

static Node* last = nullptr;
bool checkBSTInplace(Node* root){
	if(root==nullptr) return true;

	if(!checkBinaryInplace(root->left)) return false;

	if(last!=nullptr && last->val > root->val){
		return false;
	}

	last=root;

	if(!checkBinaryInplace(root->right)) return false;

	return true;
}


void treeInorderList(Node* root,vector<int>& list){
	if(root==nullptr) return;
	treeInorderList(root->left, list);
	list.push_back(root->val);
	treeInorderList(root->right, list);
}

bool checkBSTExtraSpace(Node* root){
	if(root==nullptr) return true;
	vector<int> list;
	treeInorderList(root, list);
	for(int i=1; i<list.size();i++){
		if(list[i]<list[i-1]) return false;
	}
	return true;

}



void checkTreeTest(){
	clock_t start;
	cout << "Balance, BST: " << endl;
	vector<int> num;
	for(int i=0;i<10000;i++){
		num.push_back(i);
	}
	Node* root = constructBalanceTree(num);
	start = clock();
	cout << "Balance? " << checkBalanced(root) << endl;
	cout << "Binary? " << checkBSTInplace(root) << endl;
	cout << "Time: " << clock()-start << endl <<endl;

	cout << "Random, BST: " << endl;
	Node* rootu = constructUnbalanceTree(num);
	start = clock();
	cout << "Balance? "<< checkBalanced(rootu) << endl;
	cout << "Binary? " << checkBSTInplace(rootu) << endl;
	cout << "Time: " << clock()-start << endl <<endl;

	num.clear();
	srand(time(0));
	for(int i=0;i<10000;i++){
		int item = rand();
		num.push_back(item);
	}
	cout << "Random, Un-BST: " << endl;
	Node* rootub = constructUnbalanceTree(num);
	start = clock();
	cout << "Balance? "<< checkBalanced(rootub) << endl;
	cout << "Binary? " << checkBSTInplace(rootub) << endl;
	cout << "Time: " << clock()-start << endl <<endl;

}
