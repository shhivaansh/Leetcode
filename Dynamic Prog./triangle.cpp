//https://leetcode.com/problems/triangle/description/

//tabular
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();

        int dp[m+1][m+1];

        dp[0][0]=triangle[0][0];

        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                
                int up=1e9;
                int diag=1e9;

                if(i>j){
                    int up=dp[i-1][j];
                }

                if(j>0){
                    int diag=dp[i-1][j-1];
                }

                dp[i][j]=triangle[i][j]+min(up,diag);
            }
        }

        return dp[m-1][m-1];
    }
};

//memoization
class Solution {
public:
    int dp[201][201];

    int solve(int i,int j,int m, vector<vector<int>>& triangle){
        if(i==m-1){
            return triangle[i][j];
        }

        if(i<0 || j<0 || i>=m || j>=m){
            return 1e9;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=triangle[i][j]+solve(i+1,j,m,triangle);
        int diag=triangle[i][j]+solve(i+1,j+1,m,triangle);

        return dp[i][j]=min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,triangle);
    }
};
