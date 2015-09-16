#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class FenwickTree{
private:
	vector<int> BITree;
	vector<int> nums;
	int n;

	int getSumParent(int index){
		return index & (index-1);
	}

	int getUpdateParent(int index){
		return index + (index&-index);
	}

public:
	FenwickTree(int* arr, int length)
		:n(length), BITree(length + 1), nums(length)
	{
		for (int i = 0; i < n;i++){
			update(i, arr[i]);
		}
	};

	void update(int position, int value){
		int index = position + 1;
		while (index<=n){
			BITree[index] += (value-nums[position]);
			index = getUpdateParent(index);
		}
		nums[position] = value;
	}
	
	int getSum(int position){
		int index = position + 1;
		int res = 0;
		while (index>0){
			res += BITree[index];
			index = getSumParent(index);
		}
		return res;
	}
};


#endif
