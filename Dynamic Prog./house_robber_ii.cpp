//Link: https://leetcode.com/problems/house-robber-ii/description/

//tabular
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }

        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];

        for(int i=1;i<=n-1;i++){
            int take=((i-2>=0) ? dp[i-2]:0)+nums[i-1];
            int skip=dp[i-1];

            dp[i]=max(take,skip);
        }

        int r1=dp[n-1];

        dp.clear();

        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;i++){
            int take=((i-2>=0) ? dp[i-2]:0)+nums[i-1];
            int skip=dp[i-1];

            dp[i]=max(take,skip);
        }

        int r2=dp[n];

        return max(r1,r2);
    }
};

//memoization
class Solution {
public:
    int dp[101];

    int solve(int n, int i, vector<int>& nums){
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

        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0],nums[1]);
        }
        
        memset(dp,-1,sizeof(dp));
        int first_house=solve(n,1,nums);

        memset(dp,-1,sizeof(dp));
        int last_house=solve(n-1,0,nums);

        return max(first_house, last_house);
    }
};
