#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstring>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frn(i,n) for(int i=n-1;i>=0;i--)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define frn1(i,n) for(int i=n;i>0;i--)
#define N 100002
#define ll long long
#define mid(a,b) a+(b-a)/2

int block_size;

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first/block_size<b.first/block_size) return true;
    else if(a.first/block_size==b.first/block_size) if(a.second>b.second) return true;
    return false;
}

void solve(){
    int n;
    cin>>n;
    int arr[N];
    fr(i,n) cin>>arr[i];
    int q;
    cin>>q;
    vector<pair<int,int>> queries;
    int l,r;
    fr(i,q){
        cin>>l>>r;
        queries.push_back({l,r});
    }
    block_size = sqrt(q); 
    sort(queries.begin(), queries.end(), cmp);
    int ml=0,mr=-1, sum=0;
    fr(i,q){
        while(mr<queries[i].second){
            mr++;
            sum+=arr[mr];
        }
        while(mr>queries[i].second){
            sum-=arr[mr];
            mr--;
        }
        while(ml<queries[i].first){
            sum-=arr[ml];
            ml++;
        }
        while(ml>queries[i].first){
            ml--;
            sum+=arr[ml];
        }
        cout<<"Sum in the range "<<queries[i].first<<" "<<queries[i].second<<" : "<<sum<<endl;
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

