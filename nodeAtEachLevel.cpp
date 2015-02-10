/*
 * nodeAtEachLevel.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: liang
 */

#include "nodeAtEachLevel.h"
#include <deque>
#include <iostream>

vector<vector<Node*> > nodeEachLevel(Node* root){

	vector<vector<Node*> > res;
	if(root==nullptr) return res;
	deque<Node* > queue;
	vector<Node* > level;
	queue.push_back(root);
	queue.push_back(nullptr);
	while(true){
		Node* node = queue.front();
		queue.pop_front();
		if(node==nullptr){
			res.push_back(level);
			level.clear();
			if(queue.empty()){
				break;
			}else{
				queue.push_back(nullptr);
			}
		}else{
			if(node->left!=nullptr)
				level.push_back(node->left);
			if(node->right!=nullptr)
				level.push_back(node->right);
		}
	}
	return res;
}

void nodeEachLevelTest(){
	vector<int> num;
	for(int i=0;i<100;i++){
		num.push_back(i);
	}
	Node* root = constructBalanceTree(num);
	vector<vector<Node*> > list = nodeEachLevel(root);
	for(auto v:list){
		for(auto e: v){
			cout << e->val << " ";
		}
		cout << endl;
	}
}
