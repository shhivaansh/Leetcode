//Link: https://www.geeksforgeeks.org/problems/geek-jump/0

//tabular
class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n=arr.size();
        int dp[n];
        
        if(n==0){
            return 0;
        }
        
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            int left=dp[i-1]+abs(arr[i]-arr[i-1]);
            int right=INT_MAX;
            if(i>1) right=dp[i-2]+abs(arr[i]-arr[i-2]);
            
            dp[i]=min(left,right);
        }
        
        return dp[n-1];
    }
};

//memoization
class Solution {
  public:
    int dp[100001];
    
    int solve(int n,vector<int>& arr){
        if(n==0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int left=solve(n-1,arr)+abs(arr[n]-arr[n-1]);
        int right=INT_MAX;
        if(n>1) right=solve(n-2,arr)+abs(arr[n]-arr[n-2]);
        
        return dp[n]=min(left,right);
    }
    
    int minCost(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,arr);
    }
};
