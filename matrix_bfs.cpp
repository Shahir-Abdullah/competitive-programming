#include <bits/stdc++.h>
using namespace std;

const int N = 2005 + 7;
const int M = 2005 + 7;
const int INF = 1e9 + 7;

int n, m;
int r, c;
int x, y;

vector<string> matrix(N);
vector<vector<int>> dist(N, vector<int>(N, INF));
vector<vector<bool>> visited(N, vector<bool> (N, false));


void bfs(){

	deque<pair<int, int>> dq;
	
	dq.push_back({r, c});
	

	dist[r][c] = 0;
	
	auto isvalid = [&](int row, int col){
		return (row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] == '.');
	};
	
	vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	while(!dq.empty()){
	
		pair<int, int> cell = dq.front();
		int cell_r = cell.first;
		int cell_c = cell.second;
		dq.pop_front();
		
		if(visited[cell_r][cell_c] == true)continue;
		visited[cell_r][cell_c] = true;
		for(auto d : dir){
			int weight;
			if(d.second == -1){
				weight = 1;
			}else{
				weight = 0;
			}
			
			
			int v_r = cell_r + d.first;
			int v_c = cell_c + d.second;
			
			if(isvalid(v_r, v_c)==false)continue;
			
			if(dist[cell_r][cell_c] + weight < dist[v_r][v_c]){
				dist[v_r][v_c] = dist[cell_r][cell_c] + weight;
				
				if(weight==1){
					dq.push_back({v_r, v_c});
					//cout<<v_r<<","<<v_c<<" pushed back"<<endl;
				}else{
					dq.push_front({v_r, v_c});
					//cout<<v_r<<","<<v_c<<" pushed front"<<endl;
				}
				
				
			}
		}
	}
	
}

int main()
{
	cin>>n>>m;
	cin>>r>>c;
	r--;
	c--;
	cin>>x>>y;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		matrix[i] = s;
	}
	
	bfs();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '*')continue;
			if(dist[i][j] == INF)continue;
			//cout<<dist[i][j]<<" "<<dist[i][j] + (j-c)<<endl;
			int left = dist[i][j];
			int right = left + j - c;
			
			if(left <= x && right <= y)cnt++;
			
		}
	}
//	cout<<endl;
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < m; j++){
//			if(dist[i][j] <= x && dist[i][j] + j-c <= y){
//				cout<<"+";
//			}else{
//				cout<<matrix[i][j];
//			}
//		}
//		cout<<endl;
//	}
	cout<<cnt<<endl;
	return 0;
}