//Link: https://www.geeksforgeeks.org/problems/chocolates-pickup/1

//tabular
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        int dp[n][m][m];
        
        for(int j=0;j<m;j++){
            for(int j1=0;j1<m;j1++){
                if(j==j1){
                    dp[n-1][j][j1]=grid[n-1][j];
                }else{
                    dp[n-1][j][j1]=grid[n-1][j]+grid[n-1][j1];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int j1=0;j1<m;j1++){
                    int maxi=-1e9;
                    
                    for(int di=-1;di<=1;di++){
                        for(int dj=-1;dj<=1;dj++){
                            if(j+di<0 || j1+dj<0 || j+di>=m || j1+dj>=m){
                                continue;
                            }
                            
                            int ans;
                            if(j==j1){
                                ans=grid[i][j];
                            }else{
                                ans=grid[i][j]+grid[i][j1];
                            }
                            
                            
                            ans+=dp[i+1][j+di][j1+dj];
                            
                            
                            maxi=max(maxi,ans);
                        }
                    }
                    
                    dp[i][j][j1]=maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};

//memoization
class Solution {
  public:
    int dp[101][101][101];
    
    int help(int i, int j, int j1, int n, int m, vector<vector<int>> &grid){
        if(j<0 || j1<0 || j>=m || j1>=m){
            return -1e9;
        }
        
        if(i==n-1){
            if(j==j1){
                return grid[i][j];
            }else{
                return grid[i][j]+grid[i][j1];
            }
        }
        
        if(dp[i][j][j1]!=-1){
            return dp[i][j][j1];
        }
        
        int maxi=INT_MIN;
        int ans;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(j1==j){
                    ans=grid[i][j]+help(i+1,j+di,j1+dj,n,m,grid);
                }else{
                    ans=grid[i][j]+grid[i][j1]+help(i+1,j+di,j1+dj,n,m,grid);
                }
                
                maxi=max(ans,maxi);
            }
        }
        
        return dp[i][j][j1]=maxi;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        return help(0,0,m-1,n,m,grid);
    }
};
