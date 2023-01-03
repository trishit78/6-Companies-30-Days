//LeetCode Submission Link - https://leetcode.com/problems/largest-divisible-subset/submissions/
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), mx = 1;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j; 
                }
            }
            if (dp[i] > mx)
            {
                mx = dp[i];
                last = i;
            }
        }
       
        vector<int> temp;
        temp.push_back(nums[last]);
        while (hash[last] != last)
        {
            last = hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};