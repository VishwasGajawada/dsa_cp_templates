//https://cp-algorithms.com/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vl vector<long>
#define vll vector<vl>
#define l long int 
#define ll long long int
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define debug(x)  cerr << #x<<" "<<x<<endl;
// const int mod = 1e9+7;
#define pi pair<int,int>
 
void solve(vector<vector<int>>&edges,vector<int>&weights,int vertices,int start,int end){
    int n = vertices;
    vector<pair<int,int>>g[n];
    // map<pair<int,int>,int>weight;
    for(int i=0;i<edges.size();i++){
        g[edges[i][0]].push_back({edges[i][1],weights[i]});
        // weight[{edges[i][0],edges[i][1]}] = weights[i];
        
        //*****if undirected****//
        // g[edges[i][1]].push_back(edges[i][0]);
        // weight[{edges[i][1],edges[i][0]}] = weights[i];
    }
    vector<int>dist(n,INT_MAX);
    vector<bool>visit(n,false);
    vector<int>path(n,-1);  //not required generally ,.. but to visualise path from start to end
    priority_queue<pi,vector<pi>,greater<pi>>pq; //{weight and vertex}
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        visit[u] = true;
        for(auto [v,edge_w] : g[u]){
            if(!visit[v] && dist[v]>dist[u]+edge_w){
                dist[v] = dist[u]+edge_w;
                pq.push({dist[v],v});
                path[v] = u;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<dist[i]<<" ";
    //     if(i==n-1)cout<<endl;
    // }
    cout<<"Minimum weight of path from start to end is "<<dist[end]<<endl;

    int v = end;
    while(v!=-1){
        cout<<v<<" <- ";
        v = path[v];
    }
    cout<<endl;
}

//second way representing weights
void solve2(vector<vector<int>>&edges,vector<int>&weights,int vertices,int start,int end){
    int n = vertices;
    vector<int>g[n];
    map<pair<int,int>,int>weight;
    for(int i=0;i<edges.size();i++){
        g[edges[i][0]].push_back(edges[i][1]);
        weight[{edges[i][0],edges[i][1]}] = weights[i];
        
        //*****if undirected****//
        // g[edges[i][1]].push_back(edges[i][0]);
        // weight[{edges[i][1],edges[i][0]}] = weights[i];
    }
    vector<int>dist(n,INT_MAX);
    vector<bool>visit(n,false);
    vector<int>path(n,-1);  //not required generally ,.. but to visualise path from start to end
    priority_queue<pi,vector<pi>,greater<pi>>pq; //{weight and vertex}
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int w = pq.top().first , u = pq.top().second;
        pq.pop();
        visit[u] = true;
        for(auto v : g[u]){
            int edge_w = weight[{u,v}];
            if(!visit[v] && dist[v]>dist[u]+edge_w){
                dist[v] = dist[u]+edge_w;
                pq.push({dist[v],v});

                path[v] = u;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<dist[i]<<" ";
    //     if(i==n-1)cout<<endl;
    // }
    cout<<"Minimum weight of path from start to end is "<<dist[end]<<endl;

    int v = end;
    while(v!=-1){
        cout<<v<<" <- ";
        v = path[v];
    }
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt","r",stdin);
    //     freopen("out.txt","w",stdout);
    //     freopen("err.txt","w",stderr);
    // #endif
 
    // int t;cin >>t;
    // while(t--)solve();

    vector<vector<int>>edges;
    vector<int>weights;
    int n;//vertices
    int start,end;

    n = 6;
    edges = {{0,1},{0,2},{0,3},{1,5},{2,4},{3,1},{5,2}};
    weights = {1,   4,      3,     1,   1,     1,    1};
    start = 0;end = 2;
    solve(edges,weights,n,start,end);
    solve2(edges,weights,n,start,end);
    return 0;
}