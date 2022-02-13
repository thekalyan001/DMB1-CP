    KNAPSACK PROBLEM HAI PURE

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Best Time to Buy and Sell Stock

Simply keep track of min of previous and keep calculating the different from the current element

int maxProfit(vector<int>& arr) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int maxPro=0,mn=INT_MAX,n=arr.size();
	for(int i=0;i<n;i++)
	{
		mn=min(mn,arr[i]);
		maxPro=max(maxPro,arr[i]-mn);
	}
	return maxPro;
}

--------------------------------------Best Time to Buy and Sell Stock II---------------------------------------------------
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

if next day prices is greater then current then take buy the today and sell next day
	int maxProfit(vector<int>& prices) {
		int proFit=0;
		for(int i=1;i<prices.size();i++){
			if(prices[i]>prices[i-1])
				proFit+=prices[i]-prices[i-1];
		}
		return proFit;
	}

	---------------------------------------Best Time to Buy and Sell Stock III-----------------------------------------------------------

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Naive- Using Recursion- TLE
given transation shoud be atmost 2

check if we have not bought any item then hold==0 then we will eigher buy means include or dont buy disclude it
if we have bought then hold==1 then either we will sell it or dont sell it if selling means transation++, bcox buy+sell=transation

	int maxPro(vector<int>& prices,int i,int hold, int total_traction){
		if(total_traction>=2 || i>=prices.size())return 0;

        if(hold==0){ //didnt buy any item
            int opt1=maxPro(prices,i+1,1,total_traction)-prices[i]; //wither buy it
            int opt2=maxPro(prices,i+1,0,total_traction); //dont buy it
            return max(opt1,opt2);
        }
        else if(hold==1){
            int opt1=prices[i]+maxPro(prices,i+1,0,total_traction+1); //sell it- bech diye to traction complete
            int opt2=maxPro(prices,i+1,1,total_traction); //don't sell it
            return max(opt1,opt2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        return maxPro(prices,0,0,0); //ith day, holding?, total traction
    }


DP_ ☑☑☑☑
    item, hold, transation
int dp[100004][2][3]; // 10004-item size, 2-(hold true, unhold false), 3 max transaition 2 to 1bda kr 

int maxPro(vector<int>& prices,int i,int hold, int total_transation){
	if(total_transation>=2 || i>=prices.size())return 0;

	if(dp[i][hold][total_transation]!=-1)
		return dp[i][hold][total_transation];

        if(hold==0){ //didnt buy any item
            int opt1=maxPro(prices,i+1,1,total_transation)-prices[i]; //wither buy it
            int opt2=maxPro(prices,i+1,0,total_transation); //dont buy it
            return dp[i][hold][total_transation]=max(opt1,opt2);
        }
        else if(hold==1){
            int opt1=prices[i]+maxPro(prices,i+1,0,total_transation+1); //sell it- bech diye to traction complete
            int opt2=maxPro(prices,i+1,1,total_transation); //don't sell it
            return dp[i][hold][total_transation]=max(opt1,opt2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {

    	for(int i=0;i<100004;i++){
    		for(int j=0;j<2;j++){
    			for(int k=0;k<3;k++){
    				dp[i][j][k]=-1;
    			}
    		}
    	}
        return maxPro(prices,0,0,0); //ith day, holding?, total traction
    }

    --------------------------------------------------Best Time to Buy and Sell Stock IV--------------------------------------------------------------------------------

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Same as Stock III above but instead of 2 transation we can do atmost k transation  so change instead of 2 we should change it to k
Using Recursion- TLE

int maxPro(vector<int>& prices,int i,int hold, int total_traction){
		if(total_traction>=k || i>=prices.size())return 0; //here changes compare to stock III

        if(hold==0){ //didnt buy any item
            int opt1=maxPro(prices,i+1,1,total_traction)-prices[i]; //wither buy it
            int opt2=maxPro(prices,i+1,0,total_traction); //dont buy it
            return max(opt1,opt2);
        }
        else if(hold==1){
            int opt1=prices[i]+maxPro(prices,i+1,0,total_traction+1); //sell it- bech diye to traction complete
            int opt2=maxPro(prices,i+1,1,total_traction); //don't sell it
            return max(opt1,opt2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        return maxPro(prices,0,0,0); //ith day, holding?, total traction
    }



DP_ ☑☑☑☑

int dp[1001][2][101];
    int maxPro(vector<int>& prices,int i,int hold, int total_traction, int k){
		if(total_traction>=k || i>=prices.size())return 0;

        if(dp[i][hold][total_traction]!=-1)
            return dp[i][hold][total_traction];
        
        if(hold==0){ //didnt buy any item
            int opt1=maxPro(prices,i+1,1,total_traction,k)-prices[i]; //wither buy it
            int opt2=maxPro(prices,i+1,0,total_traction,k); //dont buy it
            return dp[i][hold][total_traction]=max(opt1,opt2);
        }
        else if(hold==1){
          int opt1=prices[i]+maxPro(prices,i+1,0,total_traction+1, k); //sell it- bech diye to traction complete
          int opt2=maxPro(prices,i+1,1,total_traction, k); //don't sell it
            return dp[i][hold][total_traction]=max(opt1,opt2);
        }
        return 0;
    }
    int maxProfit(int k,vector<int>& prices) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return maxPro(prices,0,0,0,k); //ith day, holding?, total traction
    }

----------------------Best Time to Buy and Sell Stock with Transaction Fee--------------------------------------------------------------------------------
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

m1
Recursion-

Yhan pr transation k unlimited hai to dp ka ek parameter remove ho gya k so only two variable constrain

ith day and hold?

int rec(vector<int>prices, int i,bool hold,int fee){

    //base condition
    if(i>=prices.size())
        return 0;

    if(hold==0){
        int opt1=rec(prices,i+1,1,fee)-prices[i]; //khreed liye so hold=1 and prices kam ho gya
        int opt2=rec(prices,i+1,0,fee); //nhi khreede
        return max(opt1,opt2);
    }
    if(hold==1){
        int opt1=rec(prices,i+1,0,fee)+(prices[i]-fee); //bech liye so hold=0 and fee dena pdega profit me se
        int opt2=rec(prices,i+1,1,fee); //nhi beche so no transation done
        return max(opt1,opt2);
    }
    //aise hi de diye nhi to bolega int function should retuen
    return 0;
}
int maxProfit(vector<int>& prices, int fee) {
        return rec(prices,0,0,0,fee); //price, day, hold?, fee
    }


DP_ ☑☑☑☑

int dp[500005][2];
   int rec(vector<int> &prices,int i,bool hold,int fee){
       
       // BASE CONDITION
       if(i>=prices.size()){
           return 0;
       }
       if(dp[i][hold]!=-1){
           return dp[i][hold];
       }
       
       // CURRENTLY JAVENT BOUGHT THE STOCK
       if(hold == 0){
           int op1 =   rec(prices,i+1,1,fee) - prices[i];
           int op2 =  rec(prices,i+1,0,fee);
           
           return  dp[i][hold]= max(op1,op2);
       }
       // STATE OF SELLING THE STOCK
       else if(hold == 1){
           
           int op1 = rec(prices,i+1,0,fee)+ (prices[i]-fee);
           int op2 = rec(prices,i+1,1,fee);
           
           return dp[i][hold]= max(op1,op2);
       }
       return 0;       
   }
    int maxProfit(vector<int>& prices, int fee) {
        for(int i=0;i<500005;i++){
            for(int j=0;j<2;j++){
                    dp[i][j]=-1;            
            }
        }
        return rec(prices,0,0,fee); //price, day, hold?, fee
    }

----------------------Best Time to Buy and Sell Stock with Cooldown--------------------------------------------------------------------------------
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Same as transation fee but can not sell next day so after selling call i+1 instead of i thats it
and fee bhi nhi lgana h

recursion- TLE

int rec(vector<int>& prices,int day, bool hold){
        //base case
        if(day>=prices.size()){
            return 0;
        }
        
        if(hold==0){ //nhi khreede h
            int opt1=rec(prices,day+1,1)-prices[day]; //khreed rhe h
            int opt2=rec(prices,day+1,0); //nhi khreed rhe h
            return max(opt1,opt2);
        }
        if(hold==1){
            int opt1=rec(prices,day+2,0)+prices[day]; //bech diye to hold=0 and we cant sell next day to i+2
            int opt2=rec(prices, day+1,1); //nhi bech rhe h
            return max(opt1,opt2);
        }
        
        //int fun should return someting 
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        return rec(prices, 0, 0);
    }

DP_☑☑☑☑

//ith day and hold?
    int dp[5001][2];
    int rec(vector<int>& prices,int day, bool hold){
        //base case
        if(day>=prices.size()){
            return 0;
        }
        
        if(dp[day][hold]!=-1)
            return dp[day][hold];
        if(hold==0){
            int opt1=rec(prices,day+1,1)-prices[day];
            int opt2=rec(prices,day+1,0);
            return dp[day][hold]=max(opt1,opt2);
        }
        if(hold==1){
            int opt1=rec(prices,day+2,0)+prices[day]; //bech diye to hold=0 and we cant sell next day to i+2
            int opt2=rec(prices, day+1,1); //nhi bech rhe h
            return dp[day][hold]=max(opt1,opt2);
        }
        
        //int fun should return someting 
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<5001;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
        return rec(prices, 0, 0);
    }