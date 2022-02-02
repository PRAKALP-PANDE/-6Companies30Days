class Solution {
public:
    int dp[201][201];
    int solve(int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for(int ind=i;ind<=j;ind++)
            mn=min(mn,ind+max(solve(i,ind-1),solve(ind+1,j)));
        return dp[i][j]=mn;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};