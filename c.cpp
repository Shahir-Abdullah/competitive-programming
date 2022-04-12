#include <bits/stdc++.h>


using namespace std;

int ascii(char ch){
	if(ch >= '0' && ch <= '9'){
		return (int)ch-'0';
	}else{
		return (int)ch - 'A' + 10;
	}
}
char tochar(int x){
	return (char) x +'0';
}
void solve(){
	string s;
	int a, b;
	cin>>s>>a>>b;
	int adecimal = 0;
	reverse(s.begin(), s.end());
	long long int p = 0;
	for(int i = 0; i < s.length(); i++){
		adecimal += (ascii(s[i]) * pow(a, p));
		p++;
	}
	//cout<<adecimal<<endl;
	string result;
	while(adecimal){
		long long int x = adecimal%b;
		adecimal /= b;
		result.push_back(tochar(x));
	}
	reverse(result.begin(), result.end());
	cout<<result<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	return 0;
}