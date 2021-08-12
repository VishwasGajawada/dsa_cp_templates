#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>
#define ll long long int
#define pb push_back
#define ff first
#define ss second

#define endl "\n"
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
const int mod = 1e9+7;


void prims(vector<vector<int>>&edges,vector<int>&weights,int vertices){
    int n = vertices;
    vector<pair<int,int>>g[n+1];
    for(int i=0;i<edges.size();i++){
        g[edges[i][0]].push_back({edges[i][1],weights[i]});
        
        g[edges[i][1]].push_back({edges[i][0],weights[i]});
    }
    vector<int>dist(n+1,INT_MAX),visit(n+1,0);
    int src=1; //random
    dist[src] = 0;
    set<pair<int,int>>s;
    for(int i=1;i<=n;i++)s.insert({dist[i],i});

    int mst_cost = 0;

    for(int i=1;i<=n;i++){
        if(s.empty()){
            cout<<"NO MST"<<endl;
            return;
        }
        auto [w2,u] = *s.begin();
        s.erase(s.begin());
        visit[u] = true;
        mst_cost+=w2;
        
        cout<<u<<" "<<w2<<endl;

        for(auto [v,w] : g[u]){
            if(!visit[v] && dist[v] > w){
                s.erase({dist[v],v});
                dist[v] = w;
                s.insert({dist[v],v});
            }
        }
    }
    cout<<"mst cost : "<<mst_cost<<endl;

}
 
int main(){
    vector<vector<int>>edges;
    vector<int>weights;
    int n;//vertices

    n = 6;
    edges = {{1,2},{1,4},{1,5},{4,5},{2,4},{2,3},{3,4},{2,6},{3,6}};
    weights = {2,   1,      4,     9,   3,     3,    5,    7,   8};
    prims(edges,weights,n);
}
