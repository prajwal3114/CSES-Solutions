#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<char>> &v,vector<vector<bool>> &vis,int r,int c,int n,int m,queue<pair<int,int>> &q)
{
	vis[r][c]=true;
	{
    	pair<int,int> p=q.front();
    	q.pop();
    	vector<int> v1={1,0,-1,0};
    	vector<int> v2={0,1,0,-1};
    	for(int i=0;i<4;i++)
    	{
    		int nrow=p.first+v1[i];
    		int ncol=p.second+v2[i];
    		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && v[nrow][ncol] == '.' && !vis[nrow][ncol]) {
    q.push({nrow, ncol});
    vis[nrow][ncol] = true;
    bfs(v, vis, nrow, ncol, n, m, q);
}
    	}
	}
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char>> v(n,vector<char>(m));
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>v[i][j];
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	queue<pair<int,int>> q;
	int rooms=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(v[i][j]=='.' && !vis[i][j])
		{
			q.push(make_pair(i,j));
			rooms++;
			bfs(v,vis,i,j,n,m,q);
		}
	}
	cout<<rooms<<"\n";
}