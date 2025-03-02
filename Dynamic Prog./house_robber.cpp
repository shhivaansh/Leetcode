//Link: https://leetcode.com/problems/house-robber/description/

//tabular
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];

        if(n==1){
            return nums[0];
        }

        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int take=dp[i-2]/*ek ghar phle tk ka dp*/+nums[i-1]/*doosrwa ghar*/;
            int skip=dp[i-1];

            dp[i]=max(take,skip);
        }

        return dp[n];
    }
};

//memoization
class Solution {
public:
    int dp[101];

    int solve(int &n,int i,vector<int>& nums){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int take=solve(n,i+2,nums)+nums[i];
        int skip=solve(n,i+1,nums);

        return dp[i]=max(take,skip);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(n,0,nums);
    }
};
