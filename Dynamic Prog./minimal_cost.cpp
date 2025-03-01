//Link: https://www.geeksforgeeks.org/problems/minimal-cost/0

//tabular
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        int dp[n+1];
        
        if(n==0){
            return 0;
        }
        
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            int minCosts=INT_MAX;
            
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jumps=dp[i-j]+abs(arr[i]-arr[i-j]);
                    minCosts=min(minCosts,jumps);
                }
            }
            
            dp[i]=minCosts;
        }
        
        return dp[n-1];
    }
};

//memoization
class Solution {
  public:
    int dp[10001];
    
    int solve(int k, vector<int> &arr, int n){
        if(n==0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int minCost=INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                int jump=solve(k,arr,n-i)+abs(arr[n]-arr[n-i]);
                minCost=min(minCost,jump);
            }
        }
        
        return dp[n]=minCost;
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(k,arr,n-1);
    }
};
