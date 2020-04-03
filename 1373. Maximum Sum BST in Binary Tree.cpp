/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Result
{
    bool isValid;
    int leftMax;
    int rightMin;
    int sum;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

class Solution
{
    int maxSum;

public:
    Result calculateSum(TreeNode *root)
    {
        Result result = {true, INT_MIN, INT_MAX, 0};
        if (!root)
            return result;

        if (!root->left && !root->right)
        {
            result.leftMax = result.rightMin = result.sum = root->val;
            return result;
        }

        Result leftResult = calculateSum(root->left);
        Result rightResult = calculateSum(root->right);
        if (leftResult.isValid && rightResult.isValid && root->val > leftResult.leftMax && root->val < rightResult.rightMin)
        {
            result.sum = root->val + leftResult.sum + rightResult.sum;
            result.leftMax = max(root->val, leftResult.leftMax);
            result.rightMin = min(root->val, rightResult.rightMin);
            maxSum = max(maxSum, result.sum);
            return result;
        }

        result.sum = max(leftResult.sum, rightResult.sum);
        result.isValid = false;
        maxSum = max(result.sum, maxSum);
        return result;
    }

    int maxSumBST(TreeNode *root)
    {
        maxSum = 0;
        Result r = calculateSum(root);
        return max(r.sum, maxSum);
    }
};
