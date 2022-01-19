// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
         vector<int> g[K];
       
       for(int i = 0; i<N-1; i++){
           int minlen = min(dict[i].size(),dict[i+1].size());
           for(int j = 0; j<minlen; j++){
               if(dict[i][j] != dict[i+1][j]){
                   g[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                   break;
               }
           }
       }
       
       vector<int> indegree(K,0);
       for(int i = 0; i<K; i++){
           for(auto x : g[i]) indegree[x]++;
       }
       
       queue<int> q;
       
       for(int i = 0; i<K; i++){
           if(indegree[i] == 0) q.push(i);
       }
       
       string ans = "";
       while(!q.empty()){
         int node = q.front();
         q.pop();
         ans += (node+'a');
         for(auto x : g[node]){
             indegree[x]--;
             if(indegree[x] == 0) q.push(x);
         }
       }
       
       // cout<<ans;
       
       if(ans.size() == K) return ans;
       
       return "";
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends