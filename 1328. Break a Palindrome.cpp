class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        string res, tmp;
        int n = palindrome.size();
        int isPossible = false;
        if (n <= 1)
            return tmp;
        for (int i = 0; i < n; i++)
        {
            int j = n - i - 1;
            if (!isPossible && i != j)
            {
                char ch = 'a';
                while (ch < palindrome[i] && ch == palindrome[j])
                {
                    ch++;
                }

                if (ch < palindrome[i])
                {
                    res.push_back(char(ch));
                    isPossible = 1;
                }
                else
                    res.push_back(palindrome[i]);
            }
            else
                res.push_back(palindrome[i]);
        }
        if (isPossible)
            return res;
        res.clear();
        if (!isPossible)
        {
            for (int i = 0; i < n; i++)
            {
                int j = n - i - 1;
                if (!isPossible && i != j)
                {
                    char ch = 'a';
                    while (ch <= 'z' && ch == palindrome[i])
                    {
                        ch++;
                    }

                    if (ch <= 'z')
                    {
                        res.push_back(char(ch));
                        isPossible = 1;
                    }
                    else
                        res.push_back(palindrome[j]);
                }
                else
                    res.push_back(palindrome[j]);
            }
        }
        if (!isPossible)
            return tmp;
        reverse(res.begin(), res.end());
        return res;
    }
};
