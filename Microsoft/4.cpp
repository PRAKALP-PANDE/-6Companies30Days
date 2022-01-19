// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int total = r*c;
       int startingRow=0;
       int endingRow=r-1;
       int startingCol=0;
       int endingCol=c-1;
       
       vector<int> sp;
       int count = 0;
       while(count<total){
           for(int i=startingCol;i<=endingCol && count<total;i++){
               sp.push_back(matrix[startingRow][i]);
               count++;
           }
           startingRow++;
           for(int i = startingRow;i<=endingRow && count<total ;i++){
               sp.push_back(matrix[i][endingCol]);
               count++;
           }
           endingCol--;
           for(int i = endingCol;i>=startingCol && count<total ;i--){
               sp.push_back(matrix[endingRow][i]);
               count++;
           }
           endingRow--;
           for(int i=endingRow;i>=startingRow && count<total ;i--){
               sp.push_back(matrix[i][startingCol]);
               count++;
           }
           startingCol++;
       }
return sp;    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends