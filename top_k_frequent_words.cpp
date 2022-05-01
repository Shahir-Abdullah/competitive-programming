#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}

vector<string> solution(){
	int n, k;
	cin>>n>>k;
	unordered_map<string, int> mp;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		mp[s]++;
	}
	vector<pair<string, int>> freq;
	for(auto word : mp){
		freq.push_back(word);
	}
	
	sort(freq.begin(), freq.end(), cmp);
	
	vector<string> result;
	
	for(int i = 0; i < k; i++){
		result.push_back(freq[i].first);
	}
	return result;
	
}

int main()
{
	vector<string> result = solution();
	for(auto s : result){
		cout<<s<<endl;
	}
	return 0;
}