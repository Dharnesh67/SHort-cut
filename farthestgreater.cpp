// leetcode 962

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        vector<int> maxr(n);
        maxr[n - 1] = n-1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[maxr[i+1]]<nums[i]){
                maxr[i]=i;
            }else{
                maxr[i]=maxr[i+1];
            }
        }
        int i = 0, j = 1;
        while (j < nums.size()) {
            while (i < j - 1 && nums[maxr[j]] < nums[i]) {
                i++;
            }
            if (nums[i]<=nums[maxr[j]]){
                len=max(maxr[j]-i,len);
            }
            j++;
        }
        return len;
    }
};
