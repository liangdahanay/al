#include <string.h>
#include "mystrtok.h"
#include <map>
#include <iostream>
using namespace std;

vector<string> mystrtok(const string& str, const string& delim){
	vector<string> res;
	if(str.size()==0) return res;
	if(delim.size()==0){
		res.push_back(str);
		return res;
	}

	map<char, int> mapDelim;
	for(unsigned int i=0; i<delim.size(); i++){
		if(mapDelim.find(delim[i]) == mapDelim.end()){
			mapDelim[delim[i]] = 1;
		}
	}
	int start = 0;
	while(mapDelim.find(delim[start]) != mapDelim.end()){
		start++;
	}
	string item;
	for(int i=start; i<str.size(); i++){
		if(mapDelim.find(str[i]) != mapDelim.end() ){
			item = str.substr(start, i-start);
			if(item.size()!=0){
				res.push_back(item);
			}
			start=i+1;
		}
	}
	item = str.substr(start, str.size()-start);
	if(item.size()!=0)
		res.push_back(item);
	return res;
}

void mystrtoktest(){


	string str1 = ". aa .. a .. .bb. cc  .dd...";
	string delim1 = " .";


	vector<string> items = mystrtok(str1, delim1);

	for(int i=0;i<items.size();i++){
		cout << items[i] << endl;
	}
	cout << items.size() << endl;

	string str="a";
	cout << str.substr(1,0)<< endl;
}
