#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define ll long long
#define N 1005
#define M 1000000009
#define pi pair<int,int>
#define F first
#define S second
#define pb push_back
#define ld long double
#define inf 200000000009
#define pii pair<pi,pi>
//||

//"\n"
string s[N];
int n,m,k;
int d[N][N][4];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m || s[x][y]=='#')
        return 0;
    return 1;
}
void bfs(int x,int y)
{
    int j;
    deque<pii> q;//x,y,dir,dist(k waala)
    q.push_front({{x,y},{0,0}});
    q.push_front({{x,y},{1,0}});
    q.push_front({{x,y},{2,0}});
    q.push_front({{x,y},{3,0}});

    d[x][y][0]=1;
    d[x][y][1]=1;
    d[x][y][2]=1;
    d[x][y][3]=1;


    while(!q.empty())
    {
        pii x=q.front();

        int x1=x.F.F;
        int y1=x.F.S;
        int d1=x.S.F;
        int dist=x.S.S;


        q.pop_front();



        for(j=0;j<4;j++)
        {
            if(check(x1+dx[j],y1+dy[j]))
            {
                
                int newr = x1+dx[j];
                int newc = y1+dy[j];
                int newd = j;
                
                int weight = (d1 == j && dist < k)?0:1;
                
                if(d[x1][y1][d1] + weight < d[newr][newc][newd])
                {
                	d[newr][newc][newd] = d[x1][y1][d1] + weight;
                	
                	if(weight == 0){
                		q.push_front({{newr,newc},{newd,dist+1}});
                	}else{
                		q.push_back({{newr,newc},{newd,1}});
                	}
                    
                }
            }
        }
    }

}

main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
int i,ans=(int)1e9,j;
cin>>n>>m>>k;


for(i=0;i<n;i++)
    cin>>s[i];
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    for(int gg=0;gg<4;gg++)
        d[i][j][gg]=(int)1e9;

x1--;
y1--;
x2--;
y2--;
bfs(x1,y1);
if(x1==x2 && y1==y2)
{cout<<0<<endl;
return 0;}

//cout<<d[0][2][1]<<endl;
for(j=0;j<4;j++)
    ans=min(ans,d[x2][y2][j]);
    if(ans==(int)1e9)
        cout<<-1;
    else
cout<<ans;

    return 0;
}