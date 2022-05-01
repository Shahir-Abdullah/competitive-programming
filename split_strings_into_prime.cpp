#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

map<int, bool> sieve(int n){
	map<int, bool> primes;
	
	vector<bool> isprime(n+1, true);
	
	isprime[0] = false;
	isprime[1] = false;

	
	for(int i = 2; i*i <= n; i++){
		if(isprime[i] == false)continue;
		for(int j = i*i; j <= n; j+=i){
			isprime[j] = false;
		}
	}
	for(int i = 2; i <= n; i++){
		if(isprime[i] == true){
			primes.insert({i, true});
		}else{
			primes.insert({i, false});
		}
	}
	return primes;
}
int ways(string s, map<int, bool> primes){
	int n = s.length();
	vector<int> dp(n+1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(s[i-1] != '0' && primes[stoi(s.substr(i-1, 1))] == true){
			dp[i] = dp[i-1];
		}
		if(i-2 >= 0 && s[i-2] != '0' && primes[stoi(s.substr(i-2, 2))] == true){
			dp[i] = (dp[i] + dp[i-2])% mod;
		}
		if(i-3 >= 0 && s[i-3] != '0' && primes[stoi(s.substr(i-3, 3))] == true){
			dp[i] = (dp[i] + dp[i-3]) % mod;
		}
	}
	
	return dp[n];
}
int main()
{
	map<int, bool> primes = sieve(1000);
	string s;
	cin>>s;
	cout<<ways(s, primes)<<endl;
	return 0;
}