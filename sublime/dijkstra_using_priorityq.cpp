/* priority queue->
duplicates are allowed

priority_queue<int> pq;    ------> max heap
priority_queue<int , vector<int> , greater<int>> pq;  ----> min heap

pq.empty();
pq.push(43)
pq.size();
pq.top(); only way to access priority queue
pq.pop();



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int age;
    string name;
    student(int age , string name)
    {
        this->age = age;
        this-> name = name;
    }
    
};

 struct comp{
    bool operator()(student a , student b)
    {
     return a.age > b.age;
    }
    };
int main()
{
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(3);
    pq.push(3);
    pq.push(34);
    pq.push(1);
    pq.push(12);
    pq.push(76);


    while(!pq.empty())
    {
        //cout<<pq.top()<<" ";
        pq.pop();
    }

    //custom datatypes

    priority_queue<student , vector<student >, comp> pq1;
    pq1.push(student(12 , "ajay"));
    pq1.push(student(3 , "negi"));
    pq1.push(student(44, "india"));

    while(!pq1.empty())
    {
        cout<<pq1.top().name<<"  "<<pq1.top().age<<" "<<endl;
        pq1.pop();
    }

}*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int main()
{
    int n,m,w;
    cin>>n>>m;
    vector<pair<int , int>> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;

    int src;cin>>src;

    vector<int> dist(n+1 , N);

    dist[src] = 0;
    pq.push({ 0 , src});//wt  , src

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(auto it : adj[curr])  //pair<int,int>
        {
            if( dist[it.first] > wt + it.second)
            {
                dist[it.first] = wt + it.second;
                pq.push({ dist[it.first] , it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }   
}
/*


6 9
1 2 4
1 6 2
2 6 1
2 3 5
6 3 8
6 5 10
5 3 3
5 4 5
3 4 6


0 3 8 14 11 2


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,s,d,wt;
    cin>>n>>m;
    vector<int> dist(n+1, 1000);
    vector<pair<int,int>> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        cin>>s>>d>>wt;
        adj[s].push_back({d,wt});
       //adj[d].push_back({s,wt});
    }

    int source;cin>>source;
    dist[source] = 0;

    set<pair<int,int>> st;

    st.insert({0 , source});// wt , v

    while(!st.empty()){
        auto x = *(st.begin());
        st.erase(x);
        for(auto it : adj[x.second]){

            if(dist[it.first] >  it.second + dist[x.second]){
                
                st.erase({dist[it.first] , it.first});
                
                dist[it.first] = dist[x.second] + it.second;
                st.insert({dist[it.first] , it.first});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    
}*/