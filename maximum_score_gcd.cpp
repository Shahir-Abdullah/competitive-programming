#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b, a%b);
}

const int N = 1e6 + 5;

int maximum_score()
{
	int n;
	cin>>n;
	
	vector<int> a(n);
	vector<int> b(n);
	vector<int> gcd_array;
	vector<int> count_a(N, 0);
	vector<int> count_b(N, 0);
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
		count_a[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
		count_b[b[i]]++;
	}
	
	while(a.size() > 0){
	

	
	vector<int> mul_a(N, 0);
	vector<int> mul_b(N, 0);
	
	for(int i = 1; i < N; i++){
		int mxn = 0;
		for(int j = i; j < N; j += i){
			if(count_a[j] > 0){
				mul_a[i] = j;
			}
		}
	}
	
	for(int i = 1; i < N; i++){
		int mxn = 0;
		for(int j = i; j < N; j += i){
			if(count_b[j] > 0){
				mul_b[i] = j;
			}
		}
	}
	
	int ra, rb;
	
	for(int i = 1; i < N; i++){
		if(mul_a[i] > 0 && mul_b[i] > 0){
			ra = mul_a[i];
			rb = mul_b[i];
		}
	}
	
	gcd_array.push_back(gcd(ra, rb));
	
	for(auto x : a){
		if(x==ra){
			
		}
	}
	a.erase(find(a.begin(), a.end(), ra));
	b.erase(find(b.begin(), b.end(), rb));
		count_a[ra]--;
		count_b[rb]--;
	
	}
	
	sort(gcd_array.begin(), gcd_array.end());
	
	int maxscore = 0;
	
	for(int i = 0; i < gcd_array.size(); i++){
		maxscore += ((i+1) * gcd_array[i]);
	}
	
	return maxscore;
}

int main()
{
	cout<<maximum_score()<<endl;
	return 0;
}