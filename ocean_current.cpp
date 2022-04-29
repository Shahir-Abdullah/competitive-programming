#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e3 + 5;
const int INF = 1e9;

vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

vector<vector<int>> dist(N, vector<int> (M, INF));

vector<string> grid(N);

int rs, cs, rd, cd;
int row, col;

void boat_bfs_01(){
	dist[rs][cs] = 0;
	deque<pair<int, int>> dq;
	dq.push_front({rs, cs});
	
	auto isvalid = [&](int r, int c){
		return (r >= 0 && r < row && c >= 0 && c < col);
	};
	
	while(!dq.empty()){
		pair<int, int> cell = dq.front();
		dq.pop_front();
		int r = cell.first;
		int c = cell.second;
		
		for(int i = 0; i < directions.size(); i++){
		
			int newr = r + directions[i].first;
			int newc = c + directions[i].second;
			
			if(isvalid(newr, newc) == false)continue;
			
			int weight = ((int)grid[r][c]-'0' == i)?0:1;
			
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
	
	cout<<dist[rd][cd]<<endl;
	return;
	
}

int main()
{
	cin>>row>>col;
	for(int i = 0; i < row; i++){
		cin>>grid[i];
	}
	int t;
	cin>>t;
	while(t--){
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				dist[i][j] = INF;
			}
		}
		cin>>rs>>cs>>rd>>cd;
		rs--;
		cs--;
		rd--;
		cd--;
		boat_bfs_01();
	}
	
}