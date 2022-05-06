#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
	return a.first < b.first;
}

int solution(){
	int m, n;
	cin>>m>>n;
	vector<pair<int, int>> points(2*n);
	int open = 0;
	int close = 1;
	int j = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		points[j++] = {a, open};
		points[j++] = {b, close};
	}
	
	sort(points.begin(), points.end(), cmp);
	
	int maxPoint = 0;
	int maxDiff = 0;
	
	int cnt = 0;
	for(int i = 1; i < 2*n; i++){
		if(points[i].second == open){
			cnt++;
			if(maxDiff < cnt){
				maxPoint = points[i].first;
			}
		}else{
			cnt--;
		}
	}
	return maxPoint;
}

int main(){
	int ans = solution();
	cout<<ans<<endl;
	return 0;
}