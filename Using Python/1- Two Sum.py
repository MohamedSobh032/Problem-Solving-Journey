from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    return [i, j]
        return []

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = 0
        r = len(nums) - 1
        while l < r:
            total = nums[l] + nums[r]
            if total == target:
                return {l, r}
            elif total < target:
                l += 1
            else:
                r -= 1
        return []

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nmap = {}
        for i in range(len(nums)):
            sol = target - nums[i]
            if (sol in nmap):
                return [i, nmap[sol]]
            nmap[nums[i]] = i
        return []


