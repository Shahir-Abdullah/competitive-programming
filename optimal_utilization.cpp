#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>const &a, pair<int, int>const&b){
	return a.second < b.second;
}

vector<pair<int, int>> solution(){
	int an, bn, target;
	cin>>an>>bn>>target;
	vector<pair<int, int>> a(an);
	vector<pair<int, int>> b(bn);
	for(int i = 0; i < an; i++){
		int af, as;
		cin>>af>>as;
		a[i] = {af, as};
	}
	for(int i = 0; i < bn; i++){
		int bf, bs;
		cin>>bf>>bs;
		b[i] = {bf, bs};
	}
	
	vector<pair<int, int>> result;
	
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	int minsum = 0;
	auto aptr = a.begin();
	auto bptr = b.rbegin();
	while(aptr != a.end() && bptr != b.rend()){
		int sum = (*aptr).second + (*bptr).second;
		if(sum > target){
			bptr++;
		}else{
			if(sum > minsum){
				result.clear();
			}
			result.push_back({(*aptr).first, (*bptr).first});
			minsum = sum;
			aptr++;
		}
	}
	return result;
	
	
}

int main(){
	vector<pair<int, int>> result = solution();
	for(int i = 0; i < result.size(); i++){
		cout<<result[i].first<<" "<<result[i].second<<endl;
	}
	return 0;
}