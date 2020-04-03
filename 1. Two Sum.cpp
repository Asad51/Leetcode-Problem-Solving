class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if (mp[n] != 0)
            {
                v.push_back(mp[n] - 1);
                v.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]] = i + 1;
            }
        }
        return v;
    }
};
