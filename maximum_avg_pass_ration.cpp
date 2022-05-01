#include <bits/stdc++.h>
using namespace std;

// print with precision upto 10 decimal values :  cout<<fixed<<setprecision(10)<<ans<<endl;

double maximize_avg()
{
	int n;
	cin>>n;
	vector<pair<int, int>> classes(n);
	auto profit = [&](int p, int c){
		return (double)(p+1)/(double)(c+1) - ((double)p/(double)c);
	};
	priority_queue<pair<double, pair<int, int>>> pq;
	
	for(int i = 0; i < n; i++){
		int p, c;
		cin>>p>>c;
		classes[i] = {p, c};
		pq.push({profit(p, c), {p, c}});
	}
	
	int extra;
	cin>>extra;
	while(extra > 0){
		pair<double, pair<int, int>> class_ = pq.top();
		pq.pop();
		pq.push({profit(class_.second.first+1, class_.second.second+1), {class_.second.first+1, class_.second.second+1}});
		extra--;
	}
	
	double maximum_avg = 0.0;
	
	while(!pq.empty()){
		pair<double, pair<int, int>> class_ = pq.top();
		pq.pop();
		maximum_avg += ((double)class_.second.first/class_.second.second);
	}
	
	return maximum_avg/n;
	
}

int main()
{
	cout<<fixed<<setprecision(5)<<maximize_avg()<<endl;
	return 0;
}
