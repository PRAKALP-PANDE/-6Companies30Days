// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        sort(arr,arr+n);
        int*ans= new int[2];
        long long s1= arr[n-1], s2=n;
        for(int i=0; i<n-1;i++)
        {
            if(arr[i] ==arr[i+1])
            {
                ans[0] = arr[i];
            }
            s1+=arr[i];
            s2+=i+1;
        }
        ans[1]= s2 - (s1-ans[0]);
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends