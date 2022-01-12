// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        map<pair<int,int>, string> mp;
       int dp[n-1][n-1];
   
   for(int i=0, j=0; j<n-1; ++j)
   {
     int r=i,c=j, len=n-1-j;
      while(len--)
      {
          if(j==0)
          {
            dp[r][c] =0;
           
            string str = "";
            char ch = 'A'+ (n-1-len-1);
            str = str + ch;
            mp[make_pair(r,c)] = str;
             r++; c++;
   
          }
          else if(j==1)
          {
         dp[r][c] = p[r]*p[c]*p[c+1];
         mp[make_pair(r,c)] = '('+ mp[make_pair(r,c-1)] + mp[make_pair(r+1,c)]+ ')';
            r++, c++;
          }
          else
          {
            int right, down;
            dp[r][c] = INT_MAX;
            for(right=r, down=r+1; right<=c && down<=c; right++, down++)
            {
         
              int operations = dp[r][right] + dp[down][c] + p[r]*p[down]*p[c+1];
   
             if(dp[r][c] > operations)
             {
               dp[r][c] = operations;
               mp[make_pair(r,c)] = '('+ mp[make_pair(r,right)]+mp[make_pair(down,c)]+')';
             }
            }
            
            r++, c++;
          }
      }
   } 
   
   
 
   return mp[make_pair(0,n-2)];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends