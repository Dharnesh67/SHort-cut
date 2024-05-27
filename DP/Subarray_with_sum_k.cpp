class Solution {  // 560 ,930
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(), 0);
        pre[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            pre[i] = pre[i - 1] + nums[i];
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (pre[i] == k)
                ans++;
            if (mp.find(pre[i] - k) != mp.end())
                ans += mp[pre[i] - k];
            mp[pre[i]]++;
        }
        return ans;
    }
};
/*
The numSubarraysWithSum function takes a vector of integers nums and an integer k as input.

A prefix sum array pre is created and initialized. The prefix sum array at index i contains the sum of all elements in nums from index 0 to i.

The code then initializes ans to 0. This variable will hold the final count of subarrays that sum up to k.

An unordered map mp is created to store the frequency of each prefix sum.

The code then iterates over the prefix sum array. For each prefix sum pre[i]:

If pre[i] is equal to k, it means that the subarray from index 0 to i has a sum of k, so ans is incremented.

If pre[i] - k is found in the map, it means that there is a subarray ending at index i with sum k. The number of such subarrays is added to ans.

The frequency of pre[i] in the map is incremented.

Finally, the function returns ans, which is the total number of subarrays with sum k.*/
