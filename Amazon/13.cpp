// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
       if(n==0) return 0;
       int m = grid[0].size();
       int unit_time = 0, count = 0, total = 0;
       queue<pair<int, int>> q;
       int x[4] = {0, 0, 1, -1};
       int y[4] = {1, -1, 0, 0};
       
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(grid[i][j]!=0) total++;
               if(grid[i][j]==2) q.push({i, j});
           }
       }
       
       while(!q.empty()){
           int size_q = q.size();
           count += size_q;
           while(size_q--){
               int i = q.front().first;
               int j = q.front().second;
               q.pop();
               for(int k = 0; k<4; k++){
                   int p = i + x[k];
                   int r = j + y[k];
                   if(p<0 || p>=n || r<0 || r>=m || grid[p][r]!=1) continue;
                   grid[p][r] = 2;
                   q.push({p, r});
               }
           }
           if(!q.empty()) unit_time++;
       }
       return (count == total) ? unit_time : -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends