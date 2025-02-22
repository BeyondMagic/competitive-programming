#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#

from typing import List

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        inf = float('inf')
        dp = [inf] * (amount + 1)
        dp[0] = 0
        for a in range(1, amount + 1):
            for c in coins:
                if a - c < 0:
                    continue
                dp[a] = min(dp[a], 1 + dp[a - c])
        return dp[amount] if dp[amount] != inf else -1
        
# @lc code=end

test_cases = [
    ([1, 2, 5], 11, 3),
    ([2], 3, -1),
    ([1], 0, 0),
    ([1], 1, 1),
    ([1], 2, 2),
    ([1, 2], 3, 2),
    ([2147483647], 2, -1),
]

for coins, amount, expected in test_cases:
    r = Solution().coinChange(coins, amount)
    print(r, expected)
    assert r == expected
