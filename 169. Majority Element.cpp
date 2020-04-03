class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]] > 0)
                mp[nums[i]]++;
            else
                mp[nums[i]] = 1;
            if (mp[nums[i]] > ceil(n / 2))
                return nums[i];
        }
        return -1;
    }
};
