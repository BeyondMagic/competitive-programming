#
# @lc app=leetcode id=1235 lang=python
#
# [1235] Maximum Profit in Job Scheduling
#

# @lc code=start
class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        
        class Job(object):
            def __init__(self, start, end, profit):
                self.start = start
                self.end = end
                self.profit = profit
        
        def binary_search(arr, target):
            low, high, res = 0, len(arr) - 1, -1
            while low <= high:
                mid = (low + high) // 2
                if arr[mid] <= target:
                    res = mid
                    low = mid + 1
                else:
                    high = mid - 1
            return res
        
        # Make jobs and sort...
        jobs = [Job(start, end, profit) for start, end, profit in zip(startTime, endTime, profit)]
        jobs = sorted(jobs, key=lambda job: job.end)
        N = len(jobs)
        
        # Find last non-overlapping job for each i using binary search.
        time_end = [job.end for job in jobs]
        non_overlap = [-1] * N
        for i in range(N):
            start = jobs[i].start
            non_overlap[i] = binary_search(time_end, start)
            
        print(non_overlap)
        
        # Compute DP iteratively.
        dp = [0] * (N + 1)
        for i in range(1, N + 1):
            current = jobs[i - 1].profit
            prev = non_overlap[i - 1]
            take = current + (dp[prev + 1] if prev != -1 else 0)
            dp[i] = max(dp[i-1], take)
            
        print(dp)

        return dp[-1]
        
        
# @lc code=end

test_cases = [
    ([1, 2, 3, 3], [3, 4, 5, 6], [50, 10, 40, 70], 120)
]

for time_start, time_end, profit, expected in test_cases:
    ans = Solution().jobScheduling(time_start, time_end, profit)
    print(ans, expected)
    assert ans == expected
