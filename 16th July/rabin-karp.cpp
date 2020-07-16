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

bool equals(string s1, string s2, int begin, int n1, int n2){
    fr(i,n2) if(s1[begin+i]!=s2[i]) return false ;
    return true;
}


void solve(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()<s2.length()){
        cout<<"0"<<endl;
        return;
    }else{
        int  n1=s1.length(), n2=s2.length();
        long long hashvals=0;
        long long s2_hashval=0;

        int factors[n2];
        factors[n2-1]=1;

        frn(i,n2-1) factors[i] = (factors[i+1]%mod * 10%mod)%mod;

        fr(i,s2.length()){
            s2_hashval = ((s2_hashval%mod) + ((int(s2[i]-'a')) *factors[i]%mod)%mod)%mod;
            hashvals = ((hashvals%mod) + ((int(s1[i]-'a')) *factors[i]%mod)%mod)%mod;
            cout<<int(s2[i]-'a')<<endl;
        }
        vector<int> ans;
        if(s2_hashval==hashvals){
            if(equals(s1,s2,0,n1,n2)) ans.push_back(1);
        }
        fr1(i,n1-n2){
            hashvals = ((((hashvals)%mod - (int(s1[i-1]-'a')*factors[0]%mod)%mod)%mod *10%mod)%mod + (int(s1[i+n2-1]-'a'))%mod)%mod;
            if(s2_hashval==hashvals) ans.push_back(i+1);
        }
        fr(i,ans.size()) cout<<ans[i]<<" "; cout<<endl;
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

