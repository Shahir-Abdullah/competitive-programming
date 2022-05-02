#include <bits/stdc++.h>
using namespace std;

int solution(){
	string s;
	cin>>s;
	int cntt = 0;
	int cnth = 0;
	int n = s.length();
	if(n < 3){
		return 0;
	}
	
	if(s[0] == 'T' && s[1] == 'H')cntt++;
	if(s[0] == 'H' && s[1] == 'T')cnth++;
	if(s[n-1] == 'T' && s[n-2] == 'H')cntt++;
	if(s[n-1] == 'H' && s[n-2] == 'T')cnth++;
	
	for(int i = 1; i < n-1; i++){
		if(s[i] == 'H' && s[i-1] == 'T' && s[i+1] == 'T')cnth++;
		else if(s[i] == 'T' && s[i-1] == 'H' && s[i+1] == 'H')cntt++;
	}
	
	return max(cntt, cnth);
}

int main(){
	cout<<solution()<<endl;
	return 0;
}