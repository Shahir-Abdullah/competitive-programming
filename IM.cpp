#include <bits/stdc++.h>
using namespace std;
struct Edge{
	long int src;
	long int dst;
};

class Graph{
	public:
		vector<vector<long int>> adjList;
		Graph(vector<Edge> const &edgeList, long int n){
			adjList.resize(n+1);
			for(auto &edge : edgeList){
				adjList[edge.src].push_back(edge.dst);
				adjList[edge.dst].push_back(edge.src);
			}
		}
};

void printGraph(Graph const &graph, long int n){
	
	for(long int i = 1; i <= n; i++){
		cout<<i<<" ---> ";
		for(auto vertex : graph.adjList[i]){
			cout<<vertex<<" ";
		}
		cout<<endl;
	}
}

void DFSUtil(Graph &graph, vector<long int> &visited, long int vertex){
	visited[vertex] = 1;
	//cout<<vertex<<" ";
	for(auto v : graph.adjList[vertex]){
		if(visited[v] == 0){
			DFSUtil(graph, visited, v);
		}
	}
	
}
vector<Edge> createEdgeList(vector<long int> &p, int n){
	vector<Edge> edgeList;
	for(long int i = 0; i < n; i++){
		if(p[i] != (i+1) && p[p[i]-1] ){
			edgeList.push_back({p[i], i+1});
		}
			
	}
	return edgeList;
}
int main()
{

	long int t;
	cin>>t;
	while(t--){
		long int n;
		cin>>n;
		vector<long int> p;
		for(long int i = 0; i < n; i++){
			long int p1;
			cin>>p1;
			p.push_back(p1);
		}
		vector<long int> visited(n+1, 0);
		vector<Edge> edgeList	= createEdgeList(p, n);
		Graph graph(edgeList, n);
//		cout<<"Graph "<<endl;
//		printGraph(graph, n);
//		cout<<"Connected components"<<endl;
		long int connectedComponents = 0;
		for(long int i = 1; i <= n; i++){
			if(visited[i] == 0){
				connectedComponents++;
				DFSUtil(graph, visited, i);
				//cout<<endl;
			}
		
		}
		cout<<connectedComponents<<endl;
		
	}
	
	
	
	
	
	//cout<<"Total number of connected components "<<connectedComponents<<endl;
	return 0;
	
}