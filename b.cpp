#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

//usr/bin/python3.8 /home/shahir/Projects/Python-Projects/Personal/TimerApp/timerapp.py 
int intlog(double base, double x) { //log of x of base base
    return (int)(log(x) / log(base));
}
int moduler(int base, int power, int mod){ // calculates base^power % mod
        int x = 1;
        int e = base%mod;
        for(int i = 0; i <= 31; i++){
                if(power & (1<<i)){
                     x = (x*e)%mod;   
                }
                e = (e*e)%mod;
        }
        return x;
}
int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b, a%b);
}



int main()
{
	IOS;
    int t;
    cin>>t;
    while(t--){
		long int n;
		cin>>n;
		long long int sum = 0;
		vector<long int> v(n, 0);
		for(long int i = 0; i < n; i++){
		    cin>>v[i];
		}
		sort(v.begin(), v.end());
		
		long long int redsum = 0;
		long long int bluesum = v[0];
		long long int j = 1;
		bool nai = true;
		for(long int i = n-1; i > n/2; i--){
			redsum += v[i];
			bluesum += v[j++];
			
			if(redsum > bluesum){
				nai = false;
				break;
			}
			
		}
		if(nai == true){
			cout<<"NO"<<'\n';
		}else{
			cout<<"YES"<<'\n';
		}
		
    	
    }
    
    return 0;
    
    
    
}
	