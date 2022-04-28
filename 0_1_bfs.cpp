#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int M = 1e5 + 7;
const int INF = 1e9;

int src, dst;

vector<pair<int, int>> graph[N];
vector<bool> visited(N, false);
vector<int> dist(N, INF);

int bfs_01(){
	dist[src] = 0;
	deque<int> dq;
	dq.push_front(src);
	while(!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		visited[u] = true;
		for(auto edge : graph[u]){
			int v = edge.first;
			int weight = edge.second;
			if(visited[v] == false && dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				if(weight == 1){
					dq.push_back(v);
				}else{
					dq.push_front(v);
				}
			}
		}
	}
	return (dist[dst] == INF)?-1:dist[dst];
}

int main()
{
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin>>x>>y;
		if(x==y)continue;
		graph[x].push_back({y, 0});
		graph[y].push_back({x, 1});
	}
	
	src = 1;
	dst = n;
	
	cout<<bfs_01()<<endl;
	
	return 0;
}