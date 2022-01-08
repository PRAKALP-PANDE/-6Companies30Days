// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string &s){
        // code here 
        s = '1' +s + 'I';
        int n = s.size(), nextNum =2, countD= 0;
        for(int i=1; i<n; i++){
            if(s[i] == 'I'){
                reverse(s, i-countD-1, i-1);
                countD =0;
            }
            else countD++;
            s[i] = nextNum +'0';
            nextNum++;
        }
        s.pop_back();
        return s;
    }
    void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i] , s[j]);
            i++;
            j--;
        }
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends