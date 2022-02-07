/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int parent[100];
vector<int> sz(100);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int n ){
    if(parent[n] == n)
     return n;

    return find(parent[n]);
}

void unionn(int x,int y){
    int a = find(x);
    int b = find(y);

    if(a!=b){
        if(sz[a]<sz[b])
            swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

bool iscycle(int n ,vector<pair<int,int>> &adj){    

    for(auto it : adj){

        int a = it.first;
        int b = it.second;

        int p1 = find(a);
        int p2 = find(b);

        if(p1 == p2)
            return 1;
        else
            unionn(a,b);
      } 
    return 0;
}

int main(){

    int n,m,u,v;
    cin>>n>>m;
    vector<pair<int,int>> adj;
    for(int i=0;i<n;i++){
        make_set(i);
    }

    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj.push_back({u,v});
        //adj.push_back({v,u});
    }

    cout<<iscycle(n , adj);
}
*/
/*
//second method for detecting cycle in a undirected graph 

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent , bool vis[] , vector<int> adj[]){

    vis[node] = true;
    bool flag = false;

    for(auto it :adj[node]){
        
        if(vis[it] && it==parent)
            continue;

        if(vis[it])
            return true;

        flag = flag || dfs(it,node,vis,adj);
    }
    return flag;
}

int main(){

    int n,m,u,v;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool vis[n];
    memset(vis,false,sizeof vis);
    bool x = false;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,0,vis,adj))
            {
                x = true;
                break;
            }
        }
    }
    cout<<(x?"yes cycle h":"no cycle nhi h");
}

/*
8 6
1 2
2 3
2 4
3 5
6 7
1 5 //yes cycle
*/


#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(checkForCycle(it, node, vis, adj)) 
                    return true; 
            }
        else if(it!=parent) 
            return true; 
    }
    return false; 
}

bool isCycle(int V, vector<int>adj[]){
        vector<int> vis(V+1, 0); 
        
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(checkForCycle(i, -1, vis, adj)) 
                    return true; 
            }
        }
    return false; 
}

int main() {
    
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        bool ans = isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
 
}
