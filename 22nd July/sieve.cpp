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

void solve(){
    int n;
    cin>>n;
    bool prime[N];
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=4;i<=n;i+=2) prime[i]=false;
    for(int i=3;i<=n;i+=2){
        if(prime[i]==true){
            for(int j=i*i; j<=n; j+=i){
                prime[j]=false;
            }
        }
    }
    cout<<"Prime Numbers are : "<<endl;
    fr1(i,n) if(prime[i]==true) cout<<i<<" ";
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

