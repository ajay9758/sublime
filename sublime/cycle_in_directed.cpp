#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[] , bool vis[] , bool order[], int n){

    vis[n] = true;
    order[n] = true;

    for(auto it : adj[n]){
        if(!vis[it]){
            if(dfs(adj,vis,order,it))
                return true;
        }
        else if(order[it] == true)
            return true;
    }
    order[n] = false;
    return false;
}

bool fun(vector<int> adj[] , int n){

    bool vis[n];memset(vis,false,sizeof vis);
    bool order[n];memset(order,false,sizeof order);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,order,i))
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n,m,u,v;
    cin>>n>>m;
    std::vector<int> adj[n];

    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    cout<<fun(adj , n);
    return 0;
}