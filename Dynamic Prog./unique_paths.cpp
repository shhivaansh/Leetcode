//Link: https://leetcode.com/problems/unique-paths/description/

//tabular
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
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

    int solve(int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i<0 || j<0 || i>=m || j>=n){ //escaped the matrix
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=solve(i+1,j,m,n);
        int right=solve(i,j+1,m,n);

        return dp[i][j]=down+right;
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};
