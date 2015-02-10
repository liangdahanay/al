/*
 * tree.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: liang
 */
#include "tree.h"
#include <cstdlib>
#include <ctime>
Node::Node(int val, Node* left, Node* right):val(val), left(left), right(right){}

Node* constructBalanceHelper(const std::vector<int>& num, Node* root, int left, int right){
	if(left>right) return nullptr;
	int idx = (left+right)/2;
	root = new Node(num[idx], nullptr, nullptr);
	root->left = constructBalanceHelper(num, root->left, left, idx-1);
	root->right = constructBalanceHelper(num, root->right, idx+1, right);

	return root;
}

Node* constructBalanceTree(const std::vector<int>& num){
	if(num.size()==0)
		return nullptr;
	Node* root = constructBalanceHelper(num, root, 0, num.size()-1);
	return root;
}

Node* getByValue(Node* root, int val){
	if(root==nullptr) return nullptr;
	if(root->val == val) return root;
	Node* node = getByValue(root->left, val);
	if(node!=nullptr) return node;
	return getByValue(root->right, val);
}

Node* constructUnbalanceHelper(const std::vector<int>& num, int left, int right){
	if(left>right){
		return nullptr;
	}
	srand(time(0));
	int idx = left+rand()%(right-left+1);
	Node* node = new Node(num[idx], nullptr, nullptr);
	node->left = constructUnbalanceHelper(num, left, idx-1);
	node->right = constructUnbalanceHelper(num, idx+1, right);

	return node;
}

Node* constructUnbalanceTree(const std::vector<int>& num){
	if(num.size()==0) return nullptr;
	return constructUnbalanceHelper(num, 0, num.size()-1);
}
