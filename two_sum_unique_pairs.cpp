#include <bits/stdc++.h>
using namespace std;

int solution(){
	int n, target;
	cin>>n>>target;
	int ans = 0;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	sort(nums.begin(), nums.end());
	set<pair<int, int>> s;
	int left = 0, right = n-1;
	while(left<right){
		int sum = nums[left] + nums[right];
		if(sum == target){
			int a, b;
			a = nums[left];
			b = nums[right];
			s.insert({a, b});
			right--;
			left++;
		}
		else if(sum > target){
			right--;
		}else{
			left++;
		}
	}
//	for(auto x : s){
//		cout<<x.first<<" "<<x.second<<endl;
//	}
	return s.size();
}

int main(){
	cout<<solution()<<endl;
	
	
}