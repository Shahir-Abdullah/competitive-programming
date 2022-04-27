#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int maxN = 5e5 + 7;

int ans = 0;
int src = 0;
int n, m, k;

vector<int> train(maxN, INF);
vector<int> dist(maxN, INF);
vector<bool> visited(maxN, false);
vector<bool> cantRemove(maxN, false);

int find_min_dist(){
	int v = -1;
	for(int i = 0; i < n; i++){
		if(visited[i] == false && (v == -1 || dist[i] < dist[v])){
			v = i;
		}
	}
	return v;
}

void dijkstra(vector<vector<pair<int, int>>>&graph){

	
	
	set<pair<int, int>> st;
	
	for(int i = 2; i <= n; i++){
		dist[i] = train[i];
		if(dist[i] != INF){
			cantRemove[i] = true;
		}
		st.insert({dist[i], i});
	}
	dist[1] = 0;
	st.insert({dist[1], 1});
	
	while(!st.empty()){
		int city = st.begin()->second;
		st.erase(st.begin());
		
		if(dist[city] == INF)break;
		if(cantRemove[city]==true)ans++;
	
		
		visited[city] = true;
		
		
		for(auto x : graph[city]){
			int to = x.first;
			int len = x.second;
			
			if(visited[to] == false && dist[city] + len <= dist[to]){
				st.erase({dist[to], to});
				dist[to] = dist[city] + len; 
				st.insert({dist[to], to});
				
				cantRemove[to] = false;
			}
		}
		
	}
	
	return;
	
}

int main()
{
	cin>>n>>m>>k;
	
	train.assign(maxN, INF);
	dist.assign(maxN, INF);
	visited.assign(maxN, false);
	cantRemove.assign(maxN, false);
	
	vector<vector<pair<int, int>>> graph(maxN);
	
	for(int i = 0; i < m; i++){
		int u, v, x;
		cin>>u>>v>>x;
		graph[u].push_back(make_pair(v, x));
		graph[v].push_back(make_pair(u, x));
	}
	
	
	for(int i = 0; i < k; i++){
		int s, y;
		cin>>s>>y;
		train[s] = min(train[s], y);
	}
	
	dijkstra(graph);
	cout<<k-ans<<endl;
	
	return 0;
	
}
