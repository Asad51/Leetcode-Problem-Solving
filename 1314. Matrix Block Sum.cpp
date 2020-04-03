class Solution
{
public:
    bool isValid(int m, int n, int k, int l)
    {
        if (k >= 0 && k < m && l >= 0 && l < n)
            return true;
        return false;
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            tmp.clear();
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = i - K; k <= i + K; k++)
                {
                    for (int l = j - K; l <= j + K; l++)
                    {
                        if (isValid(m, n, k, l))
                            sum += mat[k][l];
                    }
                }
                tmp.push_back(sum);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
