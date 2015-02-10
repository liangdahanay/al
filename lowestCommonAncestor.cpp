/*
 * lowestCommonAncestor.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: liang
 */

#include "lowestCommonAncestor.h"
#include <iostream>
#include <time.h>
#include "tree.h"
int count(Node* root, Node* p, Node* q){
	if(root==nullptr) return 0;

	int match = count(root->left, p, q) + count(root->right, p, q);
	if(root==p ||root==q){
		match++;
	}
	return match;
}

Node* LCAUpDownHelper(Node* root, Node* p, Node* q){
	if(p==nullptr||q==nullptr||root==nullptr) return nullptr;
	if(root==q||root==p) return root;

	int matchLeft = count(root->left, p, q);
	if(matchLeft==1){
		return root;
	}else if(matchLeft==2){
		return LCAUpDown(root->left,  p, q);
	}else{
		return LCAUpDown(root->right,  p, q);
	}
}
Node* LCAUpDown(Node* root, Node* p, Node* q){
	if(count(root, p, q)!=2) return nullptr;
	return LCAUpDownHelper( root, p, q);
}

Node* LCADownUpHelper(Node* root, Node* p, Node* q){

	if(p==nullptr||q==nullptr||root==nullptr) return nullptr;
	if(root==q||root==p) return root;

	Node* left = LCADownUpHelper(root->left, p, q);
	Node* right = LCADownUpHelper(root->right, p, q);

	if(left!=nullptr && right!=nullptr) return root;

	return left==nullptr?right:left;
}
Node* LCADownUp(Node* root, Node* p, Node* q){
	if(count(root, p, q)!=2) return nullptr;
	return LCADownUpHelper( root, p, q);
}


Node* LCABSTHelper(Node* root, Node* p, Node* q){
	if(p==nullptr||q==nullptr||root==nullptr) return nullptr;
	if(root==q||root==p) return root;
	if(root->val<min(p->val, q->val)){
		return LCABSTHelper(root->right, p, q);
	}else if(root->val>max(p->val, q->val)){
		return LCABSTHelper(root->left, p, q);
	}else{
		return root;
	}


}
Node* LCABST(Node* root, Node* p, Node* q){
	if(count(root, p, q)!=2) return nullptr;
	return LCABSTHelper( root, p, q);
}


void lowestCommonAncestorTest(){


	clock_t start;
	Node* ancestor;

	vector<int> num;
	for(int i=0;i<10000;i++){
		num.push_back(i);
	}

	start = clock();
	Node* root = constructBalanceTree(num);
	Node* node1 = getByValue(root, 101);
	Node* node2 = getByValue(root, 1000);

	std::cout << "Init balanced tree finished " << std::endl;


	Node* rootu = constructUnbalanceTree(num);
	Node* node1u = getByValue(rootu, 101);
	Node* node2u = getByValue(rootu, 1000);

	std::cout << "Init Unbalanced tree finished " << std::endl;

	std::cout << "Init Time: " << clock()-start << std::endl;


	std::cout << "Balanced" << std::endl << std::endl;

	std::cout << "Up to Down" << std::endl;
	start = clock();
	ancestor = LCAUpDown(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: "<< ancestor->val << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Down to Up" << std::endl;
	start = clock();
	ancestor = LCADownUpHelper(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}


	std::cout << std::endl;

	std::cout << "BST" << std::endl;
	start = clock();
	ancestor = LCABST(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}

	std::cout << std::endl;


	std::cout << "Unbalanced" << std::endl << std::endl;


	std::cout << "Up to Down" << std::endl;
	start = clock();
	ancestor = LCAUpDown(rootu, node1u, node2u);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: "<< ancestor->val << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Down to Up" << std::endl;
	start = clock();
	ancestor = LCADownUpHelper(rootu, node1u, node2u);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}


	std::cout << std::endl;

	std::cout << "BST" << std::endl;
	start = clock();
	ancestor = LCABST(rootu, node1u, node2u);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}

	std::cout << std::endl;
}


