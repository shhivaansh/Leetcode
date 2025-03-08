//Link: https://leetcode.com/problems/unique-paths-ii/description/

//tabular
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        int dp[m+1][n+1];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }

                int up=0;
                int left=0;

                if(i>0){
                    up=dp[i-1][j];
                }

                if(j>0){
                    left=dp[i][j-1];
                }

                dp[i][j]=up+left;
            }
        }

        return dp[m-1][n-1];
    }
};

//memoization
class Solution {
public:
    int dp[101][101];

    int solve(int i,int j,int m, int n,vector<vector<int>>& obstacleGrid){
        if(i==m-1 && j==n-1){
            return (obstacleGrid[i][j]==1) ? 0:1;
        }

        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }

        if(obstacleGrid[i][j]==1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left=solve(i,j+1,m,n,obstacleGrid);
        int down=solve(i+1,j,m,n,obstacleGrid);

        return dp[i][j]=left+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,obstacleGrid);
    }
};
