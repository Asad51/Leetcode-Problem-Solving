bool cmp(vector<int> v1, vector<int> v2)
{
    if (v1[1] == v2[1])
        return v1[0] > v2[0];
    return v1[1] > v2[1];
}

class Solution
{
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<vector<int>> tmp;
        vector<int> res;
        for (int i = 0; i < restaurants.size(); i++)
        {
            if (veganFriendly && !restaurants[i][2])
                continue;
            if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
                tmp.push_back(restaurants[i]);
        }

        printf("%d\n", tmp.size());
        sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < tmp.size(); i++)
            res.push_back(tmp[i][0]);
        return res;
    }
};
