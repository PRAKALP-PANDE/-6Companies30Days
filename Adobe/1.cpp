// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector <int> v;
       int start = 0;
       int current_sum = 0;
       for(int i=0;i<n;i++)
       {
           current_sum+= arr[i];
           while(current_sum >= s && v.size() == 0)
           {
               if(current_sum == s)
               {
                   v.push_back(start+1);
                   v.push_back(i+1);
                   break;
               }
              
               current_sum-=arr[start];
               start++;
           }
       }
       if(v.size()==0)
       {
           v.push_back(-1);
       }
       return v;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends