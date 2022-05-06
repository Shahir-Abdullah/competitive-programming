#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

int solution(){
	string s;
	cin>>s;
	int n = s.length();
	
	int ans = INF;
	int i = 0; 
	int j = s.length()-1;
	
	int zerocnt = 0;
	int onecnt = 0;
	
	int ansz = 0;
	int anso = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			ansz += onecnt;
			zerocnt++;
		}
		else{
			anso += zerocnt;
			onecnt++;
		}
		
	}
	return min(ansz, anso);
}
int main(){
	cout<<solution()<<endl;
	return 0;
}