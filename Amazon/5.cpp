// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int i; string t=""; vector<vector<string>>ans;
        for(i=0;i<s.size();i++){
            t+=s[i];
            vector<string>v;
            set<string>st;
            for(int j=0;j<n;j++){
                int l=contact[j].find(t);
                if(l==0){
                    st.insert(contact[j]);
                }
            }
            if(!st.empty()){
                for(auto it:st){
                    v.push_back(it);
                }
                ans.push_back(v);
            }
            else{
                v.push_back("0");
                ans.push_back(v);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends