// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
         int ans=0;
      int n=str.size();
      bool check=0;


      if(str[0]=='-')
        check=1;
      else{
          ans=ans*10 + (str[0]-'0');
    }
       if(n==1 && check==0)
           return ans;
      else if(n==1 && check==1)
           return -1;
           
      for(int i=1;i<n;i++){
          if(str[i]>='0' && str[i]<='9')
                ans=ans*10 + (str[i]-'0');
          else
               return -1;
      }
      if(check==0)
           return ans;
      return (0-ans);
   }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends