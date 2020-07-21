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

void quick_sort(int arr[], int l, int r){
    int pivot = r;
    int i=l-1,j=l;
    if(l<r){
        while(j<pivot){
            if(arr[j]<arr[pivot]){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
            else j++;
        }
        i++;
        int temp = arr[pivot];
        arr[pivot] = arr[i];
        arr[i] = temp;
        quick_sort(arr,l,i-1);
        quick_sort(arr,i+1,r);
    }
}


void solve(){
    int n;
    cin>>n;
    int arr[N];
    fr(i,n) cin>>arr[i];
    quick_sort(arr, 0, n-1);
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

/*
1
10 
1 1 5 8 4 7 4 7 4 6
*/