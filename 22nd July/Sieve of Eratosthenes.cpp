#include<bits/stdc++.h>
using namespace std;

void printPrimeNos(int factor[] , int n){
	for(int i = 2; i <= n; i++)
	    if(factor[i] == i)
		    cout<<i<<" ";
	cout<<"\n";
}

void printPrimeFactors(int factor[] , int no , int n){
	while(no > 1){
		cout<<factor[no]<<" ";
		no = no / factor[no];
	}
	cout<<"\n";
}

int main(){
	long long n;
	cin>>n;
	
	int factor[n + 1];
	
	for(int i = 0 ; i <= n; i++)
	    factor[i] = i;
	    
	vector<int>primeNos;
	
	for(int i = 2; i * i <= n; i++){
		if(factor[i] == i){
			for(int j = i * i; j <= n; j += i)
				factor[j] = i;
		}
	}
	
	cout<<"Prime Nos up to "<<n<<endl;
	printPrimeNos(factor , n);
	
	/* For printing all the prime factors of a no */
	int no;
	cin>>no;
	printPrimeFactors(factor , no , n);
}
