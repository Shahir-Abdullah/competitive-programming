#include <bits/stdc++.h>
using namespace std;

long long int solution()
{
	int n, k;
	cin>>n>>k;
	vector<int> profit(n);
	long long int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>profit[i];
		sum += profit[i];
	}
	long long int ans = 0;
	
	for(int i = 0; i < n/2; i++){
		int a = profit[i];
		int b = profit[i+k+1];
		ans = max(ans, sum - a - b);
	}
	return ans;
}

int main()
{
	cout<<solution()<<endl;
	return 0;
}