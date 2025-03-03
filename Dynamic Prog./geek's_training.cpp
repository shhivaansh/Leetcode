//Link: https://www.geeksforgeeks.org/problems/geeks-training/0

//tabular
class Solution {
  public:
    
    int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>> &dp){
        
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        
        if(day==0){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last){
                    maxi=max(maxi,points[0][i]);
                }
            }
            return dp[day][last]=maxi;
        }
        
        int maxi = 0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                int activity=solve(day-1,i,points,dp)+points[day][i];
                maxi=max(maxi,activity);
            }
        }
        
        return dp[day][last]=maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        
        return solve(n-1,3,points,dp);
    }
};
