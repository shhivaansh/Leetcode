//Link: https://leetcode.com/problems/minimum-path-sum/description/

//tabular
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int dp[m+1][n+1];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }

                int up=1e9; //yaha bhi 0 ni max value hogi jisse ki wo consider na ho
                int left=1e9; //yaha bhi 0 ni max value hogi jisse ki wo consider na ho

                if(i>0){
                    up=grid[i][j]+dp[i-1][j];
                }

                if(j>0){
                    left=grid[i][j]+dp[i][j-1];
                }

                dp[i][j]=min(up,left);
            }
        }

        return dp[m-1][n-1];
    }
};

//memoization
class Solution {
public:
    int dp[201][201];

    int solve(int i,int j, int m, int n, vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return grid[i][j];          //return 1; value ko return karenge yaha kyunki hum us value ko add kr rhe hn na ki steps count kr rhe
        }

        if(i<0 || j<0 || i>=m || j>=n){
            return 1e9;              //return 0; out of bound hone pe maximum value return kr do jisse ki use consider na kiya jaye
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=grid[i][j]+solve(i+1,j,m,n,grid);
        int right=grid[i][j]+solve(i,j+1,m,n,grid);

        return dp[i][j]=min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,grid);
    }
};
