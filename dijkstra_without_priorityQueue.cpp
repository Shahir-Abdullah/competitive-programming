#include <bits/stdc++.h>
using namespace std;

int min_vertex(vector<int> &dist, vector<bool> &checked){
	int vertex = -1;
	int mind = INT_MAX;
	for(int i = 0; i < dist.size(); i++){
		if(checked[i] == false && (vertex == -1 || dist[i] < dist[vertex])){
			vertex = i;
		}
	}
	return vertex;
}

void printPath(vector<int>const &parent, int src, int dst){
	vector<int> path;
	for(int v = dst; v != src; v = parent[v]){
		path.push_back(v);
	}
	path.push_back(src);
	reverse(path.begin(), path.end());
	for(int i = 0; i < path.size(); i++){
		cout<<path[i]<<" --> ";
	}
	cout<<endl;
}
void dijkstra(vector<vector<pair<int, int>>> &graph, int src){
	int V = graph.size();
	vector<int> dist(V, INT_MAX);
	vector<int> parent(V, 0);
	vector<bool> checked(V, false);
	
	dist[src] = 0;
	parent[src] = src;
	
	for(int i = 0; i < V; i++){
		int vertex = min_vertex(dist, checked);
		//cout<<"min v is "<<vertex<<endl;
		if(dist[vertex] == INT_MAX){
			//isolated vertex 
			//cout<<"breaking out cause vertex"<<vertex<<" is "<<dist[vertex]<<endl;
			break;
		}
		
		checked[vertex] = true;
		//cout<<"vertex "<<vertex<<endl;
		for(auto &node: graph[vertex]){
			int to = node.first;
			int weight = node.second;
			//cout<<" relaxed weight "<<dist[vertex]+weight<<" current weight"<<dist[to]<<endl;
			if(dist[vertex]+weight < dist[to]){
				//cout<<"Vertex "<<to<<" relaxed"<<endl;
				dist[to] = dist[vertex]+weight;
				parent[to] = vertex;
				
			}
		}
		
		
	}
	
	printPath(parent, 0, 4);
	
}

int main()
{
	vector<vector<pair<int, int>>> graph = {
		{{1, 4}, {7, 8}},
		{{0, 4}, {2, 8}, {7, 11}},
		{{1, 8}, {8, 2}, {3, 7}, {5, 4}},
		{{2, 7}, {5, 14}, {4, 9}},
		{{3, 9}, {5, 10}},
		{{2, 4}, {3, 14}, {4, 10}},
		{{5, 2}, {7, 1}, {8, 6}},
		{{0, 8}, {1, 11}, {6, 1}, {8, 7}},
		{{2, 2}, {6, 6}, {7, 7}}
	};
//	for(int i = 0; i < 9; i++){
//		for(auto &node: graph[i]){
//			int to = node.first;
//			int weight = node.second;
//			cout<<"Vertex "<<i<<" connect to "<<to<<" cost is "<<weight<<endl;
//		}
//	}
	
	dijkstra(graph, 0);
}
