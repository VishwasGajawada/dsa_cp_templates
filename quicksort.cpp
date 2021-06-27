//https://cp-algorithms.com/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define vl vector<long>
#define vll vector<vl>
// #define l long int 
#define ll long long int
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define debug(x)  cerr << #x<<" "<<x<<endl;
// const int mod = 1e9+7;
#define pi pair<int,int>

int partition(vector<int>&arr,int l,int r){ 
    int i=l-1;
    int n = r-l+1;
    int random_pivot = rand()%n+l;
    swap(arr[random_pivot],arr[r]);
    for(int j=l;j<r;j++){
        if(arr[j]<arr[r]){
            i++;swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}
void solve(vector<int>&arr,int l,int r){
    if(l>r)return;
    int p = partition(arr,l,r);
    solve(arr,l,p-1);
    solve(arr,p+1,r);

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
    vector<int>arr = {5,6,-4,1,5,0};
    int n = arr.size();
    solve(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}