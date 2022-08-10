https://practice.geeksforgeeks.org/problems/super-primes2443/1

int superPrimes(int n)
{
	int pp=n+2;
	vector<int>prime(pp, true);
	prime[0]=prime[1]=false;
	for(int i=2;i<pp;i++){
		if(prime[i]){
	           for(int j=i*2;j<pp;j+=i) //sieve of eratosthenes
	           	prime[j]=false;
	       }
	   }
	   
	   int ans=0;
	   for(int i=2;i<=n;i++)
	   	if(prime[i] && prime[i-2]) ans++;
	   
	return ans;
}