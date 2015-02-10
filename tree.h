/*
 * tree.h
 *
 *  Created on: Feb 8, 2015
 *      Author: liang
 */

#ifndef TREE_H_
#define TREE_H_
#include <vector>
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int, Node*, Node*);
};
Node* constructBalanceTree(const std::vector<int>& num);//oredered num: binary, otherwise not BST
Node* getByValue(Node* root, int val);
Node* constructUnbalanceTree(const std::vector<int>& num);

#endif /* TREE_H_ */
