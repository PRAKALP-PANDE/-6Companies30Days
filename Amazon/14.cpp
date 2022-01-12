// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int maxi = 0;
        Node *t = NULL;
        util1(root,target,maxi,t);
        int m = height (t)-1;
        
        return max(maxi,m);
    }
    pair<int,int>util1(Node *root, int target, int &maxi,Node * &t){
        if(!root) return {0,0};
        
        if (root->data==target){
            t=root;
            return {target,1};
        }
        pair<int,int>l,r;
        l = util1(root->left,target,maxi,t);
        r = util1(root -> right,target,maxi,t);
        
        if(l.first){
            maxi = max(maxi,l.second+r.second);
            return {l.first,l.second+1};
        }
        else if(r.first){
            maxi = max(maxi,r.second+l.second);
            return {r.first,r.second+1};
        }
        
        return {0,max(l.second,r.second)+1};
    }
    
    int height(Node *root){
        if(!root) return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends