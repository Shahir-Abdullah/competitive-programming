#include <bits/stdc++.h>
using namespace std;
bool isValid(string s){
	int n = s.length();
	if(n==0)return true;
	if(n%2==1)return false;
	
	stack<char> stk;
	
	for(int i = 0; i < n; i++){
		char ch = s[i];
		if(stk.empty() || stk.top() != ch){
			stk.push(ch);
		}else if(stk.top() == ch){
			stk.pop();
		}
	}
	return stk.empty();
	
}
vector<int> solution()
{
	int n;
	cin>>n;
	vector<string> coupons(n);
	for(int i = 0; i < n; i++){
		cin>>coupons[i];
	}
	vector<int> validity(n, 0);
	for(int i = 0; i < n; i++){
		if(isValid(coupons[i]) == true){
			validity[i] = 1;
		}else{
			validity[i] = 0;
		}
	}
	return validity;
}

int main()
{
	vector<int> validity = solution();
	for(int i = 0; i < validity.size(); i++){
		cout<<validity[i]<<" ";
	}
	cout<<endl;
	return 0;
}