// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n=N.size();
        if(n<=3) return "-1";
        string half = N.substr(0,n/2);
        if( next_permutation( half.begin() , half.end() ) )
        {
            string ans=half;
            if(n&1)
            {
                ans+=N[n/2];
            }
            reverse(half.begin() , half.end());
            ans+=half;
            return ans;
        }
        return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends