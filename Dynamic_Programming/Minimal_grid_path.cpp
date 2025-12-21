#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<pair<int,int>> cur,nxt;
 
    cur.push_back({0,0});
    vis[0][0]=1;
 
    string ans;
    ans.push_back(a[0][0]);
 
    for(int step=0;step<2*n-2;step++){
        char best='Z';
        for(auto &p:cur){
            int x=p.first,y=p.second;
            if(x+1<n) best=min(best,a[x+1][y]);
            if(y+1<n) best=min(best,a[x][y+1]);
        }
        nxt.clear();
        for(auto &p:cur){
            int x=p.first,y=p.second;
            if(x+1<n && a[x+1][y]==best && !vis[x+1][y]){
                vis[x+1][y]=1;
                nxt.push_back({x+1,y});
            }
            if(y+1<n && a[x][y+1]==best && !vis[x][y+1]){
                vis[x][y+1]=1;
                nxt.push_back({x,y+1});
            }
        }
        ans.push_back(best);
        cur.swap(nxt);
    }
 
    cout<<ans<<"\n";
}