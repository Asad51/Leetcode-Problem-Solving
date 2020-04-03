class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        vector<int> tmp;

        for (int i = 0; i < mat.size(); i++)
        {
            tmp.clear();
            for (int j = i, k = 0; j < mat.size() && k < mat[i].size(); j++, k++)
                tmp.push_back(mat[j][k]);
            sort(tmp.begin(), tmp.end());
            for (int j = i, k = 0, l = 0; j < mat.size() && k < mat[i].size() && l < tmp.size(); j++, k++, l++)
                res[j][k] = tmp[l];
        }

        for (int i = 0; i < mat[0].size(); i++)
        {
            tmp.clear();
            for (int j = 0, k = i; j < mat.size() && k < mat[j].size(); j++, k++)
                tmp.push_back(mat[j][k]);
            sort(tmp.begin(), tmp.end());
            for (int j = 0, k = i, l = 0; j < mat.size() && k < mat[j].size() && l < tmp.size(); j++, k++, l++)
                res[j][k] = tmp[l];
        }

        return res;
    }
};
