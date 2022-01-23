// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
       int ans = 0;
       if(n == 1) return 1;

        vector<vector<int>>dp(n, vector<int>(10001));
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int d = nums[j] - nums[i];

                dp[j][d] = max(dp[i][d] + 1, 2);

                ans = max(ans, dp[j][d]);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends