class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> res;
        for (auto a : A)
        {
            res.push_back(a * a);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
