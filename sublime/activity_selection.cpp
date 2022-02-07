//activity selection problem find out maximum number of job can be scheduled;

#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    if(a[1]==b[1])
        return a[0]<b[0];
    else
        return a[1]<b[1];
}

int main(){
    int n,s,e;cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end() ,cmp);
    for(int i=0;i<n;i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }
    int take=1;
    int end = v[0][1];
    for(int i=1;i<n;i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }

cout<<take;
}

/*
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second<b.second;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> v;
    int s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        v.push_back({s,e});
    }

    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i][0] , v[i][1]});
    }

    sort(vp.begin(),vp.end(),cmp);

    for(auto it : vp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    int take=1;
    int end = vp[0].second;
    for(int i=1;i<n;i++){
        if(vp[i].first >= end){
            take++;
            end = vp[i].second;
        }
    }
cout<<take;
}
*/