#include <bits/stdc++.h>
using namespace std;

vector<string> subarrays;
/**
Using this analogy for recursive call sequence, 
it should follow that maximum number of stack frames that could be present in memory at any point of time is equal to maximum depth of recursion tree. In the recursion tree, when the call corresponding to leaf node state is getting executed, its call sequence could be represented by the path from the root node in recursion tree to that leaf node. For example, in the recursion tree for computing 5th fibonacci number, when left and bottom most state f(1) is getting executed, the call sequence which led to this state would be f(5)->f(4)->f(3)->f(2)->f(1) and all the corresponding stack frames would be present in the memory and when f(1) is returned its stack frame would be removed from the memory(or call stack).

To conclude, space complexity of recursive algorithm is proportinal to maximum depth of recursion tree generated. If each function call of recursive algorithm takes O(m) space and if the maximum depth of recursion tree is 'n' then space complexity of recursive algorithm would be O(nm).
**/
void generate_substrings(string s, int leftIndex, int rightIndex){
	if(rightIndex >= s.length())return;
	if(leftIndex > rightIndex){
		generate_substrings(s, 0, rightIndex+1);
	}else{
		string sub = s.substr(leftIndex, rightIndex-leftIndex+1);
		subarrays.push_back(sub);
		generate_substrings(s, leftIndex+1, rightIndex);
	}
	return;
}

int count_distinct(string s){
	unordered_map<char, int> mp;
	for(int i = 0; i < s.length(); i++){
		mp[s[i]]++;
	}
	return mp.size();
}

int solution(){
	int sum = 0;
	for(string s : subarrays){
		sum += count_distinct(s);
	}
	return sum;
}
int main(){
	string s;
	cin>>s;
	generate_substrings(s, 0, 0);
	cout<<solution()<<endl;
	return 0;
}