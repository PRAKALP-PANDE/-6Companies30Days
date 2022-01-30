// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long help(string temp)
{
    int n = temp.size();
    long long num=0;
    for(int i=0;i<n;i++)
    {
        num = num*10+temp[i]-'0';
    }
    return num;
}

int missingNumber(const string& str)
{
    // Code here
    int n = str.size();
    for(int l=1;l<=6;l++)
    {
        int i=0;
        string temp = str.substr(i,l);
       
        long long prev = help(temp);
         
        int c=0;
        int flag=0;
        temp="";
        long long num;
        int j=l;
        while(j<str.size())
        {
            temp = temp+str[j];
            
            j++;
            if(prev+1==help(temp))
            {
                
                prev = help(temp);
                
                temp="";
            }
            else if(prev+2==help(temp))
            {
                c++;
                    num = prev+1;
                    
                    prev = help(temp);
                temp="";
            }
            else if(prev<help(temp))
            {
                flag=1;
            }
        }
        if(c==1 and flag==0)
        {
            return num;
        }
    }
    return -1;
}