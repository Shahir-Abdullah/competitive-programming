#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

bool possible(){
	int n, x;
	cin>>n>>x;
	vector<int> heights(n);
	for(int i = 0; i < n; i++){
		cin>>heights[i];
	}
	vector<vector<bool>> dp(n+1, vector<bool> (x+1, false));
	
	for(int day = 0; day <= x; day++){
		dp[1][day] = true;
	}
	
	for(int i = 2; i <= n; i++){
		int prev_day = INF;
		for(int day = 1; day <= x; day++){
			if(dp[i-1][day] == true){
				prev_day = day;
				break;
			}
		}
		
		int min_day_need = (heights[i] > heights[i-1])?0:abs(heights[i]-heights[i-1])+1;
		min_day_need += prev_day;
		for(int day = min_day_need; day <= x; day++){
			dp[i][day] = true;
		}
	}
	return dp[n][x];
}

int main(){
	if(possible()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}