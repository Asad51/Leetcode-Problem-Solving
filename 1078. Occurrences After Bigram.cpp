class Solution
{
public:
    void split(vector<string> &textParts, string text)
    {
        textParts.clear();
        string tmp = "";
        for (int i = 0; i <= text.size(); i++)
        {
            if (i == text.size() || text[i] == ' ')
            {
                textParts.push_back(tmp);
                tmp = "";
            }
            else
                tmp += text[i];
        }
    }

    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> textParts, results;
        split(textParts, text);
        for (int i = 1; i < textParts.size(); i++)
        {
            if (textParts[i - 1] == first && textParts[i] == second)
            {
                if (i + 1 < textParts.size())
                    results.push_back(textParts[i + 1]);
            }
        }
        return results;
    }
};
