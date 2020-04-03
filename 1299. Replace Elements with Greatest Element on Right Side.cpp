class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int mx = -1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int tmp = max(mx, arr[i]);
            arr[i] = mx;
            mx = tmp;
        }
        return arr;
    }
};
