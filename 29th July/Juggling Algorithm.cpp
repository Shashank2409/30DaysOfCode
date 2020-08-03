#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    int noOfSets = __gcd(n , k);
    
    if(noOfSets == n)
        return ;
    
    for(int start = 0; start < noOfSets; start++){
        int startSet = start , temp = nums[start] , next;
        do{
            next = nums[(startSet + k)%n];
            nums[(startSet + k)%n] = temp;
            temp = next;
            startSet = (startSet + k)%n;
        }while(start != startSet);
    }
}

int main(){
	long long n , rotations;
	cin>>n>>rotations;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin>>nums[i];
	rotate(nums , rotations);
	for(int i = 0; i < n; i++)
		cout<<nums[i]<<" ";
}
