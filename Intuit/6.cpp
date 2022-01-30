/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
/*
class Solution {
    public int mountainindex(MountainArray mountainArr)
    {
        int index=-1;
        int low=0,high=mountainArr.length()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mid-1>=0 && mid+1<=mountainArr.length()-1)
            {
                int midvalue=mountainArr.get(mid);
                int prev=mountainArr.get(mid-1);
                int next=mountainArr.get(mid+1);
                if( midvalue>prev && midvalue>next)
            {
                return mid;
            }
            else if( midvalue>prev && mountainArr.get(mid)<next){
                low=mid+1;
            }
            else {
                high=mid;
            }
            }
            else
            {
                return -1;
            }
            
                    
        }
        return index;
    }
    public int binarySearch(MountainArray mountainArr,int target,int low,int high)
    {
        int index=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)<target){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
                    
        }
        return index;
    }
    public int binarySearch1(MountainArray mountainArr,int target,int low,int high)
    {
        int index=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
                    
        }
        return index;
    }
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int index=mountainindex(mountainArr);
        if(index==-1)
        {
            return -1;
        }
        if(mountainArr.get(index)==target)
        {
            return index;
        }
        int low=binarySearch(mountainArr,target,0,index-1);
        int high=binarySearch1(mountainArr,target,index+1,mountainArr.length()-1);
        if(low!=-1)
        {
            return low;
        }
        if(high!=-1)
        {
            return high;
        }
        return -1;
    }
}
*/

#include <bits/stdc++.h>

using namespace std;

int findInMountainArray(int target, vector<int>&m) {
        int l=1;int r=m.size()-1;
int t=-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int idx=m[mid];
      int idxl=m[mid-1];
      int idxr=m[mid+1];
      if(idx>idxl&&idx>idxr)
      {
        t=mid;
        break;
      }
      else if(idxr>idx&&idx>idxl)
        l=mid+1;
      else if(idxr<idx&&idx<idxl)
        r=mid-1;

    }

    l=0;r=t;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        l=mid+1;
      else
        r=mid-1;
    }

    l=t;r=m.size()-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        r=mid-1;
      else
        l=mid+1;
    }
    return -1;

    }

    int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int res = findInMountainArray(target ,a);

    cout << res << endl;

    return 0;
}