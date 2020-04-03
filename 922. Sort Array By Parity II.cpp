#define MAX_SIZE 1001

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int arr[MAX_SIZE] = {0};
        vector<int> res;
        for (int i = 0; i < A.size(); i++)
        {
            arr[A[i]]++;
        }
        int o = 0, e = 1;
        for (; o < MAX_SIZE && e < MAX_SIZE;)
        {
            if (arr[o] && arr[e])
            {
                res.push_back(o);
                res.push_back(e);
                arr[o]--;
                arr[e]--;
            }
            else
            {
                if (!arr[o])
                    o += 2;
                else
                    e += 2;
            }
        }

        return res;
    }
};
