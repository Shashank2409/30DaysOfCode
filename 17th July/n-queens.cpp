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

bool checkpossible(bool arr[101][101], int n, int row, int col){
    
    int diff= row-col;
    int sum = row+col;
    fr(i,n){
        if(arr[i][col] == true) return false;
        int col1 = i - diff;
        int col2 = sum - i;
        if(arr[i][col1]==true || arr[i][col2]==true) return false;
    }
    return true;
}

bool nqueens(bool arr[101][101], int curr, int n){
    if(curr == n)
        return true;
    fr(i,n){
        if(checkpossible(arr,n,curr,i)){
            arr[curr][i]=true;
            if(!nqueens(arr,curr+1,n)) arr[curr][i] = false;
            else return true;
        }
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    bool arr[101][101]={false};
    nqueens(arr,0,n);
    fr(i,n) {
        fr(j,n) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
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

