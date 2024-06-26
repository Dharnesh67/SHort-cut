void permutations(vector<vector<int>> &res, vector<int> nums, int l, int h)   // leetcode 46 permutations
{
    if (l == h)
    {
        res.push_back(nums);
        return;
    }
    for (int i = l; i <= h; i++)
    {
        swap(nums[i], nums[l]);
        permutations(res,nums,l+1,h);
        swap(nums[i], nums[l]);
    }
}
