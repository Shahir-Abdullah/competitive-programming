#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> all_subarrays;

void generate_all_subarrays(vector<int>& arr, int leftindex, int rightindex){
	if(rightindex >= arr.size())return;
	
	if(leftindex > rightindex){
		generate_all_subarrays(arr, 0, rightindex+1);
	}
	else{
		vector<int> subarr;
		for(int i = leftindex; i <= rightindex; i++){
			subarr.push_back(arr[i]);
		}
		all_subarrays.push_back(subarr);
		generate_all_subarrays(arr, leftindex+1, rightindex);
	}
}

long long int solution(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	generate_all_subarrays(nums, 0, 0);
	long long int result = 0;
	for(auto arr : all_subarrays){
		int mx = -INF;
		int mn = INF;
		for(int i = 0; i < arr.size(); i++){
			mx = max(mx, arr[i]);
			mn = min(mn, arr[i]);
		}
		result += (mx-mn);
	}
	return result;
}

int main(){
	int result = solution();
	cout<<result<<endl;
	return 0;
}