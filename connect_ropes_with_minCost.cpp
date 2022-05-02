#include <bits/stdc++.h>
using namespace std;

int solution(){
	int n;
	cin>>n;
	vector<int> ropes(n);
	for(int i = 0; i < n; i++){
		cin>>ropes[i];
	}
	priority_queue<int, vector<int>, greater<int>> min_heap;
	
	for(int i = 0; i < n; i++){
		min_heap.push(ropes[i]);
	}
	
	int cost = 0;
	while(min_heap.size() > 1){
		int r1 = min_heap.top();
		min_heap.pop();
		int r2 = min_heap.top();
		min_heap.pop();
		cost += r1+r2;
		cout<<"sofar cost "<<cost<<endl;
		min_heap.push(r1+r2);
	}
	return cost;
}

int main(){
	cout<<solution()<<endl;
	return 0;
}