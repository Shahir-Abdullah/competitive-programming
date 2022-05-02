#include <bits/stdc++.h>

using namespace std;

int solution(){
	int n, teamsize, maxDiff;
	cin>>n>>teamsize>>maxDiff;
	vector<int> skills(n);
	for(int i = 0; i < n; i++){
		cin>>skills[i];
	}
	sort(skills.begin(), skills.end());
	
	int ans = 0;
	int left = 0, right = teamsize-1;
	while(right < n){
		if(skills[right]-skills[left] <= maxDiff){
			ans++;
			left = right + 1;
			right = left + teamsize - 1;
		}else{
			left++;
			right++;
		}
	}
	return ans;
}

int main(){
	cout<<solution()<<endl;
	return 0;
}