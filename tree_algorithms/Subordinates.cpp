#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
ll dfs(vector<vector<ll>> &adj,ll i,vector<bool> &visited,vector<ll> &ans)
{
    visited[i]=true;
    for(auto x:adj[i]){
        if(!visited[x])
            ans[i]+=dfs(adj,x,visited,ans);
    }
    return ans[i]+1;
}
 
int main() {
    ll n;
    cin>>n;
    
    vector<vector<ll>> adj(n+1);
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    vector<ll> ans(n+1,0);
    vector<bool> visited(n+1,false);
    dfs(adj,1,visited,ans);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}