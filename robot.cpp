#include <bits/stdc++.h>

using namespace std;

void is_circular(){
	string s;
	cin>>s;
	int n = s.length();
	int count_l = 0;
	int count_r = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'L')count_l++;
		else if(s[i] == 'R')count_r++;
	}
	
	if(count_l == count_r)cout<<"false"<<endl;
	else cout<<"true"<<endl;
	return;
}

int main()
{
	is_circular();
	return 0;
}