class compare
{
  public:
    bool operator()(string& a ,string& b)
    {
        if(a.length() == b.length())
            return (a > b);
        return (a.length() > b.length());
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),compare());
        return nums[k - 1];
    }
};