class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i<n; i++){
            for (int j=i; j<n; j++){
                int sum = 0;
                for (int k =i; k<=j; k++){
                    sum += nums[k];
                }
                if (sum >=target){
                    ans = min(ans, (j-i+1));
                    break;
                }
            }
        }
        return (ans != INT_MAX) ? ans: 0;
    }
};