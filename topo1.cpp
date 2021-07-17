#include <bits/stdc++.h>
using namespace std;

enum COLORS{WHITE=0, GRAY=1, BLACK=2};

bool hasCycle(vector<vector<int>>&g,int u,vector<int>&colors){
    colors[u] = GRAY;
    for(int v : g[u]){
        if(colors[v]==GRAY)return true;
        else if(colors[v]==WHITE){
            if(hasCycle(g,v,colors))return true;
        }
    }
    colors[u] = BLACK;
    return false;
}

bool hasCycle(vector<vector<int>>&g ,int n){
    vector<int>colors(n+1,WHITE);
    for(int i=1;i<=n;i++){
        if(colors[i]==WHITE){
            if(hasCycle(g,i,colors))return true;
        }
    }
    return false;
}

void topo(vector<vector<int>>&g,int u,vector<int>&visit,stack<int>&order){
    visit[u] = 1;
    for(int v : g[u]){
        if(visit[v]!=1)topo(g,v,visit,order);
    }
    order.push(u);
}

void solve(int test = 1){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].emplace_back(b);
    }

    if(hasCycle(g,n)){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    stack<int>order;
    vector<int>visit(n+1,0);
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            topo(g,i,visit,order);
        }
    }
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
    cout<<endl;

}

