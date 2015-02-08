#include "lowestCommonAncestor.h"
#include <iostream>
#include <time.h>
Node::Node(int val, Node* left, Node* right):val(val), left(left), right(right){}

Node* constructHelper(const vector<int>& num, Node* root, int left, int right){
	if(left>right) return nullptr;
	int idx = (left+right)/2;
	root = new Node(num[idx], nullptr, nullptr);
	root->left = constructHelper(num, root->left, left, idx-1);
	root->right = constructHelper(num, root->right, idx+1, right);

	return root;
}

Node* constructTree(const vector<int>& num){
	if(num.size()==0)
		return nullptr;
	Node* root = constructHelper(num, root, 0, num.size()-1);
	return root;
}

Node* getByValue(Node* root, int val){
	if(root==nullptr) return nullptr;
	if(root->val == val) return root;
	Node* node = getByValue(root->left, val);
	if(node!=nullptr) return node;
	return getByValue(root->right, val);
}


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

	Node* left = LCADownUp(root->left, p, q);
	Node* right = LCADownUp(root->right, p, q);

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

	vector<int> num;
	for(int i=0;i<1000;i++){
		num.push_back(i);
	}

	start = clock();
	Node* root = constructTree(num);
	Node* node1 = getByValue(root, 48);
	Node* node2 = getByValue(root, 100);

	std::cout << "Init Time: " << clock()-start << std::endl;



	std::cout << "Up to Down" << std::endl;
	start = clock();
	Node* ancestor = LCAUpDown(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: "<< ancestor->val << std::endl;
	}


	std::cout << "Down to Up" << std::endl;
	start = clock();
	ancestor = LCADownUpHelper(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}


	std::cout << "BST" << std::endl;
	start = clock();
	ancestor = LCABST(root, node1, node2);
	std::cout << "Time: " << clock()-start << std::endl;
	if(ancestor==nullptr){
		std::cout << "no ancestor" << std::endl;
	}else{
		std::cout << "Ancestor: " << ancestor->val << std::endl;
	}
}

