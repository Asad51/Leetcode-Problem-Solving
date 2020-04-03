class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> results;
        int n = A.size();
        int freq[n][26] = {{0}};
        for (int i = 0; i < n; i++)
        {
            int m = A[i].size();
            for (int j = 0; j < m; j++)
                freq[i][A[i][j] - 'a']++;
        }

        for (int j = 0; j < 26; j++)
        {
            int cnt = 9999;
            for (int i = 0; i < n; i++)
                cnt = min(cnt, freq[i][j]);

            for (int k = 0; k < cnt; k++)
                results.push_back(string(1, 'a' + j));
        }
        return results;
    }
};
