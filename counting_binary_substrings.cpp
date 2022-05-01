#include <bits/stdc++.h>
using namespace std;



int solution(string s)
{
	int n = s.length();
	int zcnt = 0;
	int ocnt = 0;
	int cnt = 0;
	for(int i = 0; i < n-1; i++){
		if(s[i] == '0' && s[i+1] == '0'){
			zcnt++;
			if(ocnt > 0){
				cnt++;
				ocnt--;
				//cout<<"cnt incresed for 00 now is "<<cnt<<" zcnt "<<zcnt<<" ocnt "<<ocnt<<endl;
			}
		}else if(s[i] == '1' && s[i+1] == '1'){
			ocnt++;
			if(zcnt > 0){
				cnt++;
				zcnt--;
				//cout<<"cnt incresed for 1 now is "<<cnt<<" zcnt "<<zcnt<<" ocnt "<<ocnt<<endl;
			}
		}else{
			cnt++;
			//cout<<"cnt incresed for 01/10 now is "<<cnt<<endl;
		}
	}
	
	return cnt;
}

int main()
{
	string s;
	cin>>s;
	
	int ans = solution(s);
	
//	for(auto ss : substrings){
//		cout<<ss<<endl;
//	}
	cout<<ans<<endl;
	return 0;
}