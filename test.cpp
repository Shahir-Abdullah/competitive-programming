#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int t;
	cin>>t;
	while(t--){
		long int n;
		cin>>n;
		int ara[n][5];
		for(long int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++){
				int k;
				cin>>k;
				ara[i][j] = k;
			}
		}
		vector<int> valids;
		for(int j = 0; j < 5; j++){
			long int s = 0;
			for(long int i = 0; i < n; i++){
				s += ara[i][j];
			}
			if(s >= n/2){
				valids.push_back(j);
			}
		}
		if(valids.size() < 2){
			cout<<"NO"<<endl;
		}else{
			bool ase = false;
			int ss = valids.size();
			for(int i = 0; i < ss; i++){
				for(int j = i+1; j < ss; j++){
					long int cnt = 0;
					for(long int ii = 0; ii < n; ii++){
						if((ara[ii][valids[i]] + ara[ii][valids[j]]) > 0){
							cnt++;
						}
						
					}
					if(cnt >= n){
						ase = true;
						break;
					}
				}
			}
			if(ase){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	
	}
}