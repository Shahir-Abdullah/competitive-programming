#include <bits/stdc++.h>
using namespace std;

void generate_numbers(vector<int> &ara, int index, int num, int target){
	
	if(target < 0)return;
	
	if(target == 0){
		for(int i = 0; i < index; i++){
			cout<<ara[i]<<" ";
		}
		cout<<endl;
	}
	
	int prev = (index==0)?1:ara[index-1];
	for(int i = prev; i < num; i++){
		ara[index] = i;
		generate_numbers(ara, index+1, num, target-i);
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> ara(n);
	generate_numbers(ara, 0, n, n);
	return 0;
}