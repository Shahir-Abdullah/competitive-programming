#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 5;

const int INF = 1e9 + 7;


int minimum_difficulty(){
	int n;
	cin>>n;
	vector<int> jobDifficulty(n);
	for(int i = 0; i < n; i++){
		cin>>jobDifficulty[i];
	}
	int d;
	cin>>d;
	if(d < n)return -1;
	
	vector<vector<int>> dp(n+1, vector<int> (d+1, INF));
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			int max_d = 0;
			for(int k = i; k >= j; k--){
				max_d = max(max_d, jobDifficulty[k-1]);
				if(dp[k-1][j-1] < INF){
					dp[i][j] = min(dp[i][j], max_d+dp[k-1][j-1]);
				}
			}
		}
	}
	return dp[n][d];
}

int main(){
	
	
	return 0;
}