#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
const int INF = 1e9;

vector<vector<bool>> visited(N, vector<bool> (N, false));
vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int bfs(int sx, int sy, vector<vector<char>> &matrix){
	int steps = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {sx, sy}});
	
	int row = matrix.size();
	int col = matrix[0].size();
	
	auto isValid = [&](int r, int c){
		return (r >= 0 && r < row && c >= 0 && c < col && matrix[r][c] != 'D');
	};
	while(!q.empty()){
		pair<int, int> cell = q.front().second;
		int dis = q.front().first;
		q.pop();
		int x, y;
		x = cell.first;
		y = cell.second;
		
		if(visited[x][y] == true)continue;
		visited[x][y] = true;
		
		for(auto d : directions){
			int newx = x + d.first;
			int newy = y + d.second;
			int newdis = dis + 1;
			if(isValid(newx, newy) == false)continue;
			
			if(matrix[newx][newy] == 'X'){
				return newdis;
			}
			
			q.push({newdis, {newx, newy}});
		}
		
	}
	return -1;
	
}

int main(){
	
	
	int srx = 0;
	int sry = 0;
	//cout<<"fine"<<endl;
	vector<vector<char>> matrix = {
		{'O', 'O', 'O', 'O'},
		{'D', 'O', 'D', 'O'},
		{'O', 'O', 'O', 'O'},
		{'X', 'D', 'D', 'O'}
	};
	cout<<bfs(srx, sry, matrix)<<endl;
	return 0;
	
}