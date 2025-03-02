//Link: https://leetcode.com/problems/climbing-stairs/description/

//tabular
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];

        if(n==0 || n==1 || n==2 || n==3){
            return n;
        }

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};

//memoization
class Solution {
public:
    int dp[46];

    int solve(int n){
        if(n==0 || n==1 || n==2 || n==3){
            return n;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};

