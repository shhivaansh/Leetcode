//Linke: https://leetcode.com/problems/minimum-falling-path-sum/description/

//tabular
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int dp[m+1][n+1];

        for(int j=0;j<n;j++){
            dp[m-1][j]=matrix[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=matrix[i][j]+dp[i+1][j];
                int diagonal_l=1e9;
                int diagonal_r=1e9;

                if(j<n-1){
                    diagonal_r=matrix[i][j]+dp[i+1][j+1];
                }

                if(j>=1){
                    diagonal_l=matrix[i][j]+dp[i+1][j-1];
                }

                dp[i][j]=min({down, diagonal_r,diagonal_l});
            }
        }

        int mini=1e9;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[0][j]);
        }

        return mini;
    }
};

//memoization
class Solution {
public:
    int dp[101][101];

    int solve(int i,int j, int m, int n, vector<vector<int>>& matrix){
        if(j < 0 || j >= n){
            return 1e9;
        }

        if(i == m-1){             
            return matrix[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=matrix[i][j]+solve(i+1,j,m,n,matrix);        
        int diagonal_r=matrix[i][j]+solve(i+1,j+1,m,n,matrix);
        int diagonal_l=matrix[i][j]+solve(i+1,j-1,m,n,matrix);

        return dp[i][j]=min({down, diagonal_r, diagonal_l});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        
        int mini=1e9;
        for(int j=0;j<n;j++){
            mini=min(mini,solve(0,j,m,n,matrix));
        }

        return mini;
    }
};
