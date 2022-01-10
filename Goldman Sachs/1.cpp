// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=K;i++){
            int max1=INT_MIN;
            for(int j=1;j<N;j++){
                if(dp[i-1][j-1]-A[j-1]>max1){
                    max1=dp[i-1][j-1]-A[j-1];
                }
                if(max1+A[j]>dp[i][j-1]){
                    dp[i][j]=max1+A[j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends