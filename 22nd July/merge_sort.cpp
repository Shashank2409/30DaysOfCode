#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frn(i,n) for(int i=n-1;i>=0;i--)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define frn1(i,n) for(int i=n;i>0;i--)
#define N 100002
#define ll long long
#define mid(a,b) a+(b-a)/2
#define INF 1000000003

void merge(int arr[], int l, int m, int r){
    int left[m-l+2], right[r-m+1];
    for(int i=l;i<=m;i++) left[i-l]=arr[i];
    for(int j=m+1;j<=r;j++) right[j-m-1]=arr[j];
    left[m-l+1]=right[r-m]=INF;

    int i=0,j=0,k=l;
    while(i<m-l+2 && j<r-m+1 && k<=r){
        if(left[i]<right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
}

void merge_sort(int arr[], int n, int l, int r){
    if(r>l){
        merge_sort(arr, n , l, mid(l,r));
        merge_sort(arr, n , mid(l,r)+1, r);
        merge(arr,l,mid(l,r),r);
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[N];
    fr(i,n) cin>>arr[i];
    merge_sort(arr,n,0,n-1);
    fr(i,n) cout<<arr[i]<<" ";
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}

