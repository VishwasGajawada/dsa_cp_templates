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
#define debug(x)  cerr <<#x<<" "<<x<<endl;
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

int solve(vector<int>&arr,int l,int r,int k){
    if(l>r) return INT_MAX;
    int p = partition(arr,l,r);
    int p_is = p-l+1; //p-l+1th smallest element in  [l,r]
    if(k==p_is) return arr[p];
    else if(k<p_is) return solve(arr,l,p-1,k);
    else return solve(arr,p+1,r,k-p_is);
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
    int k = 3; //find kth smallest element
    int ans = solve(arr,0,n-1,k);
    cout<<ans<<endl;

    return 0;
}