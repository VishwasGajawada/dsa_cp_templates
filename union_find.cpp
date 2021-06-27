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

// ********normal variant******** takes O(n) worst case
// int find(vector<int>&arr,int x){
//     if(arr[x]==-1)return x;
//     return find(arr,arr[x]);
// }
// void uni(vector<int>&arr,int x,int y){
//     if(arr[x]==-1)arr[x] = y;
//     else if(arr[y]==-1)arr[y] = x;
//     else arr[find(arr,x)] = arr[find(arr,y)];
// }

// *********** rank and path compresssion********** takes O(logn)
struct subset{
    int parent;
    int rank;
};

int find(vector<subset>&arr,int x){
    //PATH COMPRESSION : 
    // find root and make root as parent of x to have less path next time
    if(arr[x].parent != x)
        arr[x].parent = find(arr,arr[x].parent);
    return arr[x].parent;
}

void uni(vector<subset>&arr,int x,int y){
    //UNION BY RANK : 
    //attach smaller rank tree under higher rank tree
    
    if(arr[x].rank < arr[y].rank){
        arr[x].parent = y;
    }else if(arr[x].rank > arr[y].rank){
        arr[y].parent = x;
    }else{
        arr[y].parent = x;
        arr[x].rank++;
    }
}
// void uni(int s[],int ranks[],int a, int b) {
//     a = find(s,a);
//     b = find(s,b);
    
//     if (ranks[a] >= ranks[b]) {
//         s[b] = a; 
//         ranks[a]++;
//     }
//     else {
//         s[a] = b; 
//         ranks[b]++;
//     }
// }

//cycle detection
void solve(vector<vector<int>>&edges,int n){
    vector<subset>arr(n);
    for(int i=0;i<n;i++){
        arr[i].parent = i;
        arr[i].rank = 0;
    }
    
    for(int i=0;i<edges.size();i++){
        int x_set = find(arr,edges[i][0]);
        int y_set = find(arr,edges[i][1]);
        if(x_set == y_set){
            cout<<"Cycle formed at edge "<<edges[i][0]<<" - "<<edges[i][1]<<endl;
            return;
        }
        cout<<edges[i][0]<<" - "<<edges[i][1]<<endl;
        uni(arr,x_set,y_set);
    }

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
    int n;//vertices

    n = 6;
    edges = {{0,1},{0,2},{0,3},{1,5},{2,4},{3,1},{5,2}};
    solve(edges,n);
    return 0;
}