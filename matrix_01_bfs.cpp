#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e3 + 5;
const int INF = 1e9 + 5;

vector<vector<int>> dist(N, vector<int> (M, INF));
vector<string> grid(N);

int src_r = 0, src_c = 0;
int R, C;

void bfs_01(){

	dist[src_r][src_c] = 0;
	deque<pair<int, int>> dq;
	dq.push_front({src_r, src_c});
	
	auto isvalid = [&](int r, int c){
		return (r >= 0 && r < R && c >= 0 && c < C);
	};
	
	vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int r, c;
	
	while(!dq.empty()){
	
		pair<int, int> cell = dq.front();
		r = cell.first;
		c = cell.second;
		dq.pop_front();
		
		for(auto d : dir){
			int newr = r+d.first;
			int newc = c+d.second;
			
			if(isvalid(newr, newc)==false)continue;
			
			int weight = (grid[r][c] == grid[newr][newc])?0:1;
			
			
			
			if(dist[r][c] + weight < dist[newr][newc]){
				dist[newr][newc] = dist[r][c] + weight;
				if(weight == 1){
					dq.push_back({newr, newc});
				}else{
					dq.push_front({newr, newc});
				}
			}
		}
	}
	
	cout<<dist[R-1][C-1]<<endl;
	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>R>>C;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				dist[i][j] = INF;
			}
		}
		for(int i = 0; i < R; i++){
			cin>>grid[i];
		}
		//cout<<"fine"<<endl;
		bfs_01();
	}
	return 0;
}