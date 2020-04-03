class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int arr[26], check[26], cnt = 0;
        bool isCompleted;
        for (int i = 0; i < 26; i++)
            arr[i] = 0;
        for (int i = 0; i < chars.size(); i++)
            arr[chars[i] - 'a']++;
        for (int i = 0; i < words.size(); i++)
        {
            for (int i = 0; i < 26; i++)
                check[i] = 0;
            isCompleted = true;
            for (int j = 0; j < words[i].size() && isCompleted; j++)
            {
                if (arr[words[i][j] - 'a'] <= check[words[i][j] - 'a'])
                    isCompleted = false;
                check[words[i][j] - 'a']++;
            }
            if (isCompleted)
                cnt += words[i].size();
        }
        return cnt;
    }
};
