class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < text.size(); i++)
            freq[text[i] - 'a']++;
        int res = min(freq[0], min(freq[1], min(freq[11] / 2, min(freq[13], freq[14] / 2))));
        return res;
    }
};
