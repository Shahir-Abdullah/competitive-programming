#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5 + 7;
const int M = 1e5 + 7;

vector<vector<int>> graph(N);
vector<int> degree(N, 0);

vector<int> get_possible_nodes(int n){
	vector<int> nodes;
	for(int i = 1; i <= n; i++){
		if(degree[i] >= 2){
			nodes.push_back(i);
		}
	}
	return nodes;
	
}

vector<pair<int, pair<int, int>>> get_all_trio(vector<int>& nodes){
	vector<pair<int, pair<int, int>>> result;
	for(int i = 0; i < nodes.size(); i++){
		for(int j = i+1; j < nodes.size(); j++){
			int a = nodes[i];
			int b = nodes[j];
			for(auto ac : graph[a]){
				for(auto bc : graph[b]){
					if(ac == bc){
						for(auto x : graph[a]){
							if(x == b){
								result.push_back({a, {b, ac}});
							}
						}
					}
				}
			}
		}
	}
	return result;
	
	
}

int calculate_degree(pair<int, pair<int, int>> &trio){
	int cnt = 0;
	cnt += degree[trio.first] - 2;
	cnt += degree[trio.second.first]- 2;
	cnt += degree[trio.second.second] - 2;
	return cnt;
}

int solution(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	vector<int> nodes = get_possible_nodes(n);
	vector<pair<int, pair<int, int>>> trios = get_all_trio(nodes);
	int ans = INF;
	for(auto trio : trios){
		ans = min(ans, calculate_degree(trio));
	}
	return ans;
}

int main(){
	cout<<solution()<<endl;
	return 0;
}