#include <bits/stdc++.h>

using namespace std;

string solution(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	string ss;
	for(int i = 0; i < s.length(); i++){
		int j = (s[i] - 'A' - k);
		if(j < 0){
			j = 26 + j;
		}
		ss.push_back('A' + j);
	}
	return ss;
}

int main()
{
	cout<<solution()<<endl;
	return 0;
}