https://leetcode.com/problems/count-primes/
count between 1 to n
#include<bits/stdc++.h>
using namespace std;
void allPermutation(int n){
	if(n<=1)return 0;
	vector<bool>prime(n,true);
	prime[0]=prime[1]=false;
	for(int i=0;i<sqrt(n);i++){
		if(prime[i]==true){

			for(int j=i*i;j<n;j+=i){
				prime[j]=false;
			}

		}
	}
	return count(prime.begin(), prime.end(), true);
}
int main(){
	vector<int>arr;
	allPermutation(n);
}


https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1#
between n to m, print all,

bool isPrime(int n){
	if(n<2)return false;
	if(n%2==0)return (n==2);
	for(int i=3;i<=sqrt(n);i+=2)
		if(n%i==0)return false;

	return true;
}
vector<int> primeRange(int m, int n) {

	vector<int> ans;
        for(int i=m;i<=n;i++)  //O(n-m)*logn
        	if(isPrime(i))
        		ans.push_back(i);

    return ans;
}