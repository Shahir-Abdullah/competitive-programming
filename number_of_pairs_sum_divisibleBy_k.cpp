#include <bits/stdc++.h>
using namespace std;

int number_of_pairs()
{
	int n, k;
	cin>>n>>k;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}
	
	vector<int> freq(k, 0);
	
	for(int i = 0; i < n; i++){
		freq[nums[i]%k]++;
	}
	
	int sum = (freq[0] * (freq[0]-1))/2;
	
	for(int i = 1; i <= k/2 && i != k-i; i++){
		sum += (freq[i]*freq[k-i]);
	}
	if(k%2==0){
		sum += (freq[k/2]*(freq[k/2]-1))/2;
	}
	
	return sum;
	
}

int main()
{
	cout<<number_of_pairs()<<endl;
	return 0;
}