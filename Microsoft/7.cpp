// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int x=grid.size();
       int y=grid[0].size();
       
       bool visited[x][y];
       
       for(int i=0;i<x;i++){
           for(int j=0;j<y;j++){
               visited[i][j]=false;
           }
       }
       
       int count=-1;
       int counter=0;
       queue<pair<int,int>>q;
       for(int i=0;i<x;i++){
           for(int j=0;j<y;j++){
               
               if(visited[i][j]==false && grid[i][j]==1){
                   visited[i][j]=true;
                   counter=1;
                   q.push(make_pair(i,j));
                   
                   while(!q.empty()){
                       int a=q.front().first;
                       int b=q.front().second;
                       q.pop();
                       
                       if(a>=0 && a<x && b+1>=0 && b+1<y && visited[a][b+1]==false && grid[a][b+1]==1){
                           visited[a][b+1]=true;
                           counter++;
                           q.push(make_pair(a,b+1));
                       }
                       if(a>=0 && a<x && b-1>=0 && b-1<y && visited[a][b-1]==false && grid[a][b-1]==1){
                           visited[a][b-1]=true;
                           counter++;
                           q.push(make_pair(a,b-1));
                       }
                       if(a-1>=0 && a-1<x && b>=0 && b<y && visited[a-1][b]==false && grid[a-1][b]==1){
                           visited[a-1][b]=true;
                           counter++;
                           q.push(make_pair(a-1,b));
                       }
                        if(a+1>=0 && a+1<x && b>=0 && b<y && visited[a+1][b]==false && grid[a+1][b]==1){
                           visited[a+1][b]=true;
                           counter++;
                           q.push(make_pair(a+1,b));
                       }
                       if(a-1>=0 && a-1<x && b+1>=0 && b+1<y && visited[a-1][b+1]==false && grid[a-1][b+1]==1){
                           visited[a-1][b+1]=true;
                           counter++;
                           q.push(make_pair(a-1,b+1));
                       }
                       
                       if(a-1>=0 && a-1<x && b-1>=0 && b-1<y && visited[a-1][b-1]==false && grid[a-1][b-1]==1){
                           visited[a-1][b-1]=true;
                           counter++;
                           q.push(make_pair(a-1,b-1));
                       }
                       if(a+1>=0 && a+1<x && b+1>=0 && b+1<y && visited[a+1][b+1]==false && grid[a+1][b+1]==1){
                           visited[a+1][b+1]=true;
                           counter++;
                           q.push(make_pair(a+1,b+1));
                       }
                       if(a+1>=0 && a+1<x && b-1>=0 && b-1<y && visited[a+1][b-1]==false && grid[a+1][b-1]==1){
                           visited[a+1][b-1]=true;
                           counter++;
                           q.push(make_pair(a+1,b-1));
                       }
                   }
                   
                   if(counter>count)
                   count=counter;
                   
               }
           }
       }
       
       return count;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends