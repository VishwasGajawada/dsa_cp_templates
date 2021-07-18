#include <bits/stdc++.h>
using namespace std;

void solve(int test = 1){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    int a,b;
    //a task before b task
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].emplace_back(b);
        indegree[b]++;
    }
    queue<int>q;
    vector<int>order;
    while(!q.empty()){
        int u =q.front();q.pop();
        order.emplace_back(u);
        for(int v : g[u]){
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
    }
    for(int x : order)cout<<x<<" ";
    cout<<endl;
}
